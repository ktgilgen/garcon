#include"AppManager.h"
#include<fstream>
#include<utility>


AppManager* AppManager::instance = 0;

//constructor
AppManager::AppManager() {
    string home = getenv("HOME") ; //get the home directory
    GARCON_RC = home + "/.garconrc";

    ifstream fileIn;

    fileIn.open(GARCON_RC.c_str());
    GARCON_RC_VERIFIED = true;
  
    if(!fileIn.good()) { //if file not there, create it and return
        ofstream outFile;
        outFile.open(GARCON_RC.c_str());
          if(!outFile.good()) //if file could not be created -- apps cannot be saved
             GARCON_RC_VERIFIED = false;
        outFile.close(); 
        return;
    } 

    //initializes app list with files stored in .garconrc
    initAppList(fileIn);
    fileIn.close();

}

//destructor
AppManager::~AppManager() {
    saveApps();
}

void AppManager::quit() {
    instance->~AppManager();
}

//get instance
AppManager* AppManager::getInstance() {
    if(!instance) {
        instance = new AppManager();
        return instance;
    }
    return instance;
}

//read an app from .garconrc 
bool AppManager::getApp(ifstream &fileIn, AppInfo &app) {
    char buffer;
    pair<string, string> attribute;
    string value = "";

    fileIn >> buffer;
    while(buffer != '>' && buffer != '=') {
        if(buffer == ':') {
            attribute.first = value;
            value.clear();
        }
        else if(buffer == '&') {
            attribute.second = value;
            value.clear();

            //not going to add an initial app
            setAttribute(attribute, app);
        }
        else if(buffer != '\n') {
            value += buffer;
        }
      fileIn >> buffer;
    }
    if(buffer == '>') { //there are more apps to read
        return true;
    }
    return false; //all of the apps are read in
}

//set an attribute to an AppInfo object
void AppManager::setAttribute(pair<string, string> &attribute, AppInfo &app) {
        if(attribute.first ==  "NAME") 
            app.setName(attribute.second);
        else if(attribute.first ==  "AUTHOR")
            app.setAuthor(attribute.second);
        else if(attribute.first == "YEARBUILT")
            app.setYearBuilt(attribute.second);
        else if( attribute.first == "DESCRIPTION")
            app.setDescription(attribute.second);
        else if( attribute.first == "PATHTOIMAGE")
            app.setPathToImage(attribute.second);
        else if( attribute.first ==  "PATHTOBASH") 
            app.setPathToBash(attribute.second);
}


//if there were no errors in initializing, return true, otherwise return false; currently only check if GARCON_RC_VERIFIED was read/created or not
bool AppManager::good() {
   if(GARCON_RC_VERIFIED)
     return true;
   return false;
}

//Opens .garconrc and uploads the current apps stored
void AppManager::initAppList(ifstream& fileIn){
    ifstream fileLocation;
    char buffer;
    string inputLine = "";
    AppInfo app;

    fileIn >> noskipws;
    fileIn >> buffer;

// Get file path info from .garconrc file to apps
   while( buffer != '=' ){
           if(buffer == '&'){
               fileLocation.clear();
               fileLocation.open(inputLine); //Open the file at file stored path

               if( fileLocation.good()){
                    getApp(fileLocation, app);   //Get the app info from file
                    app.setPathToGarcon( string(inputLine) );
                    if(!app.getName().empty())
                        apps[app.getName()] = app; // Add info to manager
                    app.clear();
               }


               fileLocation.close();
               inputLine.clear();
               fileIn >> buffer; //get endline char
           }
           else
               inputLine += buffer;
       fileIn >> buffer;
   } //end while loop
}

//gets the list of app names
void AppManager::getAppList(vector<string> &appList) {
   for(auto key : apps) {
       appList.push_back(key.first);  
   }
}

//assuming that the app exists in the system TODO: get rid of this assumption
bool AppManager::runApp(string appName) {
    //start new stuff
        std::string gnome = "gnome-terminal -x sh -c ";
        std::string programPath = apps[appName].getPathToBash();
        std::string quote = "\"";
        std::string runCmd = gnome + quote + programPath + quote;
       if( system( runCmd.c_str()) ) //if app could not run
          return false;
       return true;
}

//assuming that the app exists in the system TODO: get rid of this assumption
AppInfo AppManager::getAppInfo(string appName) {
   return apps[appName];
}

//adds an app 
void AppManager::addApp(AppInfo app) {
    if(!app.getName().empty())
      apps[app.getName()] = app;
}

//assuming that the app exists in the system TODO: get rid of this assumption
void AppManager::removeApp(string appName){
    apps.erase(appName);
}


void AppManager::saveApps() {

    if(GARCON_RC_VERIFIED) {
        ofstream outFile;
        outFile.open(GARCON_RC.c_str());
  
        for(auto key : apps) {
           /* outFile << "NAME:" << key.second.getName() << "&" << endl;
            outFile << "AUTHOR:" << key.second.getAuthor() << "&" << endl;
            outFile << "YEARBUILT:" << key.second.getYearBuilt() << "&" << endl;
            outFile << "DESCRIPTION:" << key.second.getDescription() << "&" << endl;
            outFile << "PATHTOIMAGE:" << key.second.getPathToImage() << "&" << endl;
            outFile << "PATHTOBASH:" <<key.second.getPathToBash() << "&" << endl;
            outFile << ">" << endl;*/
            outFile << key.second.getPathToGarcon() <<"&" << endl;
        }
      outFile << "=";
    }//end if
}


















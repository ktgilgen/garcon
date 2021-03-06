#include"AppManager.h"
#include "controls.h"
#include<fstream>
#include<utility>


AppManager* AppManager::instance = 0;

//constructor
AppManager::AppManager(QWidget * parent) :QDialog(parent){
    string home = getenv("HOME") ; //get the home directory
    GARCON_RC = home + "/.garconrc";
    bool isOn = false;
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

    else //file is there
	{
    	//initializes app list with files stored in .garconrc
    	initAppList(fileIn);
    	fileIn.close();
	}

    //check if VRPN is on
    isOn = checkVRPN();
    if(!isOn)
    {
        startVRPN(); //if not, start it
    }

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
        else if( attribute.first ==  "workingDirectory")
            app.setPathToWorkingDirectory(attribute.second);
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
//may want to make sure sh file exists and working directory is not null
bool AppManager::runApp(string appName) {

        //Disable the other main window buttons while program is running
        //button disable and enable handled by mainwindow on_run_clicked() - henry
    //check to make sure working directory is not an empty string
    if(apps[appName].getPathToWorkingDirectory().empty()){
        //wont be able to run app without working directory
        return false;
    }
    std::string programPath = "cd " + apps[appName].getPathToWorkingDirectory() + "; ./run.sh" ;

    if( system( programPath.c_str() ) ){
        //app couldn't run
        return false;
    }
    //return no error condition
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
            outFile << key.second.getPathToGarcon() <<"&" << endl;
        }
      outFile << "=";
    }
}

bool AppManager::checkVRPN(){

    //Check to see if file exists
    ifstream test;
    test.clear();
    test.open("/var/lock/wiimote");

    //true if on, false if off
    if( test.good()){
        test.close();
        return true;
    }
    else{
        test.close();
        return false;
    }
}
//TODO: add return statements on system or change to void
bool AppManager::restartVRPN(){
    //Navigate to VRPN location
    std::string gnome = "gnome-terminal -x sh -c ";
    std::string executable = "/home/local/share/wiimote/wiimote";
    std::string quote = "\"";
    std::string arg = "restart";
    std::string command = gnome + quote + executable + " " + arg + quote;
    system(command.c_str());
}

bool AppManager::startVRPN(){
    //Navigate to VRPN location
    std::string gnome = "gnome-terminal -x sh -c ";
    std::string executable = "/home/local/share/wiimote/wiimote";
    std::string quote = "\"";
    std::string arg = "start";
    std::string command = gnome + quote + executable + " " + arg + quote;
    system(command.c_str());
}

bool AppManager::showImage(string appName){
    ifstream testInput;
    testInput.clear();

    //make sure image path is not empty
    if( !(apps[appName].getPathToImage().empty()) ){

        //Check if the path is good
        testInput.open( apps[appName].getPathToImage() );
        if(testInput.good())
        {
            Controls *image = new Controls();
            connect( image, SIGNAL(destroyed()), this, SLOT(update()) );
            image->show();
            image->display(apps[appName].getPathToImage());
            testInput.close();
            return true;
        }
        else
        {
                testInput.close();
                return false;
        }

    }
    //image path empty
    else
        return false;

}



















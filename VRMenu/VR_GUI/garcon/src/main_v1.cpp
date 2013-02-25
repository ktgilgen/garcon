#include<iostream>
#include<vector>
#include<stdlib.h>

#include"AppManager.h"
#include"AppInfo.h"

using namespace std;

AppManager *manager;

void mainMenu();
void runApp(string appName);
void addApp();
void removeApp();
void editApp();


int main() {
  manager = AppManager::getInstance();

  if(manager->good() ) {
     mainMenu(); 
  }
  else {
     cout << "...[WARNING] .GARCONRC COULD NOT BE CREATED..." << endl << endl;
     mainMenu();
  }

    return 0;
}

//displays the main menu and returns the selected option
void mainMenu() {
   int choice;
   bool quit = false;
   vector<string> appList;
   manager->getAppList(appList);
   
   while(!quit) { 
      cout << "CURRENT APPS IN SYSTEM: " << endl;
      for( int i = 0; i < appList.size(); i ++) {
           cout << "     <" << i + 1 << "> " << appList[i] << endl;
      }
      cout << endl;
      cout << "     <-1> Add App" << endl;
      cout << "     <-2> Remove App" << endl;
      cout << "     <-3> Edit App" << endl;
      cout << "<0> QUIT" << endl;
      cin >> choice;

      switch(choice) {
        case 0:
              quit = true;
              manager->quit();
            break;
        case -1: //add a new app
                addApp();
                appList.clear();
                manager->getAppList(appList);
            break;
        case -2: //remove an app
               removeApp();  
                appList.clear();
                manager->getAppList(appList);                
            break;
        case -3: //edit an app
               editApp();  
                appList.clear();
                manager->getAppList(appList);
            break;
        default:
           if(choice  > 0 && choice <= appList.size()) {  //if an app is selected, run it
               runApp(appList[((int)choice) - 1]);  
           }            
           else {
              cout << endl << "=======================" << endl;
              cout << "[ERROR] - INVALID INPUT" << endl;
              cout << "=======================" << endl << endl;
           } 
        break; 
      }
   }
}


void runApp(string appName) {

  if( !manager->runApp(appName) ) 
     cout << "--------> [ERROR] BASH COULD NOT EXECUTE!!" << endl;
}

void addApp() {
   AppInfo newApp;
   string buffer;
  
   cout << "APP NAME : ";
   cin >> buffer;
     newApp.setName(buffer);
   cout << "APP AUTHOR: ";
   cin >> buffer;
     newApp.setAuthor(buffer);
   cout << "YEAR BUILT: ";
   cin >> buffer;
     newApp.setYearBuilt(buffer);
   cout << "APP DESCRIPTION: ";
   cin >> buffer;
     newApp.setDescription(buffer);
   cout << "PATH TO APP IMAGE(from the home directory or enter NO_IMAGE): ";
   cin >> buffer;
     newApp.setPathToImage(buffer);
   cout << "PATH TO APP BASH(include '~' in front of it): ";
   cin >> buffer;
     newApp.setPathToBash(buffer);
  
   manager->addApp(newApp);
   cout << "   DONE!!!!!" << endl; 
}

void removeApp() {
  string buffer;

  cout << "APP NAME TO REMOVE: ";
  cin >> buffer;
  manager->removeApp(buffer);

}

void editApp() {
  string appName;
  string newData;
  int choice;
  cout << "WHICH APP : ";
  cin >> appName;

  cout << "WHICH ONE : " << endl;
  cout << "  <1>NAME" << endl;
  cout << "  <2>AUTHOR" << endl; 
  cout << "  <3>YEAR BUILT" << endl; 
  cout << "  <4>DESCRIPTION" << endl; 
  cout << "  <5>PATH TO IMAGE" << endl; 
  cout << "  <6>PATH TO BASH "; 
  cin >> choice;


  cout << endl << "ENTER NEW INFO: ";
   cin >> newData;

  AppInfo buffer = manager->getAppInfo(appName);
  manager->removeApp(appName);

  switch(choice) {
    case 1:
          buffer.setName(newData);
      break;
    case 2:
          buffer.setAuthor(newData);
      break;
    case 3:
          buffer.setYearBuilt(newData);
      break;
    case 4:
          buffer.setDescription(newData);
      break;
    case 5:
          buffer.setPathToImage(newData);
      break;
    case 6:
          buffer.setPathToBash(newData);
      break;
    default:
           cout << "invalid choice" << endl;
      break;
  }

  manager->addApp(buffer);
}


























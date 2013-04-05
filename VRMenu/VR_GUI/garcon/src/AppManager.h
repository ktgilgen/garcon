#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include"AppInfo.h"
#include<iostream>
#include<unordered_map>
#include<string>
#include <QtCore>
#include<vector>

using namespace std;

class AppManager { /*IMPLEMENTED AS SINGLETON*/

    public:
     static AppManager* getInstance();
     bool good(); //returns true if there were no errors in initializing AppManager
     void getAppList(vector<string> &); //get a list of the app names
     bool runApp(string appName); //run app
     void initAppList(ifstream&); //Opens .garconrc and gets files

     void addApp(AppInfo app);
     bool getApp(ifstream &, AppInfo &); //used in parsing .garcon files
     void removeApp(string appName);
     AppInfo getAppInfo(string appName);
     void setString ( QString name);
     void quit(); 

     bool checkVRPN(); //true if on, false if off
     bool restartVRPN();
     bool startVRPN();


   private:
      AppManager();//constructor
     ~AppManager();//destructor
      void setAttribute(pair<string, string> &, AppInfo&); //set an attribute to an AppInfo
      void saveApps();

     static AppManager *instance;
     unordered_map<string, AppInfo> apps;
     string GARCON_RC; //should be in the home directory
     bool GARCON_RC_VERIFIED;
};
#endif

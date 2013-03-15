#ifndef APP_INFO_H
#define APP_INFO_H

#include<string>

using namespace std;

class AppInfo {
    public:
      AppInfo();
      AppInfo(string imagePath, string bashPath, string name, string YearBuilt, 
                                              string shortDescription, string author);
      ~AppInfo();

      void clear();

      void setPathToImage(string);
      void setPathToBash(string);
      void setPathToGarcon(string);
      void setName(string);
      void setYearBuilt(string);
      void setDescription(string);
      void setAuthor(string);

      string getPathToImage();
      string getPathToGarcon();
      string getPathToBash();
      string getName();
      string getYearBuilt();
      string getDescription(); 
      string getAuthor();     


   private:
     string name;
     string author; 
     string yearBuilt;
     string description;
     string pathToImage;
     string pathToBash; 
     string pathToGarcon;

};

#endif

/*
  AppInfo constants
   NO_IMAGE
   NO_BASH
*/

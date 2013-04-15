#include"AppInfo.h"

AppInfo::AppInfo() {
}

AppInfo::~AppInfo() {
 
}

void AppInfo::clear() {
   pathToImage.clear();
   name.clear();
   author.clear();
   workingDirectory.clear();
   pathToImage.clear();
   description.clear();
}

AppInfo::AppInfo(string imagePath, string bashPath, string name, string YearBuilt, 
                                                 string shortDescription, string author) {
  
     setPathToImage(imagePath);
     setPathToWorkingDirectory(bashPath);
     setName(name);
     setYearBuilt(YearBuilt);
     setDescription(shortDescription);
     setAuthor(author);
}

void AppInfo::setPathToImage(string path) {
    this->pathToImage = path;   
}

void AppInfo::setPathToWorkingDirectory(string path) {
    this->workingDirectory = path;
}
void AppInfo::setPathToGarcon(string path){
    this->pathToGarcon = path;
}

void AppInfo::setName(string Name) {
    this->name = Name;
}

void AppInfo::setYearBuilt(string YearBuilt) {
    this->yearBuilt = YearBuilt;
}

void AppInfo::setDescription(string Description) {
    this->description = Description;
}

void AppInfo::setAuthor(string Author) {
    this->author = Author;
}

string AppInfo::getPathToImage() {
    return pathToImage;
}
string AppInfo::getPathToGarcon() {
    return pathToGarcon;
}

string AppInfo::getPathToWorkingDirectory() {
    return workingDirectory;
}

string AppInfo::getName() {
    return name;
}

string AppInfo::getYearBuilt() {
    return yearBuilt;
}

string AppInfo::getDescription() {
    return description;
}

string AppInfo::getAuthor() {
    return author;
}

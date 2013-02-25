#include"AppInfo.h"

AppInfo::AppInfo() {

}

AppInfo::~AppInfo() {
 
}

void AppInfo::clear() {
   pathToImage.clear();
   name.clear();
   author.clear();
   pathToBash.clear();
   pathToImage.clear();
   description.clear();
}

AppInfo::AppInfo(string imagePath, string bashPath, string name, string YearBuilt, 
                                                 string shortDescription, string author) {
  
     setPathToImage(imagePath);
     setPathToBash(bashPath);
     setName(name);
     setYearBuilt(YearBuilt);
     setDescription(shortDescription);
     setAuthor(author);
}

void AppInfo::setPathToImage(string path) {
    this->pathToImage = path;   
}

void AppInfo::setPathToBash(string path) {
    this->pathToBash = path;
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

string AppInfo::getPathToBash() {
    return pathToBash;
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

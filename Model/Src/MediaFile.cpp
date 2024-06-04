#include "MediaFile.hpp"
using namespace std;


MediaFile::MediaFile(const string& name,const string& path,const int&type):name(name), path(path),type(type){}

string MediaFile::getName(){
    return name;
}
string MediaFile::getPath(){
    return path;
}
int MediaFile::getType(){
    return type;
}
void MediaFile::setName(string name)
{
    this->name = name;
}

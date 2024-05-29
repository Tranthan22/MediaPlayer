#include "MediaFile.hpp"
using namespace std;


MediaFile::MediaFile(const string& n, const string &p) : name(n), path(p)
{ 
}

string MediaFile::getName(){
    return name;
}
string MediaFile::getPath(){
    return path;
}
int MediaFile::getType(){
    return type;
}

#ifndef _MEDIAFILE_H_
#define _MEDIAFILE_H_

#include <iostream>
using namespace std;

class MediaFile{
private:
    string name;
    string path;
    int type;
public:
    MediaFile(const string& name,const string& path,const int& type);
    ~MediaFile()=default;
    string getName();
    string getPath();
    int getType();

};

#endif /*_MEDIAFILE_H_ */
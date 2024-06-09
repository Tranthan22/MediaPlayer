#ifndef _MEDIAPATHVIEW_HPP_
#define _MEDIAPATHVIEW_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class MediaPathView
{
private:
    string directoryPath;
    
public:
    MediaPathView()=default;
    ~MediaPathView()=default;

    string input_path();
    void display_MediaPath(vector<string>& devices);
    void display_MediaPath();
    int PathSelection();
};

#endif /*MEDIAPATHVIEW_HPP*/


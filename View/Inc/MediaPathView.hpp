#ifndef _MEDIAPATHVIEW_HPP_
#define _MEDIAPATHVIEW_HPP_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class MediaPathView
{
private:
    string directoryPath;
    
public:
    MediaPathView()=default;
    ~MediaPathView()=default;

    string input_path();
    void display_MediaPath();
};

#endif /*MEDIAPATHVIEW_HPP*/


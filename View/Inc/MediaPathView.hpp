#ifndef _MEDIAPATHVIEW_HPP_
#define _MEDIAPATHVIEW_HPP_

#include <iostream>
#include <iomanip>

class MediaPathView
{
private:
    std::string directoryPath;
    
public:
    MediaPathView()=default;
    ~MediaPathView()=default;

    std::string input_path();
    void display_MediaPath();
};

#endif /*MEDIAPATHVIEW_HPP*/


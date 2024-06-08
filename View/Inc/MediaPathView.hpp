#ifndef _MEDIAPATHVIEW_HPP_
#define _MEDIAPATHVIEW_HPP_

#include "main.hpp"


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


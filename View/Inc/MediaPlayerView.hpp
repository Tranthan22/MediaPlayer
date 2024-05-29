#ifndef MEDIAPLAYERVIEW_HPP
#define MEDIAPLAYERVIEW_HPP

#include <iomanip> // Để sử dụng setw()
#include <iostream>
#include <fstream>
#include <cstdlib> // For std::system
#include "ViewInteract.hpp"

using namespace std;

class MediaPlayerView
{
private:
    string directoryPath;
public:
    MediaPlayerView()= default;
    ~MediaPlayerView()=default;
    void display_MediaPlayer();
    void checkFilesInDirectory(ViewInteract &ViewInteract,string& directoryPath);
    void input_path(ViewInteract &ViewInteract);
};

#endif
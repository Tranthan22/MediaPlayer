#ifndef MEDIAPLAYERVIEW_HPP
#define MEDIAPLAYERVIEW_HPP

#include <iomanip> // Để sử dụng setw()
#include <iostream>
#include <fstream>
#include <cstdlib> // For std::system
// #include "ViewInteract.hpp"

using namespace std;

class MediaPlayerView
{
private:
    // string directoryPath;
public:
    MediaPlayerView()= default;
    ~MediaPlayerView()=default;
    void display_MediaPlayer();
    bool checkFilesInDirectory(const string& directoryPath) const;
    std::string input_path();
};

#endif

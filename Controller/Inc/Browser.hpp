#include <string>
#include <filesystem>
#include <vector>

#include "MediaPlayerView.hpp"
#include "MediaFileView.hpp"
#include "MenuView.hpp"
#include "AudioFile.hpp"
#include "Playlist.hpp"



// C++17 up
namespace fs = std:: filesystem;

class Browser
{
private:
    std::string Path;
    vector<MediaFile*> vMediaFile; // using mediafile to free easily
    // vector<AudioFile*> vAudioFile;
    vector<Playlist*> vPlayList;

    MediaPlayerView mediaPlayerView; 
    MenuView menuView;
    // MediaFileView mediaFileView;

public:
    MediaFileView mediaFileView;
    Browser(/* args */);
    ~Browser();
    /* View */
    void setPath();
    void loadFile();

    void menu();
    void medialist();
    

    /* Model */

};


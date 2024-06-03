#include <string>
#include <filesystem>
#include <vector>
#include <stack>

#include "MediaPlayerView.hpp"
#include "MediaFileView.hpp"
#include "MenuView.hpp"
#include "MediaPathView.hpp"
#include "AudioFile.hpp"
#include "Playlist.hpp"
#include "MediaPlayer.hpp"

enum FlowID
{
    MENU_ID = 0,
    MEDIA_LIST_ID = 1,
    PLAY_LIST_ID = 2,
    PLAY_MUSIC_ID = 3
};

// C++17 up
namespace fs = std:: filesystem;

class Browser
{
private:
    std::string Path;

    /* Stack */
    std::stack<int> flowID;

    /* Vector data */
    vector<MediaFile*> vMediaFile; // using mediafile to free easily
    vector<Playlist*> vPlayList;

    /* View declaration */
    MediaPathView mediaPathView;
    MediaPlayerView mediaPlayerView; 
    MenuView menuView;
    MediaFileView mediaFileView;

    /* Player */
    MediaPlayer myPlayer;

public:
    Browser(/* args */);
    ~Browser();

    void setPath();
    void loadFile();

    int userInput();

    void menu();
    void medialist();
    void playmusic();
    void programFlow();
};


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
#include "PlaylistView.hpp"
#include "MediaPlayerView.hpp"

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
    vector<Playlist*> vPlayList;    //vector contains playlist (include vMediaFile)
    // vector<MediaFile*> vMediaFile; // Vector contains files (all file)

    /* View declaration */
    MediaPathView mediaPathView;
    PlayMusicView mediaPlayerView; 
    MenuView menuView;
    MediaFileView mediaFileView;

    /* Player */
    MediaPlayer myPlayer;
    PlaylistView playlistView;



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

    /* Model */

    vector<MediaFile *> getMediaFiles(); /* Ngoc add */

};


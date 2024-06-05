#include <string>
#include <filesystem>
#include <vector>
#include <stack>
#include <stack>

#include "MediaPlayerView.hpp"
#include "MediaFileView.hpp"
#include "MenuView.hpp"
#include "MediaPathView.hpp"
#include "AudioFile.hpp"
#include "Playlist.hpp"
#include "MediaPlayer.hpp"
#include "MetadataView.hpp"
#include "Metadata.hpp"
#include "PlaylistView.hpp"
#include "MediaPlayerView.hpp"


#define START_PAGE 1

enum FlowID
{   
    MENU_ID = 0,
    MEDIA_LIST_ID = 1,
    PLAY_LIST_ID = 2,
    PLAY_MUSIC_ID = 3,
    PLAY_LIST_MUSIC_ID = 4,
    PLAY_MUSIC_PLAYER_ID = 5,
};


// C++17 up
namespace fs = std:: filesystem;

class Browser
{
private:
    std::string Path;
    size_t current_screen;
    size_t chosenList = 1;
    size_t chosenMusic = 1;
    size_t list = 1;
    // size_t chosenList_Play = 1;
    // size_t chosenMusic_Play = 1;

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
    Metadataview metadataView;

    /* Player */
    MediaPlayer myPlayer;
    Metadata metaData;
    PlaylistView playListView;

public:
    Browser(/* args */);
    ~Browser();

    void setPath();
    void loadFile();   
    void FreeAll();
    void CallbackRegister();

    int userInput();
    string userInputString();


    void menu();
    void medialist();
    
    /**/
    void playlist(size_t& chosenList, size_t& chosenMusic);
    void playlist_music(size_t& chosenList);

    /*Create Playlist*/
    void createList();
    
    /* Delete playlist */
    void deleteList();

    /* Rename playlist */
    void renameList();

    /**/
    void playmusic(size_t& chosenList);
    void playmusic_player(size_t& chosenList, size_t& chosenMusic);

    /**/
    void programFlow();

    

};


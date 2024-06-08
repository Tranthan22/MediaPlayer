#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include <stack>
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/taglib.h>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

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
    int current_screen;
    int chosenList = 1;
    int chosenMusic = 1;
    size_t list = 1;
    // size_t chosenList_Play = 1;
    // size_t chosenMusic_Play = 1;

    /* Stack */
    std::stack<int> flowID;

    /* Vector data */
    vector<Playlist*> vPlayList;    //vector contains playlist (include vMediaFile)
    // vector<MediaFile*> vMediaFile; // Vector contains files (all file)

    /* ptr Meta*/ 
    // Metadata* vMetadata; 

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
    
    /* Thread */
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::duration<double> timelapse;
    std::thread myThread;
    TagLib::FileRef fileRef;

    std::mutex mtx1;
    std::mutex mtx2;


public:
    Browser(/* args */);
    ~Browser();

    void setPath();
    void loadFile();   
    void FreeAll();
    void CallbackRegister();

    int userInput();
    string userInputString();

    /* Menu */ 
    void menu();
    /*META*/
    void medialist();
    void viewMetadata(int file_idx);
    void updateMetadata(int file_idx);
    
    /**/
    void playlist(int& chosenList, int& chosenMusic);
    void playlist_music(int& chosenList);

    /*Create Playlist*/
    void createList();
    
    /* Delete playlist */
    void deleteList();

    /* Rename playlist */
    void renameList();

    /**/
    void playmusic(int& chosenList);
    void playmusic_player(int& chosenList, int& chosenMusic);

    /**/
    void programFlow();

    /*thread*/
    void updatePlayerView();
    inline void startThread();
};


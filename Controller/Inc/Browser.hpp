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
#include "USB.hpp"
#include <stack>

#define START_PAGE                  1
#define MP3_EXTENSION               ".mp3"
#define MP4_EXTENSION               ".mp4"
#define MP3_TYPE                    1
#define MP4_TYPE                    2

enum FlowID
{   
    MENU_ID = 0,
    MEDIA_LIST_ID = 1,
    METADATA_LIST_ID =2,
    PLAY_LIST_ID = 3,
    PLAY_MUSIC_ID = 4,
    PLAY_LIST_MUSIC_ID = 5,
    PLAY_MUSIC_PLAYER_ID = 6,
    PATH_USB_ID =7,
    SET_PATH_ID =8,
    CLOSE_PROGRAM =9
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

    /*                    SHOW METADATA IN MEDIALIST                       */
    string file_path = "";
    string file_name = "";
    int file_type = 0;
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
    PlaylistView playListView;
    /* Player */
    MediaPlayer& myPlayer = MediaPlayer::getMediaPlayer();
    Metadata metaData;
    
    
    /* Thread */
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::duration<double> timelapse;
    std::thread myThread;
    std::thread myThread2;
    TagLib::FileRef fileRef;

    std::mutex mtx1;

    /* USB */
    USBDeviceScanner usbDeviceScanner;
    std::vector<std::string> devices;

public:
    Browser(/* args */);
    ~Browser();

    void setPath();
    void setPathView();
    void PathUsbSelection();

    void loadFile();   
    void FreeAll();

    int userInput();
    string userInputString();

    /* Menu */ 
    void menu();
    /*MEDIA*/
    void medialist();
    /*META DATA*/
    void metadatalist();
    // void viewMetadata(int file_idx);
    void viewMetadata(const string& file_path,const string& file_name,const int& file_type);
    // void updateMetadata(int file_idx);
    void updateMetadata(string& file_path,string& file_name,int& file_type);
    
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
    void display();
    /*thread*/
    void updatePlayerView();
    inline void startThread();
    inline void resetTimer();
};

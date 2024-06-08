#pragma once
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include "MediaFile.hpp"

#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
// #include "MediaPlayerView.hpp"

class MediaPlayer
{
private:
    size_t SysVolume = MIX_MAX_VOLUME;
    std::vector<MediaFile*> *list;
    static bool Playing;
    static int fileIndexInList;
    Mix_Music *bgm;    bool flagAuto =false;

public:
    MediaPlayer(/* args */);
    ~MediaPlayer();

    /* Media Player */
    int playMusic(/*const char* file*/);
    void ResumePause();
    void nextMusic();
    void preMusic();
    void autoMusic();
    void setList(std::vector<MediaFile*> *list);
    static void setIndexInList(int index);
    string getPlayingMusicName();
    string getPlayingMusicPath();
    bool isPlaying();
    /* Volume */
    size_t getVolume();
    int VolumeUp();
    int VolumeDown();
    void Exit_play();

    void setFlagAuto(bool flagAuto);
    bool getFlagAuto();

};

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
    int SysVolume = MIX_MAX_VOLUME / 2;
    std::vector<MediaFile*> *list;
    static bool Playing;
    static size_t fileIndexInList;

    // std::atomic<bool> isPlaying;
    // std::thread updateThread;
    // std::mutex mtx; // to ensure thread safety
    // PlayMusicView mediaPlayerView; // Declare the mediaPlayerView object
    // std::chrono::time_point<std::chrono::steady_clock> startTime;
    // bool isMusicPlaying = false;

    // void updateStatus();

public:
    Mix_Music *bgm;
    MediaPlayer(/* args */);
    ~MediaPlayer();

    /* Media Player */
    int playMusic(const char* file);
    void ResumePause();
    void nextMusic();
    void setList(std::vector<MediaFile*> *list);
    static void setIndexInList(size_t index);

    /* Volume */
    int getVolume();
    int VolumeUp();
    int VolumeDown();
    void Exit_play();

    // void startStatusUpdate();
    // void stopStatusUpdate();

    // double getMusicPosition();
};

#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include "MediaFile.hpp"



class MediaPlayer
{
private:
    int SysVolume = MIX_MAX_VOLUME / 2;
    static bool Playing;

public:
    MediaPlayer(/* args */);
    ~MediaPlayer();

    /* Media Player */
    int playMusic(const char* file);
    void ResumePause();
    void nextMusic(std::vector<char*>& list);
    // PlayerStatus isPlaying();

    /* Volume */
    int getVolume();
    int VolumeUp();
    int VolumeDown();
    vector<MediaFile *> getMediaFiles();
};

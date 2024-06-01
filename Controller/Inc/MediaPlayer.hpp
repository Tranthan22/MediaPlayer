
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include "MediaFile.hpp"



class MediaPlayer
{
private:
    int SysVolume = MIX_MAX_VOLUME / 2;
    std::vector<char*> *list;
    static bool Playing;
    static size_t fileIndexInList;

public:
    MediaPlayer(/* args */);
    ~MediaPlayer();

    /* Media Player */
    int playMusic(const char* file);
    void ResumePause();
    void nextMusic();
    void setList(std::vector<char*> *list);

    /* Volume */
    int getVolume();
    int VolumeUp();
    int VolumeDown();
    vector<MediaFile *> getMediaFiles();
};
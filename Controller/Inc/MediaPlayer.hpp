
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include "MediaFile.hpp"



class MediaPlayer
{
private:
    int SysVolume = MIX_MAX_VOLUME / 2;
public:
    MediaPlayer(/* args */);
    ~MediaPlayer();
    int listUpdate();
    void pauseMusic();
    void nextMusic(std::vector<char*>& list);
    int playMusic(const char* file);

    int getVolume();
    int VolumeUp();
    int VolumeDown();
    vector<MediaFile *> getMediaFiles();
};

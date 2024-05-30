
#include <vector>
#include <string>
#include "MediaFile.hpp"

#ifndef MIX_MAX_VOLUME
#define MIX_MAX_VOLUME 128
#endif

class PlaylistController
{
private:
    int SysVolume = MIX_MAX_VOLUME / 2;
public:
    PlaylistController(/* args */);
    ~PlaylistController();
    int listUpdate();
    void pauseMusic();
    void nextMusic(std::vector<char*>& list);
    int playMusic(const char* file);

    int getVolume();
    int VolumeUp();
    int VolumeDown();
    vector<MediaFile *> getMediaFiles();
};

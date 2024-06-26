#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "MediaFile.hpp"
#include <vector>

using namespace std;

class Playlist
{
private:
    string name;
    vector<MediaFile*> pPlaylist;

public:
    Playlist(const string &n);
    ~Playlist() = default;

    void addFile(MediaFile *file);

    void deleteFile(int file_idx);

    string getName();
    void setName(string name);

    int getSize();
    vector<MediaFile*>& getPlaylist();
    vector<MediaFile*>* getPlaylistPointer();

};

#endif /*PLAYLIST_H*/

#include "Playlist.hpp"
#include "MediaFile.hpp"

using namespace std;

Playlist::Playlist(const string &n) : name(n) {}

void Playlist::addFile(MediaFile *file){
    pPlaylist.push_back(file);
}

void Playlist::deleteFile(int file_idx){
    if(file_idx >= 0 && file_idx < int(pPlaylist.size())) {
        pPlaylist.erase(pPlaylist.begin() + file_idx);
    }
}

string Playlist::getName(){
    return name;
}

vector<MediaFile*>& Playlist::getPlaylist(){
    return pPlaylist;
}

vector<MediaFile*>* Playlist::getPlaylistPointer(){
    return &pPlaylist;
}
int Playlist::getSize()
{
    return pPlaylist.size();
}
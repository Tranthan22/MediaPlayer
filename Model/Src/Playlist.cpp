#include "Playlist.hpp"
#include "MediaFile.hpp"

using namespace std;

Playlist::Playlist(const string &n) : name(n) {}

void Playlist::addFile(MediaFile *file){
    files.push_back(*file);
}

void Playlist::deleteFile(int file_idx){
    if(file_idx >= 0 && file_idx < files.size()) {
        files.erase(files.begin() + file_idx);
    }
}

string Playlist::getName(){
    return name;
}

vector<MediaFile> Playlist::getFiles(){
    return files;
}
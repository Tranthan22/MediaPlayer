#ifndef PLAYLISTVIEW_HPP
#define PLAYLISTVIEW_HPP

#include <iostream>
#include <iomanip> // Để sử dụng setw()
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "MediaFile.hpp"
#include "Playlist.hpp"

#define LIST_SIZE 4
#define LIST_NAME_SIZE 4
class PlaylistView
{
    private:
        // fix size
        std::string truncate(const std::string& text, size_t width) {
        if (text.length() <= width) {
            return text;
        } else {
            return text.substr(0, width - 3) + "...";
        }
        }
    public:
        
        PlaylistView()=default;
        ~PlaylistView()=default;
        void display_Playlist(const vector<Playlist*>& plists, size_t currentpage);
        void display_PlaylistPerPage(const vector<Playlist*>& plists, size_t currentpage);

        void display_PlaylistName(const vector<MediaFile*>plist_name, size_t currentpage);
        void display_PlaylistNamePerPage(vector<MediaFile*> plists, size_t currentpage);

        void display_PlayNameAdd(vector<MediaFile*>& plist_name, size_t currentPage);
        void display_PlayNameRemove(vector<MediaFile*>& plists_name, size_t& currentPage);
};
#endif

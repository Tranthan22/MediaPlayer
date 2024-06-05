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
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/taglib.h>

#define LIST_SIZE 4
#define LIST_NAME_SIZE 4

using namespace std;
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
        void display_Playlist(const vector<Playlist*>& plists, size_t& currentPage);
        void display_PlaylistPerPage(const vector<Playlist*>& plists, size_t& currentPage);
        int check_choice_PlaylistView(const vector<Playlist*>& lists, size_t& currentPage);

        void playlistName(const vector<MediaFile*>&plist_name, size_t &currentPage);
        void display_PlaylistName(const vector<MediaFile*>& plist_name, size_t& currentPage);
        void display_PlaylistNamePerPage(const vector<MediaFile*>& plists, size_t& currentPage);
        int check_choice_PlaylistName(const vector<MediaFile*>& lists_name, size_t& currentPage);

        void display_PlayNameAdd(vector<MediaFile*>& plist_name, size_t& currentPage);
        void display_PlayNameRemove(vector<MediaFile*>& plists_name, size_t& currentPage);
};
#endif

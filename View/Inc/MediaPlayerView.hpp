#ifndef MEDIAPLAYERVIEW_HPP
#define MEDIAPLAYERVIEW_HPP

#include <iomanip> // Để sử dụng setw()
#include <iostream>
#include <fstream>
#include <cstdlib> // For std::system
#include <filesystem>
#include <vector>
// namespace fs = std::filesystem;
#include "main.hpp"
#include "Playlist.hpp"
#include "PlaylistView.hpp"

#define PLIST_SIZE 10
#define PAGE_SIZE 25

class PlayMusicView:public PlaylistView
{
    private:
        
    public:
        PlayMusicView()=default;
        ~PlayMusicView()=default;

        // fix size
        std::string truncate(const std::string& text, int width)
        {
            if ((int)text.length() <= width)
            {
                return text;
            }
            else
            {
                return text.substr(0, width - 3) + "...";
            }
        }
        void display_PlayMucsic(const vector<Playlist*>& plists, size_t currentpage);
        // void display_ListsPerPage(const vector<MediaFile*>& songs, size_t currentpage);
        void check_choice_PlayMusicView(const vector<Playlist*>& lists, size_t& currentPage);
        virtual void display_ShowPlay(const vector<MediaFile*>& lists_name, size_t currentpage){};
        virtual void check_choice_PlayMusicView_ShowPlay(const vector< MediaFile*>& lists_name, size_t currentPage){};

};


class PlayMusicView_ShowPlay:public PlayMusicView
{
    private:

    public:
        PlayMusicView_ShowPlay()=default;
        ~PlayMusicView_ShowPlay()=default;
        void check_choice_PlayMusicView_ShowPlay(const vector< MediaFile*>& lists_name, size_t currentPage);
        void display_ShowPlay(const vector<MediaFile*>& lists_name, size_t currentPage);
        // void display_ShowPlayListsPerPage(const vector<MediaFile*>& songs, size_t currentpage);

};

#endif

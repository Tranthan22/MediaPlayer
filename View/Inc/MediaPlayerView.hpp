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
#include "main.hpp"
#include "Playlist.hpp"
#include "PlaylistView.hpp"
#include "MediaPlayer.hpp"

#define PLIST_SIZE 4
#define PAGE_SIZE 4 

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
        void display_PlayMucsic(const vector<Playlist*>& plists, size_t& currentpage);
        // void display_ListsPerPage(const vector<MediaFile*>& songs, size_t currentpage);
        int check_choice_PlayMusicView(const vector<Playlist*>& lists, size_t& currentPage);
        void display_ShowPlay(const vector<MediaFile*>& lists_name, size_t &currentpage, size_t duration, size_t current, MediaPlayer& myPlayer);
        int check_choice_PlayMusicView_ShowPlay(const vector< MediaFile*>& lists_name, size_t& currentPage);
        void Time_Volume(const size_t duration, const size_t current, const size_t volume) const;
        // void Time_Volume();
        // void displayVolume(int volume);
        // void displayTime(double currentTime, double duration);
};


class PlayMusicView_ShowPlay:public PlayMusicView
{
    private:

    public:
        PlayMusicView_ShowPlay()=default;
        ~PlayMusicView_ShowPlay()=default;
        
};

#endif

#ifndef MEDIAPLAYERVIEW_HPP
#define MEDIAPLAYERVIEW_HPP


#include "main.hpp"
#include "Playlist.hpp"
#include "PlaylistView.hpp"
#include "MediaPlayer.hpp"


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
        void display_ShowPlay(const vector<MediaFile*>& lists_name, size_t &currentpage, size_t timelapse, size_t duration, MediaPlayer& myPlayer);
        int check_choice_PlayMusicView_ShowPlay(const vector< MediaFile*>& lists_name, size_t& currentPage);
        void Time_Volume(size_t timelapse, size_t duration, const size_t volume) const;
        
        inline string format_time(size_t total_seconds) const;
};

#endif

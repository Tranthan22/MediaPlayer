#ifndef PLAYLISTVIEW_HPP
#define PLAYLISTVIEW_HPP

#include <iostream>
#include <iomanip> // Để sử dụng setw()
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


struct play_list
{
    /* data */
    string list_name;
    string Number_song;

};
struct playlist_name{
    string Name;
    string Artist;
    string Duration;
    string Publisher;
};

class PlaylistView
{
    private:
        // fix size
        string truncate(const string& text, size_t width) {
        if (text.length() <= width) {
            return text;
        } else {
            return text.substr(0, width - 3) + "...";
        }
        }
    public:
        
        PlaylistView()=default;
        ~PlaylistView()=default;
        void display_Playlist(const vector<play_list>& plists, size_t currentpage);
        void display_PlaylistPerPage(const vector<play_list>& plists, size_t currentpage);

        void display_PlaylistName(const vector<playlist_name>& plist_name, size_t currentpage);
        void display_PlaylistNamePerPage(const vector<playlist_name>& plists, size_t currentpage);

        void display_PlayNameAdd(const vector<playlist_name>& plist_name, size_t currentPage);
        void display_PlayNameRemove(const vector<playlist_name>& plists_name, size_t& currentPage);
};
#endif

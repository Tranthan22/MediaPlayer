#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip> // Để sử dụng setw()
using namespace std;




class MediaFileView
{
private:
    // fix size
    string truncate(const string& text, int width) {
    if (text.length() <= width) {
        return text;
    } else {
        return text.substr(0, width - 3) + "...";
    }
    }
public:
    MediaFileView()=default;
    ~MediaFileView()=default;
    struct Song {
            string name;
            string artist;
            string duration;
            string publisher;
        };
    void display_MediaFile();
    void check_choice(const vector<Song>& songs, size_t& currentPage);
    void displaySongsPerPage(const vector<Song>& songs, size_t currentpage);
};

#endif


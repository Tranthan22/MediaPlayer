#ifndef MEDIAFILEVIEW_HPP
#define MEDIAFILEVIEW_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip> // Để sử dụng setw()
using namespace std;

#define page_size 25



class MediaFileView
{
private:
    // fix size
    string truncate(const string& text, int width) {
    if ((int)text.length() <= width) {
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
    void display_MediaFile(const vector<Song>& songs, size_t currentpage);
    void displaySongsPerPage(const vector<Song>& songs, size_t currentpage);
    // khi chon page vuot qua so luong bai  
    void Invalid_pageNumber();
    // Khi khong co lua chon nao dung
    void Invalid_choice();
    // ham nay co khi dung o phia control.
    void check_choice(const vector<Song>& songs, size_t& currentPage);
};

#endif /*MEDIAFILEVIEW_HPP*/


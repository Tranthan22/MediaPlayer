#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <iostream>
#include <vector>
#include <iomanip> // Để sử dụng setw()
using namespace std;


struct Song {
        string name;
        string artist;
        string duration;
        string publisher;
    };

class MediaFileView
{
private:
    size_t choice;
    size_t page;
    

public:
    MediaFileView()=default;
    ~MediaFileView()=default;

    void display_MediaFile();
    void check_choice(const vector<Song>& songs, int page);
    void get_Mediafile();
    void choice_page();
    void displaySongsPerPage(const vector<Song>& songs, int page);
    void selectPage(const vector<Song>& songs, int& currentPage);
    void set_choice(size_t choice)
    {
       this->choice = choice;
    }
    size_t get_choice()
    {
        return choice;
    }
    void set_page(size_t page)
    {
       this->page = page;
    }
    size_t get_page()
    {
        return page;
    }
};

#endif


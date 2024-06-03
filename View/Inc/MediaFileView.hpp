#ifndef MEDIAFILEVIEW_HPP
#define MEDIAFILEVIEW_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip> // Để sử dụng setw()
#include "MediaFile.hpp"
using namespace std;

#define PAGE_SIZE 4

class MediaFileView
{
private:
    //Path:
    std::string directoryPath;
    // fix size
    std::string truncate(const string& text, int width)
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
public:
    MediaFileView()=default;
    ~MediaFileView()=default;
    
    void display_MediaFile(const vector<MediaFile*>& songs, size_t currentpage);
    
    void displaySongsPerPage(const vector<MediaFile*>& songs, size_t& currentpage);
    // khi chon page vuot qua so luong bai  
    void Invalid_pageNumber();
    
    // Khi khong co lua chon nao dung
    void Invalid_choice();
    
    // ham nay co khi dung o phia control.
    void check_choice(const vector<MediaFile*>& songs, size_t& currentPage);

};

#endif /*MEDIAFILEVIEW_HPP*/


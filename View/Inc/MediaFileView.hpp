#ifndef MEDIAFILEVIEW_HPP
#define MEDIAFILEVIEW_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip> // Để sử dụng setw()
#include "MediaFile.hpp"
#include "MetadataView.hpp"
#include "main.hpp"
using namespace std;



class MediaFileView:public Metadataview
{
private:
    //Path:
    std::string directoryPath;
    // int choice;
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
    
    void display_MediaFile(vector<MediaFile*>& songs, size_t currentpage);
    
    void displaySongsPerPage(vector<MediaFile*>& songs, size_t& currentpage);
    // khi chon page vuot qua so luong bai  
    // void Invalid_pageNumber();
    
    // Khi khong co lua chon nao dung
    void Invalid_choice();
    
    // ham nay co khi dung o phia control.
    int check_choice(vector<MediaFile*>& songs, size_t& currentPage);
    // void setChoice(int choice);
    // int getChoice();

};

#endif /*MEDIAFILEVIEW_HPP*/


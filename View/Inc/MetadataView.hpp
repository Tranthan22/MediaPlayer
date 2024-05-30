#ifndef METADATAVIEW_HPP
#define METADATAVIEW_HPP

#include <iostream>
#include <iomanip> // Để sử dụng setw()
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Media_list
{
    /* data */
    string list;
    string Lastmodified;

};

class MetadataView
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
    
    MetadataView()=default;
    ~MetadataView()=default;
    void display_MediaList();
    void display_MedialistPerPage(const vector<Media_list>& lists, size_t currentpage);
    void choose_list(const vector<Media_list>& lists, size_t& currentPage);
};


#endif
#ifndef __METADATA_
#define __METADATA_

#include "main.hpp"
#include "MediaFileView.hpp"
#include "MetadataView.hpp"
#include "MenuView.hpp"
#include "Browser.hpp"

class Browser;

class Metadata
{
private:
    string file_name;
    string file_path;
    int file_type;
    MediaFileView view_media_file;
    Metadataview view_metadata;
    MenuView view_menu;

public:
    Metadata() = default;
    ~Metadata() = default;

    void viewMetadata(Browser *browser, int file_idx);

    void updateMetadata(Browser *browser, int file_idx);
};

#endif
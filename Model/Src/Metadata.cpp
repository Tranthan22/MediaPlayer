#ifndef __METADATA_
#define __METADATA_

#include "MediaFileView.hpp"
#include "MenuView.hpp"
#include "MetadataView.hpp"

class PlaylistController;

class Metadata
{
private:
    string file_name;
    string file_path;
    int file_type;
    MetadataView view_metadata;
    MenuView view_menu;
    MediaFileView view_file;

public:
    Metadata() = default;
    ~Metadata() = default;

    void viewMetadata(PlaylistController *ptr_control, int file_idx);

    void updateMetadata(PlaylistController *ptr_control, int file_idx);
};

#endif



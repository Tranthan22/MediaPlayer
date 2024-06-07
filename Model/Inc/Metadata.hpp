#ifndef __METADATA_
#define __METADATA_

// #include "main.hpp"
#include "MediaFileView.hpp"
#include "MetadataView.hpp"
#include "MenuView.hpp"

enum {
    UNKNOWN_FILE_TYPE               = 0,
    AUDIO_FILE_TYPE                 = 1,
    VIDEO_FILE_TYPE                 = 2

};
enum {
    MODIFY_NAME                     = 1,
    MODIFY_ALBUM                    = 2,
    MODIFY_ARTIST                   = 3,
    MODIFY_YEAR                     = 4,
    MODIFY_GENRE                    = 5,
    MODIFY_AUDIO_DURATION           = 6
};

enum {
    MODIFY_VIDEO_NAME               = 1,
    MODIFY_SIZE                     = 2,
    MODIFY_BIT_RATE                 = 3,
    MODIFY_VIDEO_DURATION           = 4,
};


class Metadata
{
private:
    string file_Path;
    TagLib::FileRef fileRef;

public:
    Metadata() = default;
    ~Metadata() = default;

    void set_FilePath(string file_Path);
    TagLib::FileRef getfileRef();
};

#endif
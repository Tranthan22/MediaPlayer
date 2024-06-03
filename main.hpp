#include "SDL.h"
#include <SDL_mixer.h>
#include <iostream>
#include <vector>


enum {
    SHOW_METADATA                   = 1,
    UPDATE_METADATA                 = 2,
    ADD_TO_PLAYLIST                 = 3
};

enum {
    UNKNOWN_FILE_TYPE               = 0,
    AUDIO_FILE_TYPE                 = 1,
    VIDEO_FILE_TYPE                 = 2

};
enum {
    MODIFY_TRACK                    = 1,
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




#define PAGE_SIZE 4
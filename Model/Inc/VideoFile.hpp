#ifndef __VIDEO_FILE_
#define __VIDEO_FILE_

#include "MediaFile.hpp"

using namespace std;

class VideoFile : public MediaFile
{
private:
public:
    VideoFile(const string &n, const string &p);
    ~VideoFile() = default;
};

#endif /* __VIDEO_FILE_ */
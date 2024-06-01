#include "Metadata.hpp"
#include "MediaPlayer.hpp"
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <iostream>

void Metadata::viewMetadata(MediaPlayer *ptr_ctr, int file_idx)
{
    file_name = ptr_ctr->getMediaFiles()[file_idx - 1]->getName();
    file_path = ptr_ctr->getMediaFiles()[file_idx - 1]->getPath();
    file_type = ptr_ctr->getMediaFiles()[file_idx - 1]->getType();
    TagLib::FileRef fileRef(file_path.c_str());
    if (!fileRef.isNull() && fileRef.tag())
    {
        TagLib::Tag *tag = fileRef.tag();
        switch (file_type)
        {
        case '1':
            // view_mediafile.displayAudioFileMetadata(tag, fileRef);
            break;
        case '2':
            // view_mediafile.displayVideoFileMetadata(tag, fileRef, file_path);
            break;
        default:
            // view_mediafile.getMediaFileTypeError();
            break;
        }
    }
    else
    {
        // view_metadata.getMetadataError();
    }
}

void Metadata::updateMetadata(MediaPlayer *ptr_ctr1, int file_idx)
{
    // getline(cin, new_value);
    file_name = ptr_ctr1->getMediaFiles()[file_idx - 1]->getName();
    file_path = ptr_ctr1->getMediaFiles()[file_idx - 1]->getPath();
    file_type = ptr_ctr1->getMediaFiles()[file_idx - 1]->getType();
    TagLib::FileRef fileRef(file_path.c_str());
    TagLib::Tag *tag = fileRef.tag();
    
}
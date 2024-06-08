#ifndef _METADATA_VIEW_H_
#define _METADATA_VIEW_H_

#include "main.hpp"


enum {
    BACK_MENU                       =0,
    SHOW_METADATA                   = 1,
    UPDATE_METADATA                 = 2,
    ADD_TO_PLAYLIST                 = 3
};

class Metadataview
{
public:
    
    Metadataview() = default;
    ~Metadataview() = default;
    void menuMetaView();

    void chooseMetadataField();

    void enterMetadataValue();

    void getMetadataError();

    void modifyMetadataError();

    void modifyMetadataSuccess();

    void displayAudioFileMetadata(TagLib::Tag *tag, TagLib::FileRef fileRef);

    void displayVideoFileMetadata(TagLib::Tag *tag, TagLib::FileRef fileRef, string file_path);

    void getMediaFileTypeError();
};

#endif /*_METADATA_VIEW_H_ */
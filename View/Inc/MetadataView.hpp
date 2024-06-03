#ifndef _METADATA_VIEW_H_
#define _METADATA_VIEW_H_

#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/taglib.h>
#include <iostream>
#include <memory> // For smart pointers
#include <string.h> // For std::string
#include <filesystem>

using namespace TagLib;

using namespace std;

class Metadataview
{
public:
    Metadataview() = default;
    ~Metadataview() = default;

    void menuView();

    void chooseMetadataField();

    void enterMetadataValue();

    void getMetadataError();

    void metadataChooseFile(int input_case);

    void modifyMetadataError();

    void modifyMetadataSuccess();

    void listEmpty(int input_case);

    void displayAudioFileMetadata(Tag *tag, FileRef fileRef);

    void displayVideoFileMetadata(Tag *tag, FileRef fileRef, string file_path);

    void getMediaFileTypeError();
};

#endif /*_METADATA_VIEW_H_ */
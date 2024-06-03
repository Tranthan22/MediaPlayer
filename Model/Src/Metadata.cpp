#include "Metadata.hpp"
#include "MetadataView.hpp"

void Metadata::viewMetadata(Browser *browser, int file_idx)
{
    file_name = browser->getMediaFiles()[file_idx - 1]->getName();
    file_path = browser->getMediaFiles()[file_idx - 1]->getPath();
    file_type = browser->getMediaFiles()[file_idx - 1]->getType();
    TagLib::FileRef fileRef(file_path.c_str());
    if (!fileRef.isNull() && fileRef.tag())
    {
        TagLib::Tag *tag = fileRef.tag();
        switch (file_type)
        {
        case AUDIO_FILE_TYPE:
            view_metadata.displayAudioFileMetadata(tag, fileRef);
            break;
        case VIDEO_FILE_TYPE:
            view_metadata.displayVideoFileMetadata(tag, fileRef, file_path);
            break;
        default:
            view_metadata.getMediaFileTypeError();
        }
    }
    else
    {
        view_metadata.getMetadataError();
    }
}

void Metadata::updateMetadata(Browser *browser, int file_idx)
{
    int update_opt;
    string new_value;
    view_metadata.chooseMetadataField();

    update_opt = browser->userInput();
    view_metadata.enterMetadataValue();

    getline(cin, new_value);
    file_name = browser->getMediaFiles()[file_idx - 1]->getName();
    file_path = browser->getMediaFiles()[file_idx - 1]->getPath();
    file_type = browser->getMediaFiles()[file_idx - 1]->getType();
    TagLib::FileRef fileRef(file_path.c_str());
    TagLib::Tag *tag = fileRef.tag();
    if (file_type == AUDIO_FILE_TYPE)
    {
        switch (update_opt)
        {
        case MODIFY_TRACK:
            tag->setTrack(stoi(new_value));
            break;
        case MODIFY_ALBUM:
            tag->setAlbum(new_value.c_str());
            break;
        case MODIFY_ARTIST:
            tag->setArtist(new_value.c_str());
            break;
        case MODIFY_YEAR:
            tag->setYear(stoi(new_value));
            break;
        case MODIFY_GENRE:
            tag->setGenre(new_value.c_str());
            break;
        case MODIFY_AUDIO_DURATION:
            view_metadata.modifyMetadataError();
            return;
        default:
            view_menu.InvalidChoiceInterface();
        }
    }

    else
    {
        switch (update_opt)
        {
        case MODIFY_VIDEO_NAME:
            tag->setTitle(new_value.c_str());
            break;
        case MODIFY_SIZE:
            view_metadata.modifyMetadataError();
            return;
        case MODIFY_BIT_RATE:
            view_metadata.modifyMetadataError();
            return;
        case MODIFY_VIDEO_DURATION:
            view_metadata.modifyMetadataError();
            return;
        default:
            view_menu.InvalidChoiceInterface();
        }
    }
    if (fileRef.save() == true)
    {
        view_metadata.modifyMetadataSuccess();
    }
}
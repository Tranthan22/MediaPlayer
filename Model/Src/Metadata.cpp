#include "Metadata.hpp"
#include "MetadataView.hpp"


void Metadata::viewMetadata(vector<MediaFile*>& Songs, int file_idx)
{
    file_name = Songs[file_idx-1]->getName();
    file_path = Songs[file_idx-1]->getPath();
    file_type = Songs[file_idx-1]->getType();
    TagLib::FileRef fileRef(file_path.c_str());
    string header = "Displaying Metadata...";
    cout << string(tableWidth , '=')<<endl;
    cout << string(tableWidth / 2-header.length()/2-file_name.length()/2, ' ') << header <<file_name<<endl;
    cout << string(tableWidth, '=')<<endl;
    cout << endl;
    if (!fileRef.isNull() && fileRef.tag())
    {
        TagLib::Tag *tag = fileRef.tag();
        switch (file_type)
        {
        case AUDIO_FILE_TYPE:
            view_metadata.displayAudioFileMetadata(tag, fileRef);
            return;
            // break;
        case VIDEO_FILE_TYPE:
            view_metadata.displayVideoFileMetadata(tag, fileRef, file_path);
            return;
            // break;
        default:
            view_metadata.getMediaFileTypeError();
            return;
        }
    }
    else
    {
        view_metadata.getMetadataError();
        return;
    }
}

void Metadata::updateMetadata(vector<MediaFile*>& Songs, int file_idx)
{   file_name = Songs[file_idx - 1]->getName();
    file_path = Songs[file_idx - 1]->getPath();
    file_type = Songs[file_idx - 1]->getType();
    TagLib::FileRef fileRef(file_path.c_str());
    TagLib::Tag *tag = fileRef.tag();
    // Show data file mp3
    string header = "Updating Metadata...";
    cout << string(tableWidth , '=')<<endl;
    cout << string(tableWidth / 2-header.length()/2 -file_name.length()/2, ' ') << header << file_name<<endl;
    cout << string(tableWidth, '=')<<endl;
    cout << endl;
    view_metadata.displayAudioFileMetadata(tag, fileRef);
    cout<<endl;
    cout << left << setw(30) << "0. Back" << endl;
    cout<<endl;
    cout << string(tableWidth, '=')<<endl;
    int update_opt;
    string new_value;
    view_metadata.chooseMetadataField();
    cin >> update_opt;
    cin.ignore();
    if(update_opt == 0)
    {
        return;
    }else{
    // update_opt = browser->userInput();
    view_metadata.enterMetadataValue();
    getline(cin, new_value);    
        if (file_type == AUDIO_FILE_TYPE)
        {
            switch (update_opt)
            {
            case MODIFY_NAME:
                tag->setTitle(new_value.c_str());
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
                return;
            }
        }else{
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
    if (fileRef.save() == true){
        view_metadata.modifyMetadataSuccess();
        return;
    }
    }
}
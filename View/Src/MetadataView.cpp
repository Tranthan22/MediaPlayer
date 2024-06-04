#include "MetadataView.hpp"
#include "main.hpp"


using namespace std;

void Metadataview::menuView()
{
    cout << "                                  Menu Metadata                                " << endl;
    cout << "==============================================================================\n" << endl;
    cout << left << setw(30) << "1. Show Metadata"
         << left << setw(30) << "2. Update Metadata"
         << left << setw(30) << "0. Back"<<endl;
    cout << "==============================================================================\n" << endl;
    cout << "Input your command: " << endl;
}

void Metadataview::chooseMetadataField()
{
    cout << "Choose a metadata field to modify: " << endl;
}

void Metadataview::enterMetadataValue()
{
    cout << "Enter new value: " << endl;
}

void Metadataview::getMetadataError()
{
    cerr << "Could not open file or retrieve tag." << endl;
}

void Metadataview::metadataChooseFile(int input_case)
{
    switch (input_case)
    {
    case SHOW_METADATA:
        cout << "Enter index of media file that you want to show metadata: " << endl;
        break;

    case UPDATE_METADATA:
        cout << "Enter index of media file that you want to update metadata: " << endl;
        break;

    default:
        cerr << "Error!" << endl;
    }
}

void Metadataview::modifyMetadataError()
{
    cout << "This field cannot be modify." << endl;
}

void Metadataview::modifyMetadataSuccess()
{
    cout << "Metadata updated succesfully!" << endl;
}

void Metadataview::listEmpty(int input_case)
{
    switch (input_case)
    {
    case SHOW_METADATA:
        cout << "There is nothing to show metadata of. Going back..." << endl;
        break;

    case UPDATE_METADATA:
        cout << "There is nothing to update metadata of. Going back..." << endl;
        break;

    default:
        cerr << "Error!" << endl;
    }
} 

void Metadataview::displayAudioFileMetadata(TagLib::Tag *tag, TagLib::FileRef fileRef)
{
    cout << "\n============================================================================================" << endl;
    cout << left << setw(30)<< "1. Track:   " << tag->track() << endl;
    cout << left << setw(30)<< "2. Album:   " << tag->album().toCString(true) << endl;
    cout << left << setw(30)<< "3. Artist:  " << tag->artist().toCString(true) << endl;
    cout << left << setw(30)<< "4. Publish Year:    " << tag->year() << endl;
    cout << left << setw(30)<< "5. Genre:   " << tag->genre().toCString(true) << endl;
    cout << left << setw(30)<< "6. Duration: " << fileRef.audioProperties()->length() << " seconds" << endl;
    cout << "\n============================================================================================" << endl;
    cout << left << setw(25) << "0. Back" << endl;
    cout << "\n============================================================================================" << endl;
}

void Metadataview::displayVideoFileMetadata(TagLib::Tag *tag, TagLib::FileRef fileRef, string file_path)
{
    cout << left << setw(30)<< "1. Video name:   " << tag->title().toCString(true) << endl;
    cout << left << setw(30)<< "2. File Size: " << filesystem::file_size(file_path) / 1000 << " Kbytes" << endl;
    cout << left << setw(30)<< "3. Bit rate: " << fileRef.audioProperties()->bitrate() << " kbps" << endl;
    cout << left << setw(30)<< "4. Duration: " << fileRef.audioProperties()->length() << " seconds" << endl;
    cout << endl;
}

void Metadataview::getMediaFileTypeError()
{
    cerr << "Unknown media file type!" << endl;
}

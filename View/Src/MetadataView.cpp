#include "MetadataView.hpp"


/*========================================================================================================================================================*/
//                                                              SHOW METADATA 
/*========================================================================================================================================================*/
void Metadataview::menuMetaView()
{
    system("clear");
    string header = "Menu Metadata";
    cout << string(tableWidth , '=')<<endl;
    cout << string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout << string(tableWidth, '=')<<endl;
    cout<<endl;
    cout << left << setw(30) << " "
         << left << setw(tableWidth/4) << "1. Show Metadata"
         << left << setw(tableWidth/4) << "2. Update Metadata"
         << left << setw(tableWidth/4) << "0. Back"<<endl;
    cout <<"\n"<<endl;
    cout << string(tableWidth, '=')<<endl;
    cout<<endl;
    cout << "Input your command: ";
}

void Metadataview::chooseMetadataField()
{
    cout << "Choose a metadata field to modify: " ;
}

void Metadataview::enterMetadataValue()
{
    cout << "Enter new value: " ;
}

void Metadataview::getMetadataError()
{
    cerr << "Could not open file or retrieve tag." << endl;
}
void Metadataview::modifyMetadataError()
{
    cout << "This field cannot be modify." << endl;
}

void Metadataview::modifyMetadataSuccess()
{
    cout << "Metadata updated succesfully!" << endl;
}

void Metadataview::displayAudioFileMetadata(TagLib::Tag *tag, TagLib::FileRef fileRef)
{
    cout << left << setw(30)<< "1. Name:   " << tag->title() << endl;
    cout << left << setw(30)<< "2. Album:   " << tag->album().toCString(true) << endl;
    cout << left << setw(30)<< "3. Artist:  " << tag->artist().toCString(true) << endl;
    cout << left << setw(30)<< "4. Publish Year:    " << tag->year() << endl;
    cout << left << setw(30)<< "5. Genre:   " << tag->genre().toCString(true) << endl;
    cout << left << setw(30)<< "6. Duration: " << fileRef.audioProperties()->lengthInSeconds()<< " seconds" << endl;
    cout << endl;
    cout << string(tableWidth, '=')<<endl;

}

void Metadataview::displayVideoFileMetadata(TagLib::Tag *tag, TagLib::FileRef fileRef, string file_path)
{
    cout << left << setw(30)<< "1. Video name:   " << tag->title().toCString(true) << endl;
    cout << left << setw(30)<< "2. File Size: " << filesystem::file_size(file_path) / 1000 << " Kbytes" << endl;
    cout << left << setw(30)<< "3. Bit rate: " << fileRef.audioProperties()->bitrate() << " kbps" << endl;
    cout << left << setw(30)<< "4. Duration: " << fileRef.audioProperties()->lengthInSeconds() << " seconds" << endl;
    cout << endl;
    cout << string(tableWidth, '=')<<endl;
}

void Metadataview::getMediaFileTypeError()
{
    cerr << "Unknown media file type!" << endl;
}

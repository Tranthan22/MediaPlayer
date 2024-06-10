#include "MediaFileView.hpp"

/*========================================================================================================================================================*/
//                                                                     SHOW SONGS IN MEDIALIST                                                            //
/*========================================================================================================================================================*/

void MediaFileView::display_MediaFile(vector<MediaFile*>& songs, size_t currentpage)
{
    system("clear");
    string header = "Media List";
    cout << string(tableWidth , '=')<<endl;
    cout << string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout << string(tableWidth, '=')<<endl;
    cout <<"|"<< left << setw(10) << " No."
         <<"|"<< left << setw(tableWidth/3) << "Name"
         <<"|"<< left << setw(tableWidth/4) << "Artist"
         <<"|"<< left << setw(tableWidth/8) << "Duration (s)"
         <<"|"<< left << setw(tableWidth/8) << "Publisher"<<endl;
    cout << string(tableWidth ,'-')<<"\n"<<endl;

    displaySongsPerPage(songs, currentpage);
    
    cout <<"\n"<< string(tableWidth , '-')<<endl;
    cout << "Total Media list: " << songs.size() << endl;
    cout << "Page: " << currentpage<<endl;
    cout <<string(tableWidth/4, ' ')
         << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit"<< endl;
    cout<<endl;
    cout<< string(tableWidth , '=')<<endl;
}

void MediaFileView::displaySongsPerPage(vector<MediaFile*>& songs, size_t& currentpage) {
    size_t startIndex = (currentpage - 1) * PAGE_SONG_SIZE;
    size_t endIndex = min(startIndex + PAGE_SONG_SIZE, songs.size());
    for (int i = (int)startIndex; i < (int)endIndex; ++i) {
        string file_path = songs[i]->getPath();
        string file_name = songs[i]->getName();
        TagLib::FileRef fileRef(file_path.c_str());
    if (!fileRef.isNull() && fileRef.tag()){
        TagLib::Tag *tag = fileRef.tag();   
        std::cout <<"|"<< left << setw(10) << i+1
            <<"|"<< left << left_align(truncate_utf8(tag->title().toCString(true), 35),tableWidth/3)
            <<"|"<< left << left_align(truncate_utf8(tag->artist().toCString(true), 30),tableWidth/4)
            <<"|"<< left << setw(tableWidth/8) << secondsToTimeFormat(fileRef.audioProperties()->lengthInSeconds())
            <<"|"<< left << setw(tableWidth/8) << tag->year()<< endl;
    }
    }   
}
/*========================================================================================================================================================*/
void MediaFileView::Invalid_choice()
{
    cout << "Invalid choice. Please enter a valid option." << endl;
}

// ==================================================== CHECK USING FOR CHOOSE SONG IN MEDIALIST TO MODIFIED =============================================//

int MediaFileView::check_choice(vector<MediaFile*>& songs, size_t& currentPage) {
    string userInput;int Song_Choice;
    bool flag = true;
    while(flag)
    {
        display_MediaFile(songs,currentPage);
        getline(cin, userInput);
        if (!userInput.empty()) {
            stringstream ss(userInput);
            
            if (ss >> Song_Choice)
            {
                if (Song_Choice > 0 && Song_Choice <= (int)songs.size())
                {
                    return Song_Choice;
                    flag = false;

                }else{
                    Invalid_choice();
                    cin.ignore();
                }
            }else{
                char command = userInput[0];
                switch (command)
                {
                    /*NEXT PAGE*/
                    case 'N':
                    case 'n':
                        if (currentPage < (songs.size() + PAGE_SONG_SIZE - 1) / PAGE_SONG_SIZE)
                        {
                            currentPage++;
                        }
                        break;
                    /*PRERIOUS PAGE*/
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        break;
                    /*EXIT PAGE*/
                    case 'E':
                    case 'e':
                        flag = false;
                        return -1;
                        break;
                    default:
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }else{
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    /*RETURN PAGE*/
    return Song_Choice;
}

/*========================================================================================================================================================*/

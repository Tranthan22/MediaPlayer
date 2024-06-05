#include "PlaylistView.hpp"

void PlaylistView::display_Playlist(const vector<Playlist*>& plists, size_t &currentPage){
    system("clear");
    cout << "                                       Playlist                                   " << endl;
    cout << "============================================================================================\n" << endl;
    cout << left << setw(10) << "No."
         << left << setw(40) << "List Name"
         << left << setw(40) << "Number" << endl;

    display_PlaylistPerPage(plists,currentPage);

    cout << "\n============================================================================================" << endl;
    cout<< "Total Media list: "<<plists.size()<<endl;
    cout<< "Page: "<<currentPage<<endl;
    cout <<left << setw(25) << "C. Create"
         << left << setw(25) << "D. Delete"
         << left << setw(25) << "R. Rename"
         << left << setw(25) << "E. Exit" << endl;
    cout << "============================================================================================" << endl;
}

// Ham lay du lieu tu model de truyen du lieu len
void PlaylistView::display_PlaylistPerPage(const vector<Playlist*>& plists, size_t &currentpage) {
    int startIndex = ((int)currentpage - 1) * LIST_SIZE;
    int endIndex = min(startIndex + LIST_SIZE, static_cast<int>(plists.size()));
    // static_cast<int> chuyen doi sang so int
    for (int i = startIndex; i < endIndex; ++i) {
        cout << left << setw(10) << i + 1
        // dung de lay ten 
             << left << setw(40) << truncate(plists[i]->getName(), 40)
             << left <<plists[i]->getSize() <<" Songs"<< endl;
    }
}

int PlaylistView::check_choice_PlaylistView(const vector<Playlist*>& lists, size_t& currentPage) {
    string userInput;
    bool flag = true;
    cout << "Choose option to playlist: " << endl;
    while(flag)
    {   
        getline(cin, userInput);
        if (!userInput.empty()) {
            stringstream ss(userInput);
            size_t ListChoice;
            if (ss >> ListChoice)
            {
                if (ListChoice > 0 && ListChoice <= lists.size())
                {
                    return ListChoice;
                }
            }
            else
            {
                char command = userInput[0];
                switch (command)
                {
                    case 'N':
                    case 'n':
                        if (currentPage < (lists.size() + LIST_SIZE - 1) / LIST_SIZE)
                        {
                            currentPage++;
                        }
                        system("clear");
                        display_Playlist(lists,currentPage);
                        break;
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        system("clear");
                        display_Playlist(lists,currentPage);
                        break;

                    /* Create list */
                    case 'C':
                    case 'c':
                        return -1;
                        break;

                    /* Delete list */
                    case 'D':
                    case 'd':
                        return -2;
                        break;

                    /* Rename list*/
                    case 'R':
                    case 'r':
                        return -3;
                        break;

                    case 'E':
                    case 'e':
                        flag = false;
                        break;
                    default:
                        display_Playlist(lists,currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            display_Playlist(lists,currentPage);
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;
}

/*===============================================================================================================*/

//                                                SHOW SONGS IN PLAYLIST CHOOSE                                  //
/*===============================================================================================================*/


void PlaylistView:: playlistName(const vector<MediaFile*>&plist_name, size_t &currentPage)
{
    cout << "                                                    Play list name                                                " << endl;
    cout << "\n======================================================================================================================\n" << endl;
    std::cout << left << setw(10) << "No."
         << left << setw(40) << "Name"
         << left << setw(30) << "Artist"
         << left << setw(20) << "Duration(s)"
         << left << setw(20) << "Publisher" << endl;
     display_PlaylistNamePerPage(plist_name,currentPage);
     cout << "\n======================================================================================================================\n" << endl;
     cout<< "Total Media list: "<<plist_name.size()<<endl;
     cout<< "Page: "<<currentPage;
}
void PlaylistView::display_PlaylistNamePerPage(const vector<MediaFile*>&plist_name, size_t &currentPage) {
    size_t startIndex = (currentPage - 1) * LIST_NAME_SIZE;
    size_t endIndex = min(startIndex + LIST_NAME_SIZE, plist_name.size());
    for (size_t i = startIndex; i < endIndex; ++i) {
        // string file_name = plist_name[i]->getName();
        string file_path = plist_name[i]->getPath();
        // size_t file_type = plist_name[i]->getType();
        TagLib::FileRef fileRef(file_path.c_str());
    if (!fileRef.isNull() && fileRef.tag()){
        TagLib::Tag *tag = fileRef.tag();
        std::cout << left << setw(10) << i + 1
            << left << setw(40) << truncate(tag->title().toCString(),40)
            << left << setw(30) << truncate(tag->artist().toCString(),30)
            << left << setw(20) << fileRef.audioProperties()->lengthInSeconds()
            << left << setw(20) << tag->year()<< endl;
    }
    }
    std::cout<<endl;
}
void PlaylistView::display_PlaylistName(const vector<MediaFile*>&plist_name, size_t &currentPage) {
    playlistName(plist_name,currentPage);
    cout<<setw(15)<<" "<<left << setw(30) << "P. Previous"
          << left << setw(30) << "N. Next"
          << left << setw(30) << "E. Exit" << endl;
    cout<<setw(22)<<" "<<left << setw(30) << "R. Remove"
          << left << setw(30) << "A. Add" << endl;
    cout << "======================================================================================================================" << endl;
}


int PlaylistView::check_choice_PlaylistName(const vector<MediaFile*>& lists_name, size_t& currentPage) {
    string userInput;
    bool flag = true;
    cout << "Choose option to play: " << endl;
    while(flag)
    {   
        
        getline(cin, userInput);
        if (!userInput.empty()) {
            stringstream ss(userInput);
            size_t MusicChoice;
            if (ss >> MusicChoice)
            {
                if (MusicChoice > 0 && MusicChoice <= lists_name.size())
                {
                    return MusicChoice;
                }
            }
            else
            {
                char command = userInput[0];
                switch (command)
                {
                    /* Next page */
                    case 'N':
                    case 'n':
                        if (currentPage < (lists_name.size() + LIST_NAME_SIZE - 1) / LIST_NAME_SIZE)
                        {
                            currentPage++;
                        }
                        system("clear");
                        display_PlaylistName(lists_name, currentPage);
                        cout << "Choose option to play: " << endl;
                        break;

                    /* Previous page */
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        system("clear");
                        display_PlaylistName(lists_name, currentPage);
                        cout << "Choose option to play: " << endl;
                        break;

                    /* Add Music */
                    case 'A':
                    case 'a':
                        return ADD_MUSIC;
                    
                    /* Remove Music */
                    case 'R':
                    case 'r':
                        return REMOVE_MUSIC;
                    
                    /* Exit */
                    case 'E':
                    case 'e':
                        flag = false;
                        return EXIT_MUSIC;
                    default:
                        system("clear");
                        display_PlaylistName(lists_name,currentPage);
                        cout << "Choose option to play: " << endl;
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            system("clear");
            display_PlaylistName(lists_name,currentPage);
            cout << "Choose option to play: " << endl;
        }
    }
    return 0;
}

/*===============================================================================================*/
//                                SHOW DISPLAY REMOVE SONG IN PLAYLIST 
/*===============================================================================================*/

void PlaylistView::display_PlayNameRemove(const vector<MediaFile*>& plist_name, size_t& currentPage)
{
    playlistName(plist_name,currentPage);
    cout<<setw(15)<<" "<<left << setw(25) << "P. Previous"
          << left << setw(25) << "N. Next"
          << left << setw(25) << "E. Exit" <<"\n"<< endl;
    cout << "======================================================================================================================\n" << endl;
    cout<<"Choose media to Remove: ";
}


/*===============================================================================================*/
//                                SHOW DISPLAY ADĐ SONG TO PLAYLIST 
/*===============================================================================================*/
bool PlaylistView::check_choice_PlaylistName_ADD(const vector<MediaFile*>& lists_name_add,const vector<MediaFile*>& lists_name_compare,int Choice_index)
{
    std::string path_compare = lists_name_compare[Choice_index-1]->getPath();
    for(int i=0;i<(int)lists_name_add.size();i++)
    {
        if(path_compare == lists_name_add[i]->getPath())
        {
            return false;
        }
    }
    return true;
    // return true;
}

int PlaylistView::check_choice_PlaylistName_REMOVE(const vector<MediaFile*>& lists_name, size_t& currentPage){
    string userInput;
    bool flag = true;
    while(flag)
    {   

        getline(cin, userInput);
        if (!userInput.empty()) {
            stringstream ss(userInput);
            size_t MusicChoice;
            if (ss >> MusicChoice)
            {
                if (MusicChoice > 0 && MusicChoice <= lists_name.size())
                {
                    return MusicChoice;
                }
            }
            else
            {
                char command = userInput[0];
                switch (command)
                {
                    /* Next page */
                    case 'N':
                    case 'n':
                        if (currentPage < (lists_name.size() + LIST_NAME_SIZE - 1) / LIST_NAME_SIZE)
                        {
                            currentPage++;
                        }
                        system("clear");
                        display_PlayNameRemove(lists_name, currentPage);

                        break;

                    /* Previous page */
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        system("clear");
                        display_PlayNameRemove(lists_name, currentPage);
                        break;
                    /* Exit */
                    case 'E':
                    case 'e':
                        flag = false;
                        return EXIT_MUSIC;
                    default:
                        system("clear");
                        display_PlayNameRemove(lists_name,currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            system("clear");
            display_PlayNameRemove(lists_name,currentPage);
        }
    }
    return 0;
}

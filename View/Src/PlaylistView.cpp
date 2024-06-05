#include "PlaylistView.hpp"

void PlaylistView::display_Playlist(const vector<Playlist*>& plists, size_t &currentpage){
     system("clear");
     cout << "                                       Playlist                                   " << endl;
     cout << "============================================================================================\n" << endl;
     cout << left << setw(10) << "No."
         << left << setw(40) << "List Name"
         << left << setw(40) << "Number" << endl;

     display_PlaylistPerPage(plists,currentpage);

     cout << "\n============================================================================================" << endl;
     cout<< "Total Media list: "<<plists.size()<<endl;
     cout<< "Page: "<<currentpage<<"\n"<<endl;
     cout <<left << setw(25) << "C. Create"
         << left << setw(25) << "D. Delete"
         << left << setw(25) << "R. Rename"
         << left << setw(25) << "E. Exit\n" << endl;
     cout<<"\n Choose Playlist: "<<endl;
     cout << "\n============================================================================================" << endl;

}

// Ham lay du lieu tu model de truyen du lieu len
void PlaylistView::display_PlaylistPerPage(const vector<Playlist*>& plists, size_t &currentpage) {
    int startIndex = (int(currentpage) - 1) * LIST_SIZE;
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
// void PlaylistView::display_PlaylistName(const vector<MediaFile*>& plist_name, size_t& currentpage) {
//     system("clear");
//     cout << "                                           Playlist name                                   " << endl;
//     cout << "============================================================================================\n" << endl;
//     cout << left << setw(10) << "No."
//          << left << setw(35) << "Name"
//          << left << setw(20) << "Artist"
//          << left << setw(10) << "Duration"
//          << left << setw(20) << "Publisher"<< endl;
    
// }

void PlaylistView::display_PlaylistName(const vector<MediaFile*>&plist_name, size_t &currentpage) {
    cout << "                                                            Play list name                                                " << endl;
    cout << "\n======================================================================================================================\n" << endl;
    std::cout << left << setw(5) << "No."
         << left << setw(40) << "Name"
         << left << setw(30) << "Artist"
         << left << setw(20) << "Duration(s)"
         << left << setw(20) << "Publisher" << endl;

     display_PlaylistNamePerPage(plist_name,currentpage);

     cout << "\n======================================================================================================================\n" << endl;
     cout<< "Total Media list: "<<plist_name.size()<<"\n"<<endl;
     cout<< "Page: "<<currentpage;
     cout<<setw(10)<<" "<<left << setw(25) << "P. Previous"
          << left << setw(25) << "N. Next"
          << left << setw(25) << "E. Exit" <<"\n"<< endl;
     cout<<setw(17)<<" "<<left << setw(25) << "R. Remove"
          << left << setw(25) << "A. Add" << endl;
}

void PlaylistView::display_PlaylistNamePerPage(const vector<MediaFile*>&plist_name, size_t &currentpage) {
    size_t startIndex = (currentpage - 1) * LIST_NAME_SIZE;
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
                        break;

                    /* Add Music */
                    case 'A':
                    case 'a':
                        return -1;
                    
                    /* Remove Music */
                    case 'R':
                    case 'r':
                        return -2;
                    
                    /* Exit */
                    case 'E':
                    case 'e':
                        flag = false;
                        return 0;
                        // break;
                    default:
                        system("clear");
                        display_PlaylistNamePerPage(lists_name,currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            system("clear");
            display_PlaylistNamePerPage(lists_name,currentPage);
        }
    }
}



/*===============================================================================================*/

void PlaylistView::display_PlayNameAdd(vector<MediaFile*>& plist_name, size_t& currentPage)
{
     display_PlaylistName(plist_name,currentPage);
     cout<<"\n Choose media to Add: ";

}
void PlaylistView::display_PlayNameRemove(vector<MediaFile*>& plist_name, size_t& currentPage)
{
     display_PlaylistName(plist_name,currentPage);
     cout<<"\n Choose media to Remove: ";
}

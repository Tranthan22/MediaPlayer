#include "MediaPlayerView.hpp"

#define tableWidth 120

//========================================================================================================================================================//
//                                                                  SHOW PLAYLIST IN  PLAY MUSIC
//========================================================================================================================================================//

void PlayMusicView::display_PlayMucsic(const vector<Playlist*>& plists, size_t& currentpage)
{
    system("clear");
    string header = "Play Music";
    cout<< string(tableWidth , '=')<<endl;
    cout<< string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout<< string(tableWidth, '=')<<endl;
    cout<<"|"<< left << setw(10) << " No."
        <<"|"<< left << setw(tableWidth/3) << "List Name"
        <<"|"<< left << setw(tableWidth/3) << "Number"<<endl;
    cout<< string(tableWidth ,'-')<<"\n"<<endl;

    display_PlaylistPerPage(plists,currentpage);

    cout<<"\n"<<string(tableWidth, '-')<<endl;
    cout << "Total Media list: " << plists.size() << endl;
    cout << "Page: " << currentpage<<endl;
    cout <<string(tableWidth/4, ' ')
         << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit"<< endl;
    cout<<endl;
    cout<< string(tableWidth, '=')<<endl;
}

// ==================================================== CHECK USING FOR SHOW PLAYLIST IN PLAY MUSIC ======================================================//

int PlayMusicView::check_choice_PlayMusicView(const vector<Playlist*>& lists, size_t& currentPage) {
    string userInput;
    bool flag = true;
    while(flag)
    {   
        cout << "\nChoose option to playlist: ";
        getline(cin, userInput);
        if (!userInput.empty()) {
            stringstream ss(userInput);
            size_t ListChoice;
            if (ss >> ListChoice)
            {
                if (ListChoice > 0 && ListChoice <= lists.size())
                {
                    system("clear");
                    return ListChoice;
                }
            }
            else
            {
                char command = userInput[0];
                switch (command)
                {   
                    /*NEXT PAGE*/
                    case 'N':
                    case 'n':
                        if (currentPage < (lists.size() + PLIST_SIZE - 1) / PLIST_SIZE)
                        {
                            currentPage++;
                        }
                        display_PlayMucsic(lists,currentPage);
                        break;
                    /*PREVIOUS PAGE*/
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        display_PlayMucsic(lists,currentPage);
                        break;
                    /*EXIT PAGE*/
                    case 'E':
                    case 'e':
                        flag = false;
                        break;
                    default:
                        display_PlayMucsic(lists,currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            display_PlayMucsic(lists,currentPage);
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    /* RETURN MENU */
    return 0;
}

/*========================================================================================================================================================*/


/*========================================================================================================================================================*/
//                                                          SHOW SONG TO PLAY IN PLAYLIST  <PLAY MUSIC>
/*========================================================================================================================================================*/

void PlayMusicView::display_ShowPlay(const vector<MediaFile*>& lists_name, size_t &currentpage, size_t progressLong, MediaPlayer& myPlayer)
{
    system("clear");
    string header = "Play Music";
    cout<< string(tableWidth , '=')<<endl;
    cout<< string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout<< string(tableWidth, '=')<<endl;
    cout <<"|"<< left << setw(10) << " No."
         <<"|"<< left << setw(tableWidth/3) << "Name"
         <<"|"<< left << setw(tableWidth/4) << "Artist"
         <<"|"<< left << setw(tableWidth/8) << "Duration (s)"
         <<"|"<< left << setw(tableWidth/8) << "Publisher"<<endl;
    cout << string(tableWidth ,'-')<<"\n"<<endl;
    
    display_PlaylistNamePerPage(lists_name,currentpage);
    // ========================================
    string Play_header =".......................................................................";
    cout<< string(tableWidth / 2-Play_header.length()/2, ' ') << Play_header <<endl;
    cout << "Playing: " << myPlayer.getPlayingMusicName() << endl;
    
    Time_Volume(progressLong, myPlayer.getVolume());

    // ========================================
    cout<< string(tableWidth , '=')<<endl;
    cout << "Total Media list: " << lists_name.size() << "\n" << endl;
    cout << "Page: " << currentpage<<endl;
    cout <<string(tableWidth/4, ' ')
         << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit"<< endl;
    cout<<endl;
    cout <<string(tableWidth/4, ' ')
         << left << setw(25) << "U. Up Volume"
         << left << setw(25) << "D. Down Volume"<< endl;
    cout<<endl;
    cout<< string(tableWidth , '=')<<endl;
    cout<< "Choose option to play: " << endl;
}

// ================================================== SHOW CHANGE TIME  - VOLUME - NEXT SONG  - PREVIOUS SONG =========================================== //

void PlayMusicView::Time_Volume(size_t progressLong, const size_t volume) const
{
    // Show time sẽ thay giá trị vào
    cout <<string(tableWidth/4, ' ')<< "Time: "
         << left /*<< setw(80)*/ << "< " << string(progressLong, '#')  << string(50-progressLong, '=') << ">"<<"\n"<<endl;
    cout <<string(tableWidth/4, ' ')<< "Volume: "
            << left << setw(80) << "<" << volume << "% >"<<"\n"<<endl;
    cout <<string(tableWidth/5,' ')
         << left << setw(28) << "<->. Previous song"
         << left << setw(28) << "<R>. Pause/ Resume"
         << left << setw(25) << "<+>. Next song" <<endl;
}

// ================================================== CHECK USING FOR SHOW SONG TO PLAY IN PLAYLIST < PLAY MUSIC >=========================================//

int PlayMusicView::check_choice_PlayMusicView_ShowPlay(const vector<MediaFile*>& lists_name, size_t& currentPage) {
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
                    case 'N':
                    case 'n':
                        if (currentPage < (lists_name.size() + PAGE_SIZE - 1) / PAGE_SIZE)
                        {
                            currentPage++;
                        }
                        // system("clear");
                        // display_ShowPlay(lists_name, currentPage);
                        break;
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        // system("clear");
                        // display_ShowPlay(lists_name, currentPage);
                        break;
                    case 'U':
                    case 'u':
                        return -1;
                    case 'D':
                    case 'd':
                        return -2;
                    case 'R':
                    case 'r':
                        return -3;
                    case '+':
                        return -4;
                    case 'E':
                    case 'e':
                        flag = false;
                        return 0;
                        // break;
                    default:
                        // system("clear");
                        // display_ShowPlay(lists_name,currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            // system("clear");
            // display_ShowPlay(lists_name,currentPage);
        }
    }
    return 0;
}

/*========================================================================================================================================================*/
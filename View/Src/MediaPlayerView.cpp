#include "MediaPlayerView.hpp"


void PlayMusicView::display_PlayMucsic(const vector<Playlist*>& plists, size_t currentpage)
{
    system("clear");
    std::cout << "                                           Play Music                                   " << endl;
    std::cout << "============================================================================================\n" << endl;
    cout << left << setw(10) << "No."
         << left << setw(40) << "List Name"
         << left << setw(40) << "Number" << endl;
    display_PlaylistPerPage(plists,currentpage);
    std::cout << "\n============================================================================================" << endl;
    std::cout << "Total Play list: " << plists.size() << "\n" << endl;
    std::cout << "Page: " << currentpage;
    std::cout << setw(10) << " " << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit" << endl;
    std::cout << "\n============================================================================================" << endl;
}

int PlayMusicView::check_choice_PlayMusicView(const vector<Playlist*>& lists, size_t& currentPage) {
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
                        if (currentPage < (lists.size() + PLIST_SIZE - 1) / PLIST_SIZE)
                        {
                            currentPage++;
                        }
                        system("clear");
                        display_PlayMucsic(lists,currentPage);
                        break;
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        system("clear");
                        display_PlayMucsic(lists,currentPage);
                        break;
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
    return 0;
}

/*Phan để hiển thị sau khi chọn playlist nhé ae */


//Sau khi chọn 1 playlist để thực hiện chạy chương trình 
void PlayMusicView::display_ShowPlay(const vector<MediaFile*>& lists_name, size_t currentpage)
{
    system("clear");
    std::cout << "                                           Play Music                                   " << endl;
    std::cout << "============================================================================================\n" << endl;
    std::cout << left << setw(10) << "No."
         << left << setw(35) << "Name"
         << left << setw(20) << "Artist"
         << left << setw(10) << "Duration"
         << left << setw(20) << "Publisher"<< endl;
    display_PlaylistNamePerPage(lists_name,currentpage);
    // Show time 
    std::cout << left << setw(5) << "\nTime: "
         << left << setw(100) << "< ###############===================================== >"<<endl;
    std::cout << left << setw(5) << "\nVolume: "
            << left << setw(100) << "< 100% >"<<endl;

    std::cout << "\n============================================================================================" << endl;
    std::cout << "Total Media list: " << lists_name.size() << "\n" << endl;
    std::cout << "Page: " << currentpage;
    std::cout << setw(10) << " " << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit" << endl;
    // std::cout << "\nChoose page to show : ";
}

int PlayMusicView::check_choice_PlayMusicView_ShowPlay(const vector<MediaFile*>& lists_name, size_t currentPage) {
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
                    system("clear");
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
                        system("clear");
                        display_ShowPlay(lists_name, currentPage);
                        // display_PlaylistNamePerPage(lists_name,currentPage);
                        // display_MediaFile(songs, currentPage);
                        break;
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        system("clear");
                        display_ShowPlay(lists_name, currentPage);
                        // display_PlaylistNamePerPage(lists_name,currentPage);
                        // display_MediaFile(songs, currentPage);
                        break;
                    case 'E':
                    case 'e':
                        flag = false;
                        break;
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

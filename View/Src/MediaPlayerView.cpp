#include "MediaPlayerView.hpp"


void PlayMusicView::display_PlayMucsic(const vector<Playlist*>& plists, size_t currentpage)
{
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

// void PlayMusicView::display_ListsPerPage(const vector<MediaFile*>& lists, size_t currentpage) {
//     size_t startIndex = (currentpage - 1) * LIST_SIZE;
//     size_t endIndex = min(startIndex + LIST_SIZE, lists.size());
//     for (size_t i = startIndex; i < endIndex; ++i) {
//         std::cout << left << setw(5) << i + 1
//              << left << setw(50) << truncate(lists[i]->getName(), 50)
//              << left << setw(50) << truncate("Last modified", 50)<< endl;
//     }
// }


//Sau khi chọn 1 playlist để thực hiện chạy chương trình 
void PlayMusicView_ShowPlay::display_ShowPlay(const vector<MediaFile*>& lists_name, size_t currentpage)
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

// void PlayMusicView_ShowPlay::display_ShowPlayListsPerPage(const vector<MediaFile*>& songs, size_t currentpage)
// {
//     size_t startIndex = (currentpage - 1) * PAGE_LIST_SIZE;
//     size_t endIndex = min(startIndex + PAGE_LIST_SIZE, songs.size());
//     for (size_t i = startIndex; i < endIndex; ++i) {
//         std::cout << left << setw(5) << i + 1
//              << left << setw(30) << truncate(songs[i]->getName(), 30)
//              << left << setw(25) << truncate("Hellooo", 25)
//              << left << setw(15) << truncate("Hellooo", 15)
//              << left << setw(20) << truncate("Hellooo", 20) << endl;
//     }
// }

void PlayMusicView::check_choice_PlayMusicView(const vector<Playlist*>& lists, size_t& currentPage) {
    string userInput;
    bool flag = true;
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
                    system("clear");
                    display_ShowPlay(lists[ListChoice]->getFiles(),currentPage);
                    // display_MediaFile(songs, currentPage);
                }
            }
            else
            {
                char command = userInput[0];
                switch (command)
                {
                    case 'N':
                    case 'n':
                        if (currentPage < (lists.size() + PAGE_SIZE - 1) / PAGE_SIZE)
                        {
                            currentPage++;
                        }
                        system("clear");
                        display_ShowPlay(lists[ListChoice]->getFiles(),currentPage);
                        // display_MediaFile(songs, currentPage);
                        break;
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        system("clear");
                        display_ShowPlay(lists[ListChoice]->getFiles(),currentPage);
                        // display_MediaFile(songs, currentPage);
                        break;
                    case 'E':
                    case 'e':
                        display_PlayMucsic(lists,currentPage);
                        flag = false;
                        break;
                    default:
                        // system("clear");
                        // display_MediaFile(songs, currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            
        }
    }
}
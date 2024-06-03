#include "MediaPlayerView.hpp"


void PlayMusicView::display_PlayMucsic(const vector<MediaFile*>& lists, size_t currentpage)
{
    std::cout << "                                           Play Music                                   " << endl;
    std::cout << "============================================================================================\n" << endl;
    std::cout << left << setw(5) << "No."
         << left << setw(50) << "List"
         << left << setw(50) << "Last modified" << endl;
    // show playlist  
    display_ListsPerPage(lists, currentpage);
    
    std::cout << "\n============================================================================================" << endl;
    std::cout << "Total Play list: " << lists.size() << "\n" << endl;
    std::cout << "Page: " << currentpage;
    std::cout << setw(10) << " " << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit" << endl;
    std::cout << "\n============================================================================================" << endl;
}

void PlayMusicView::display_ListsPerPage(const vector<MediaFile*>& lists, size_t currentpage) {
    size_t startIndex = (currentpage - 1) * LIST_SIZE;
    size_t endIndex = min(startIndex + LIST_SIZE, lists.size());
    for (size_t i = startIndex; i < endIndex; ++i) {
        std::cout << left << setw(5) << i + 1
             << left << setw(50) << truncate(lists[i]->getName(), 50)
             << left << setw(50) << truncate("Last modified", 50)<< endl;
    }
}

//Sau khi chọn 1 playlist để thực hiện chạy chương trình 
void PlayMusicView_ShowPlay::display_ShowPlay(const vector<MediaFile*>& songs, size_t currentpage)
{
    system("clear");
    std::cout << "                                           Media List                                   " << endl;
    std::cout << "============================================================================================\n" << endl;
    std::cout << left << setw(5) << "No."
         << left << setw(30) << "Name"
         << left << setw(25) << "Artist"
         << left << setw(15) << "Duration"
         << left << setw(20) << "Publisher" << endl;
    // display_ShowPlayListsPerPage(songs, currentpage);
    display_PlaylistNamePerPage(songs,currentpage);
    // Show time 
    std::cout << left << setw(5) << "\nTime: "
         << left << setw(100) << "< ###############===================================== >"<<endl;
    std::cout << left << setw(5) << "\nVolume: "
            << left << setw(100) << "< 100% >"<<endl;

    std::cout << "\n============================================================================================" << endl;
    std::cout << "Total Media list: " << songs.size() << "\n" << endl;
    std::cout << "Page: " << currentpage;
    std::cout << setw(10) << " " << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit" << endl;
    std::cout << "\nChoose page to show : ";
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
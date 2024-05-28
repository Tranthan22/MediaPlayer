#include "../Inc/MediaFileView.hpp"
#include <cstdlib>

void MediaFileView::display_MediaFile()
{
    std::cout << "                                          Media List                                   " << endl;
    cout << "==========================================================================================\n" << endl;
    cout << "No.";
    cout << "\t Name";
    cout << "\t\t\t\t Artist";
    cout << "\t\t Duration";
    cout << "\t\t Publisher \n";
    // in thong tin các bài hat 
}
void MediaFileView::get_Mediafile()
{
    cout<<"deo hieu kieu gi\n";   
    cout << "==========================================================================================\n" << endl;
}
void MediaFileView::choice_page()
{
    cout << "Page: " << MediaFileView::get_page();
    cout << "\t\t P. Previous";
    cout << "\t\t N. Next";
    cout << "\t\t E. Exit\n\n";
}

void MediaFileView::check_choice(const vector<Song>& songs, int page){
    display_MediaFile();
    displaySongsPerPage(songs,page);
    get_Mediafile();
    choice_page();
    cout << "Choose page to show: " ;
    size_t choice;
    do {
        cin >> choice;
        set_choice(choice);
        switch (choice) {
            case 1:
                // mediaList();
                system("clear");
                cout << "hello." << endl;
                break;
            case 2:
                // playlist();
                system("clear");
                cout << "hello." << endl;
                break;
            case 3:
                // playMusic();
                system("clear");
                cout << "hello." << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                cin.ignore(); // Để chờ người dùng nhấn Enter trước khi tiếp tục
                system("clear");
                // cin.get();
                break;
            default:
                system("clear");
                display_MediaFile();
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);
}


// Hàm để hiển thị danh sách bài hát trên một trang
void MediaFileView::displaySongsPerPage(const vector<Song>& songs, int page) {
    int startIndex = (page - 1) * 25;
    int endIndex = min(startIndex + 25, static_cast<int>(songs.size()) - 1);

    // cout << "==========================================================================================" << endl;
    // cout << "No." << setw(10) << "Name" << setw(30) << "Artist" << setw(20) << "Duration" << setw(20) << "Publisher" << endl;
    // cout << "==========================================================================================" << endl;
    for (int i = startIndex; i <= endIndex; ++i) {
        cout << setw(3) << i + 1 << setw(30) << songs[i].name << setw(30) << songs[i].artist << setw(20) << songs[i].duration << setw(20) << songs[i].publisher << endl;
    }
}


int main()
{
    
    vector<Song> songs = {
        {"Song 1", "Artist 1", "3:45", "Publisher 1"},
        {"Song 2", "Artist 2", "4:12", "Publisher 2"},
        {"Song 3", "Artist 3", "2:58", "Publisher 3"},
        {"Song 4", "Artist 4", "5:23", "Publisher 4"},
        {"Song 5", "Artist 5", "3:15", "Publisher 5"},
        {"Song 6", "Artist 6", "4:20", "Publisher 6"},
        {"Song 7", "Artist 7", "3:50", "Publisher 7"},
        {"Song 8", "Artist 8", "4:05", "Publisher 8"},
        {"Song 9", "Artist 9", "3:30", "Publisher 9"},
        {"Song 10", "Artist 10", "3:10", "Publisher 10"},
        // Thêm các bài hát khác vào đây...
        {"Song 11", "Artist 11", "3:00", "Publisher 11"},
        {"Song 12", "Artist 12", "4:40", "Publisher 12"},
        {"Song 13", "Artist 13", "3:55", "Publisher 13"},
        {"Song 14", "Artist 14", "2:45", "Publisher 14"},
        {"Song 15", "Artist 15", "3:20", "Publisher 15"},
        {"Song 16", "Artist 16", "3:35", "Publisher 16"},
        {"Song 17", "Artist 17", "4:15", "Publisher 17"},
        {"Song 18", "Artist 18", "3:25", "Publisher 18"},
        {"Song 19", "Artist 19", "3:48", "Publisher 19"},
        {"Song 20", "Artist 20", "4:02", "Publisher 20"},
        // Thêm các bài hát khác vào đây...
        {"Song 21", "Artist 21", "3:33", "Publisher 21"},
        {"Song 22", "Artist 22", "3:18", "Publisher 22"},
        {"Song 23", "Artist 23", "4:10", "Publisher 23"},
        {"Song 24", "Artist 24", "3:28", "Publisher 24"},
        {"Song 25", "Artist 25", "3:52", "Publisher 25"},
    };

    // Số trang hiện tại
    int currentPage = 1;

    MediaFileView a;
    a.check_choice(songs,currentPage);
    return 0;
}
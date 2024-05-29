<<<<<<< HEAD
#include "main.hpp"
#include "PlaylistController.hpp"


extern Mix_Music *bgm;
std::string musicPath;

int main() {
    
    PlaylistController myPlayer;
    std::vector<char *> mylist;

    mylist.push_back("DungKhoc-ChiDan-11809293.mp3");
    mylist.push_back("DungKhoc-ChiDan-11809293.mp3");
    mylist.push_back("DungKhoc-ChiDan-11809293.mp3");


    myPlayer.nextMusic(mylist);
    std::cout << "playing\n" ;
    int input;
    while(1)
    {
        std::cin >> input;
        if(input == 1)
        {
            myPlayer.VolumeUp();
            std::cout << "up \n" << myPlayer.getVolume() << std::endl;
        }
        else if(input == 2)
        {
            myPlayer.VolumeDown();
            std::cout << "down"  << myPlayer.getVolume() << std::endl;
        }
        else if(input == 0)
        {
            Mix_FreeMusic(bgm);
            std::cout << "exit";
            return 0;
        }
    }
=======
// #include "main.hpp"

// int main(){}
#include <iostream>
#include <iomanip> // Để sử dụng setw()
#include <vector>
#include <string>

using namespace std;

// Struct để biểu diễn một bài hát
struct Song {
    string name;
    string artist;
    string duration;
    string publisher;
};

// Hàm để hiển thị danh sách bài hát trên một trang
void displaySongsPerPage(const vector<Song>& songs, int page) {
    int startIndex = (page - 1) * 25;
    int endIndex = min(startIndex + 25, static_cast<int>(songs.size()) - 1);

    cout << "==========================================================================================" << endl;
    cout << "No." << setw(10) << "Name" << setw(30) << "Artist" << setw(20) << "Duration" << setw(20) << "Publisher" << endl;
    cout << "==========================================================================================" << endl;
    for (int i = startIndex; i <= endIndex; ++i) {
        cout << setw(3) << i + 1 << setw(30) << songs[i].name << setw(30) << songs[i].artist << setw(20) << songs[i].duration << setw(20) << songs[i].publisher << endl;
    }
    cout << "==========================================================================================" << endl;
}

// Hàm để chọn trang
void selectPage(const vector<Song>& songs, int& currentPage) {
    int selectedPage;
    cout << "Choose page to show (0 to cancel): ";
    cin >> selectedPage;

    if (selectedPage >= 1 && selectedPage <= (songs.size() + 9) / 10) {
        currentPage = selectedPage;
        displaySongsPerPage(songs, currentPage);
    } else if (selectedPage == 0) {
        // Cancel
        cout << "Cancelled." << endl;
    } else {
        cout << "Invalid page number. Please enter a valid page." << endl;
    }
}

int main() {
    // Tạo danh sách các bài hát
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

    // Hiển thị các bài hát trên trang đầu tiên
    displaySongsPerPage(songs, currentPage);

    // Lặp cho đến khi người dùng thoát
    char choice;
    do {
        // cout << "Page: " << currentPage << "            P. Previous             N. Next                 E. Exit" << endl;
        // cout << "Choose page to show: "<< endl;
        // // Menu để chọn các tùy chọn hoặc nhập trang cụ thể selectPage(songs, currentPage);

        // Lặp lại menu cho đến khi người dùng thoát
        cout << "===========================================================================================" << endl;
        cout << "Page: " << currentPage << "            P. Previous             N. Next                 E. Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;

        // Xử lý tùy chọn người dùng
        switch (choice) {
            case 'p': // Chọn trang trước
                if (currentPage > 1) {
                    --currentPage;
                    displaySongsPerPage(songs, currentPage);
                } else {
                    cout << "You are already on the first page." << endl;
                }
                break;
            case 'n': // Chọn trang kế tiếp
                if (currentPage < (songs.size() + 9) / 10) {
                    ++currentPage;
                    displaySongsPerPage(songs, currentPage);
                } else {
                    cout << "You are already on the last page." << endl;
                }
                break;
            case 'e': // Thoát
                cout << "Exiting..." << endl;
                break;
            default: // Lựa chọn không hợp lệ
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'e');

    return 0;
>>>>>>> 4cdf59e37bbbc338ed98737762320e6027d4a4de
}
#include "../Inc/MediaFileView.hpp"
#include <cstdlib>

void MediaFileView::display_MediaFile()
{
    std::cout << "                                           Media List                                   " << endl;
    cout << "============================================================================================\n" << endl;
    cout << left << setw(5) << "No."
         << left << setw(30) << "Name"
         << left << setw(25) << "Artist"
         << left << setw(15) << "Duration"
         << left << setw(20) << "Publisher" << endl;
    // in thong tin các bài hat 
}

// Hàm để hiển thị danh sách bài hát trên một trang
void MediaFileView::displaySongsPerPage(const vector<Song>& songs, size_t currentpage) {
    int startIndex = (currentpage - 1) * 25;
    int endIndex = min(startIndex + 25, static_cast<int>(songs.size()) - 1);
    // static_cast<int> chuyen doi sang so int
    for (size_t i = startIndex; i < endIndex; ++i) {
        cout << left << setw(5) << i + 1
             << left << setw(30) << truncate(songs[i].name, 30)
             << left << setw(25) << truncate(songs[i].artist, 20)
             << left << setw(15) << truncate(songs[i].duration, 15)
             << left << setw(20) << truncate(songs[i].publisher, 15) << endl;
    }
    cout << "\n============================================================================================" << endl;
    cout<< "Total Media list: "<<songs.size()<<"\n"<<endl;
    cout<< "Page: "<<currentpage;
    cout<<setw(10)<<" "<<left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit" << endl;
}


void MediaFileView::check_choice(const vector<Song>& songs, size_t& currentPage) {
        string userInput;    
        display_MediaFile();
        displaySongsPerPage(songs, currentPage);
        cout << "\nChoose page to show : ";
    do {    
        getline(cin, userInput);

        if (!userInput.empty()) {
            stringstream ss(userInput);
            size_t pageChoice;
            if (ss >> pageChoice) {
                if (pageChoice > 0 && pageChoice <= (songs.size()/25)+1) {
                    currentPage = pageChoice; // Cập nhật trang hiện tại
                    system("clear");
                    display_MediaFile();
                    displaySongsPerPage(songs, currentPage);
                    cout << "\nChoose page to show : ";
                } else {
                    system("clear");
                    display_MediaFile();
                    displaySongsPerPage(songs, currentPage);
                    cout << "\nChoose page to show : "; 
                    cout << "Invalid page number. Media list number between 1 and " << (songs.size()/25)+1<< "." << endl;
                }
            } else {
                char command = userInput[0];
                switch (command) {
                    case 'N':
                    case 'n':
                    if(currentPage<(songs.size()/25)+1){
                        currentPage++;
                    }
                        system("clear");
                        display_MediaFile();
                        displaySongsPerPage(songs, currentPage);
                        cout << "\nChoose page to show : "; 
                        break;
                    case 'P':
                    case 'p':
                        if (currentPage > 1) {
                            currentPage--;
                        }
                        system("clear");
                        display_MediaFile();
                        displaySongsPerPage(songs, currentPage);
                        cout << "\nChoose page to show : "; 
                        break;
                    case 'E':
                    case 'e':
                        return;
                    default:
                        system("clear");
                        display_MediaFile();
                        displaySongsPerPage(songs, currentPage);
                        cout << "\nChoose page to show : "; 
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        } else {
            system("clear");
            display_MediaFile();
            displaySongsPerPage(songs, currentPage);
            cout << "\nChoose page to show : ";
        }
    } while (true);
}

int main()
{
    
    vector<MediaFileView::Song> songs = {
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
        {"Song 20", "Artisaaaaaaaaaaaaaaaaaaaaaaaaaat 20", "4:02", "Publishaaaaaaaaaaaaaaaaaaaer 20"},
        // Thêm các bài hát khác vào đây...
        {"Song 21", "Artist 21", "3:33", "Publisher 21"},
        {"Song 22", "Artist 22", "3:18", "Publisher 22"},
        {"Song 23", "Artist 23", "4:10", "Publisher 23"},
        {"Song 24", "Artist 24", "3:28", "Publisher 24"},
        {"Song 25", "Artist 25", "3:52", "Publisher 25"},
        {"Song 26", "Artist 21", "3:33", "Publisher 21"},
        {"Song 27", "Artist 22", "3:18", "Publisher 22"},
        {"Song 28", "Artist 23", "4:10", "Publisher 23"},
        {"Song 29", "Artist 24", "3:28", "Publisher 24"},
        {"Song 30", "Artist 25", "3:52", "Publisher 25"},
        {"Song 31", "Artist 21", "3:33", "Publisher 21"},
        {"Song 32", "Artist 22", "3:18", "Publisher 22"},
        {"Song 33", "Artist 23", "4:10", "Publisher 23"},
        {"Song 34", "Artist 24", "3:28", "Publisher 24"},
        {"Song 35", "Artist 25", "3:52", "Publisher 25"},
        {"Song 36", "Artist 21", "3:33", "Publisher 21"},
        {"Song 37", "Artist 22", "3:18", "Publisher 22"},
        {"Song 38", "Artist 23", "4:10", "Publisher 23"},
        {"Song 39", "Artist 24", "3:28", "Publisher 24"},
        {"Song 40", "Artist 25", "3:52", "Publisher 25"},
        {"Song 41", "Artist 21", "3:33", "Publisher 21"},
        {"Song 42", "Artist 22", "3:18", "Publisher 22"},
        {"Song 43", "Artist 23", "4:10", "Publisher 23"},
        {"Song 44", "Artist 24", "3:28", "Publisher 24"},
        {"Song 45", "Artist 25", "3:52", "Publisher 25"},
        {"Song 46", "Artist 21", "3:33", "Publisher 21"},
        {"Song 47", "Artist 22", "3:18", "Publisher 22"},
        {"Song 48", "Artist 23", "4:10", "Publisher 23"},
        {"Song 49", "Artist 24", "3:28", "Publisher 24"},
        {"Song 50", "Artist 25", "3:52", "Publisher 25"},
        {"Song 51", "Artist 21", "3:33", "Publisher 21"},
        {"Song 52", "Artist 22", "3:18", "Publisher 22"},
        {"Song 53", "Artist 23", "4:10", "Publisher 23"},
        {"Song 54", "Artist 24", "3:28", "Publisher 24"},
        {"Song 55", "Artist 25", "3:52", "Publisher 25"},

    };

    // Số trang hiện tại
    size_t currentPage = 1;

    MediaFileView a;
    a.check_choice(songs,currentPage);
    return 0;
}
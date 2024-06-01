#include "../Inc/MediaFileView.hpp"
// #include <cstdlib>
#include <sstream>

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
#include "../Inc/MediaPlayerView.hpp"

void MediaPlayerView::display_MediaPlayer()
{
    cout << "                                         Media Player                                   " << endl;
    cout << "============================================================================================\n\n\n" << endl;
    cout <<setw(70) << "Please, input your media path you want to play"<< endl;\
    cout << "\n\n\n============================================================================================\n" << endl;
    // in thong tin các bài hat 
}
void MediaPlayerView::checkFilesInDirectory(const string& directoryPath) {

    // Kiểm tra xem tệp tồn tại hay không
    std::ifstream file(directoryPath);
    if (file.is_open()) {
        std::cout << "File exists. Opening file..." << std::endl;
        // Thực hiện các hoạt động trên tệp ở đây
        // std::string command = "xdg-open \""+ directoryPath + "\"";
        // std::system(command.c_str());
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            std::cout << "File: " << entry.path() << std::endl;
        } else if (entry.is_directory()) {
            std::cout << "Directory: " << entry.path() << std::endl;
        }
    }
    }
}
        
void MediaPlayerView::Check_path(){
    string userInput;    
    display_MediaPlayer();
    cout << "\nPath : ";
    
    do{
        getline(cin, directoryPath);
        checkFilesInDirectory(directoryPath);
    }while(true);
}





int main()
{
    MediaPlayerView a;
    a.Check_path();
    return 0;
}


// // Hàm để hiển thị danh sách bài hát trên một trang
// void MediaPlayerView::displaySongsPerPage() {
//     int startIndex = (currentpage - 1) * 25;
//     int endIndex = min(startIndex + 25, static_cast<int>(songs.size()) - 1);
//     // static_cast<int> chuyen doi sang so int
//     for (size_t i = startIndex; i < endIndex; ++i) {
//         cout << left << setw(5) << i + 1
//              << left << setw(30) << truncate(songs[i].name, 30)
//              << left << setw(25) << truncate(songs[i].artist, 20)
//              << left << setw(15) << truncate(songs[i].duration, 15)
//              << left << setw(20) << truncate(songs[i].publisher, 15) << endl;
//     }
//     cout << "\n============================================================================================" << endl;
//     cout<< "Total Media list: "<<songs.size()<<"\n"<<endl;
//     cout<< "Page: "<<currentpage;
//     cout<<setw(10)<<" "<<left << setw(25) << "P. Previous"
//          << left << setw(25) << "N. Next"
//          << left << setw(25) << "E. Exit" << endl;
// }


// void MediaPlayerView::check_choice() {
    //     string userInput;    
    //     display_MediaFile();
    //     displaySongsPerPage(songs, currentPage);
    //     cout << "\nChoose page to show : ";
    // do {    
    //     getline(cin, userInput);

    //     if (!userInput.empty()) {
    //         stringstream ss(userInput);
    //         size_t pageChoice;
    //         if (ss >> pageChoice) {
    //             if (pageChoice > 0 && pageChoice <= (songs.size()/25)+1) {
    //                 currentPage = pageChoice; // Cập nhật trang hiện tại
    //                 system("clear");
    //                 display_MediaFile();
    //                 displaySongsPerPage(songs, currentPage);
    //                 cout << "\nChoose page to show : ";
    //             } else {
    //                 system("clear");
    //                 display_MediaFile();
    //                 displaySongsPerPage(songs, currentPage);
    //                 cout << "\nChoose page to show : "; 
    //                 cout << "Invalid page number. Media list number between 1 and " << (songs.size()/25)+1<< "." << endl;
    //             }
    //         } else {
    //             char command = userInput[0];
    //             switch (command) {
    //                 case 'N':
    //                 case 'n':
    //                 if(currentPage<(songs.size()/25)+1){
    //                     currentPage++;
    //                 }
    //                     system("clear");
    //                     display_MediaFile();
    //                     displaySongsPerPage(songs, currentPage);
    //                     cout << "\nChoose page to show : "; 
    //                     break;
    //                 case 'P':
    //                 case 'p':
    //                     if (currentPage > 1) {
    //                         currentPage--;
    //                     }
    //                     system("clear");
    //                     display_MediaFile();
    //                     displaySongsPerPage(songs, currentPage);
    //                     cout << "\nChoose page to show : "; 
    //                     break;
    //                 case 'E':
    //                 case 'e':
    //                     return;
    //                 default:
    //                     system("clear");
    //                     display_MediaFile();
    //                     displaySongsPerPage(songs, currentPage);
    //                     cout << "\nChoose page to show : "; 
    //                     cout << "Invalid choice. Please enter a valid option." << endl;
    //             }
    //         }
    //     } else {
    //         system("clear");
    //         display_MediaFile();
    //         displaySongsPerPage(songs, currentPage);
    //         cout << "\nChoose page to show : ";
    //     }
    // } while (true);
// }

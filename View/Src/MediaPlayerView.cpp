#include "MediaPlayerView.hpp"


void MediaPlayerView::display_MediaPlayer()
{
    cout << "                                         Media Player                                   " << endl;
    cout << "============================================================================================\n\n\n" << endl;
    cout <<setw(70) << "Please, input your media path you want to play"<< endl;\
    cout << "\n\n\n============================================================================================\n" << endl;
    // in thong tin các bài hat 

}
void MediaPlayerView::checkFilesInDirectory(ViewInteract &ViewInteract, string& directoryPath) {

    // Kiểm tra xem tệp tồn tại hay không
    std::ifstream file(directoryPath);
    if (file.is_open()) {
        std::cout << "File exists. Opening file..." << std::endl;
        ViewInteract.setPath(directoryPath);
    }else{
        std::cout << "Error input path...Try Again" << std::endl;
    }
}
// Ham de su tung trang lay du lieu 
void MediaPlayerView::input_path(ViewInteract &ViewInteract){
    display_MediaPlayer();
    cout << "\nPath : ";
    while(true)
    {
        getline(cin, directoryPath);
        checkFilesInDirectory(ViewInteract,directoryPath);
        break;
    }
}

//    for (const auto& entry : fs::directory_iterator(directoryPath)) {
//             if (entry.is_regular_file()) {
//                 std::cout << "File: " << entry.path() << std::endl;
//             } else if (entry.is_directory()) {
//                 std::cout << "Directory: " << entry.path() << std::endl;
//             }
//         }

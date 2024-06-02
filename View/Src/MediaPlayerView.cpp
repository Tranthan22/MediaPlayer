#include "MediaPlayerView.hpp"


void MediaPlayerView::display_MediaPlayer()
{
    cout << "                                         Media Player                                   " << endl;
    cout << "============================================================================================\n\n\n" << endl;
    cout <<setw(70) << "Please, input your media path you want to play"<< endl;\
    cout << "\n\n\n============================================================================================\n" << endl;
}


// Ham de su tung trang lay du lieu 
std::string MediaPlayerView::input_path(){
    display_MediaPlayer();
    cout << "\nPath : ";
    string directoryPath;
    getline(cin, directoryPath);
    return directoryPath;
}





// bool MediaPlayerView::checkFilesInDirectory(const string& directoryPath) const {
//     // Kiểm tra xem tệp tồn tại hay không
//     std::ifstream file(directoryPath);
//     if (file.is_open()) {
//         return true;
//     }else{
//         return false;
//     }
// }
// // Ham de su tung trang lay du lieu 
// std::string MediaPlayerView::input_path(){
//     display_MediaPlayer();
//     cout << "\nPath : ";
//     string directoryPath;
//     while(true)
//     {
        
//         getline(cin, directoryPath);
//         if(checkFilesInDirectory(directoryPath))
//         {
//             std::cout << "File exists. Opening file..." << std::endl;
//             break;
//         }
//         else{
//             std::cout << "Error input path...Try Again" << std::endl;
//         }
//     }
//     return directoryPath;
// }

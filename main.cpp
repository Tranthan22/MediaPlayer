#include "main.hpp"
#include "Browser.hpp"
int main()
{
    Browser myBrowser;
    myBrowser.programFlow();
    return 0;
}
// #include <iostream>
// #include <thread>
// #include <chrono>

// void displayMessage() {
//     std::string messages[] = {"Original Text", "Updated Text"};
//     int index = 0;

//     while (true) {
//         // Di chuyển con trỏ về đầu dòng và xóa dòng hiện tại
//         system("clear");
//         std::cout << "\r\033[K" << messages[index] << std::flush<<std::endl;
//         std::cout << "\r\033[K" << messages[index] << std::flush<<std::endl;
//         std::cout << "\r\033[K" << messages[index] << std::flush<<std::endl;
//         std::cout << "\r\033[K" << messages[index] << std::flush<<std::endl;
//         std::cout << "\r\033[K" << messages[index] << std::flush<<std::endl;
//         std::cout << "\r\033[K" << messages[index] << std::flush<<std::endl;
//         std::cout << "\r\033[K" << messages[index] << std::flush<<std::endl;
//         std::cout << "\r\033[K" << messages[index] << std::flush<<std::endl;

//         // Chuyển đổi giữa các thông điệp
//         index = (index + 1) % 2;

//         // Chờ 1 giây trước khi cập nhật lại
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }
// }

// int main() {
//     std::thread displayThread(displayMessage);

//     // Đảm bảo chương trình không kết thúc ngay lập tức
//     displayThread.join();

//     return 0;
// }

#include "main.hpp"
#include "Browser.hpp"


int main()
{
    // Thiết lập môi trường mã hóa UTF-8
    std::setlocale(LC_ALL, "");
    Browser myBrowser;
    myBrowser.programFlow();
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <string>
// #include <filesystem>
// #include <cstdlib>
// #include <ctime>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_mixer.h>
// #include <taglib/fileref.h>
// #include <taglib/tag.h>
// #include <taglib/tpropertymap.h>
// #include <atomic>
// #include <thread>
// #include <chrono>
// #include <sstream>
// #include <iomanip>

// namespace fs = std::filesystem;

// std::string format_time(int total_seconds) {
//     int hours = total_seconds / 3600;
//     int minutes = (total_seconds % 3600) / 60;
//     int seconds = total_seconds % 60;
//     std::stringstream ss;
//     ss << std::setfill('0') << std::setw(2) << hours << ":"
//        << std::setfill('0') << std::setw(2) << minutes << ":"
//        << std::setfill('0') << std::setw(2) << seconds;
//     return ss.str();
// }

// void countup_timer(int target_time, std::atomic<int>& current_time) {
//     current_time = 0;
//     while (current_time <= target_time) {
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         current_time++;
//         std::cout << "\rTime elapsed: " << format_time(current_time) << std::flush;
//     }
//     std::cout << "\nSong duration reached!\n";
// }

// // Hàm phát một bài hát cụ thể
// void play_song(const std::string& music_path, bool loop = false) {
//     do {
//         // Khởi tạo SDL2_mixer
//         if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
//             std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
//             return;
//         }

//         // Kiểm tra tệp nhạc và tag
//         TagLib::FileRef file(music_path.c_str());
//         if (file.isNull() || !file.tag()) {
//             std::cerr << "Error: Could not open file or file has no tags." << std::endl;
//             return;
//         }

//         // Lấy thông tin về bài hát từ tag
//         TagLib::Tag *tag = file.tag();
//         std::string title = tag->title().toCString(true);
//         std::string artist = tag->artist().toCString(true);
//         std::string album = tag->album().toCString(true);
//         int duration = file.audioProperties() ? file.audioProperties()->length() : 0;

//         if (duration == 0) {
//             std::cerr << "Error: Could not determine the duration of the song." << std::endl;
//             return;
//         }

//         // Hiển thị thông tin về bài hát
//         std::cout << "Now playing: " << title << "\n";
//         std::cout << "Artist: " << artist << "\n";
//         std::cout << "Album: " << album << "\n";
//         std::cout << "Duration: " << format_time(duration) << "\n";

//         // Bắt đầu countup timer
//         std::atomic<int> current_time(0);
//         std::thread timer_thread(countup_timer, duration, std::ref(current_time));

//         // Phát nhạc
//         Mix_Music* music = Mix_LoadMUS(music_path.c_str());
//         if (music == NULL) {
//             std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
//             return;
//         }
//         Mix_PlayMusic(music, 1);
//     // Chờ đợi kết thúc bài hát
//         SDL_Delay(duration * 1000);

//         // Giải phóng bộ nhớ và dừng countup timer
//         Mix_FreeMusic(music);
//         Mix_CloseAudio();
//         timer_thread.join();
//     } while (loo
    
//     p);
// }

// //Ham phat danh sach nhac lien tuc
// void play_playlist(const std::vector<std::string>& playlist) {
//     while (true) {  // Vòng lặp để phát liên tục
//         for (const auto& music_path : playlist) {
//             play_song(music_path);
//         }
//     }
// }


// // Hàm phát danh sách nhạc ngẫu nhiên
// void play_random(const std::vector<std::string>& playlist) {
//     std::srand(std::time(nullptr)); // Khởi tạo seed ngẫu nhiên
//     while (true) {
//         int random_index = std::rand() % playlist.size();
//         play_song(playlist[random_index]);
//     }
// }

// int main() {
//     std::vector<std::string> music_list;

//     int choice;
//     std::string song_path; // Di chuyển ra ngoài switch case
//     std::cout << "Choose an option:\n";
//     std::cout << "1. Play all songs in folder\n";
//     std::cout << "2. Play songs randomly\n";
//     std::cout << "3. Play one song\n";
//     std::cin >> choice;

//     switch (choice) {
//         case 1:
//             {
//                 std::string folder_path;
//                 std::cout << "Enter folder path: ";
//                 std::cin >> folder_path;
//                 for (const auto& entry : fs::directory_iterator(folder_path)) {
//                     if (entry.path().extension() == ".mp3") {
//                         music_list.push_back(entry.path().string());
//                     }
//                 }
//                 play_playlist(music_list);
//             }
//             break;
//         case 2:
//             {
//                 std::string folder_path;
//                 std::cout << "Enter folder path: ";
//                 std::cin >> folder_path;
//                 for (const auto& entry : fs::directory_iterator(folder_path)) {
//                     if (entry.path().extension() == ".mp3") {
//                         music_list.push_back(entry.path().string());
//                     }
//                 }
//                 play_random(music_list);
//             }
//             break;
//         case 3:
//             std::cout << "Enter the path of the song: ";
//             std::cin >> song_path;
//             play_song(song_path, true); // Sử dụng loop = true để phát liên tục
//             break;
//         case 0:
//             break;
//         default:
//             std::cout << "Invalid choice\n";
//             break;
//     }

//     return 0;
// }



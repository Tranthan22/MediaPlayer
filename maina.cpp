#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <cstdio>

int main(int argc, char* argv[]) {
    // Khởi tạo SDL và SDL_mixer
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio failed: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Trích xuất âm thanh từ tệp video MP4 bằng FFmpeg
    // /home/dungdt55/MediaPlayer/Music/ViConLaNguoiTotLyricVideo-gung0cayIndieK-10699062.mp4
    std::string command =  "ffmpeg -i ViConLaNguoiTotLyricVideo-gung0cayIndieK-10699062.mp4 -vn -acodec pcm_s16le -ar 44100 -ac 2 output.wav";
    // std::string command = "ffmpeg -i /home/dungdt55/MediaPlayer/Music/ComeBackToMe-LinhBuziNhunggg-8853785.mp4 -vn -acodec pcm_s16le -ar 44100 -ac 2 output.mp3";
    std::system(command.c_str());

    // Load và phát âm thanh đã trích xuất bằng SDL2_mixer
    Mix_Music *music = Mix_LoadMUS("output.wav");
    if (!music) {
        std::cerr << "Mix_LoadMUS failed: " << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }
    if (Mix_PlayMusic(music, -1) < 0) {
        std::cerr << "Mix_PlayMusic failed: " << Mix_GetError() << std::endl;
        Mix_FreeMusic(music);
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    // Chờ người dùng nhấn một phím để kết thúc chương trình
    std::cout << "Press any key to quit..." << std::endl;
    std::cin.get();

    // Giải phóng tài nguyên và thoát
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}
// #include "../Controller/Inc/PlaylistController.hpp"
#include "PlaylistController.hpp"
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

Mix_Music *bgm;


PlaylistController::PlaylistController(/* args */)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }

    // Khởi tạo SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        SDL_Quit();
    }
}

PlaylistController::~PlaylistController()
{
    Mix_CloseAudio();
    SDL_Quit();
}

int PlaylistController::playMusic(const char* file)
{
    bgm = Mix_LoadMUS(file);
    if (bgm == NULL) {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
        return -1;
    }

    // Phát nhạc
    if (Mix_PlayMusic(bgm, -1) == -1) {  // -1 để lặp lại vô hạn
        std::cerr << "Failed to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        Mix_FreeMusic(bgm);
        Mix_CloseAudio();
        SDL_Quit();
        return -1;
    }

    // std::cout << "Press Enter to stop the music and quit..." << std::endl;
    // std::cin.get();
    // Mix_FreeMusic(bgm);
    
    return 0;
}

void PlaylistController:: pauseMusic()
{
    Mix_HaltMusic();
}

void PlaylistController:: nextMusic(std::vector<char*>& list)
{
    static size_t fileIndexInList = 0;
    fileIndexInList++;
    pauseMusic();
    playMusic(list[fileIndexInList]);
}

int PlaylistController:: getVolume()
{
    return SysVolume;
}
int PlaylistController:: VolumeUp()
{
    if(SysVolume > 123)
    {
        SysVolume = 128;
    }
    else
    {
        SysVolume += 5;
    }
    Mix_VolumeMusic(SysVolume);
    return SysVolume;
}

int PlaylistController:: VolumeDown()
{
    if(SysVolume < 5)
    {
        SysVolume = 0;
    }
    else
    {
        SysVolume -= 5;
    }
    Mix_VolumeMusic(SysVolume);
    return SysVolume;
}
vector<MediaFile *> PlaylistController::getMediaFiles()
{
    return mediaFiles;
}
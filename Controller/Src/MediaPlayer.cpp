#include "MediaPlayer.hpp"
#include <iostream>

Mix_Music *bgm;
bool MediaPlayer::Playing = false;
size_t MediaPlayer::fileIndexInList;

MediaPlayer::MediaPlayer(/* args */)
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

MediaPlayer::~MediaPlayer()
{
    Mix_CloseAudio();
    SDL_Quit();
}

int MediaPlayer::playMusic(const char* file)
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

    Playing = true;
    

    // std::cout << "Press Enter to stop the music and quit..." << std::endl;
    // std::cin.get();
    // Mix_FreeMusic(bgm);
    
    return 0;
}

void MediaPlayer:: ResumePause()
{
    if(Playing == true)
    {
        Mix_PauseMusic();
        Playing = false;
    }
    else
    {
        Mix_ResumeMusic();
        Playing = true;
    }
}

void MediaPlayer:: nextMusic()
{
    Mix_HaltMusic();
    playMusic((*list)[fileIndexInList]);

    if(++fileIndexInList > list->size()-1)
    {
        fileIndexInList = 0;
    }
    else
    {
        /**/
    }
    
}
void MediaPlayer::setList(std::vector<char*> *list)
{
    this->list = list;
}


/*================ Volume ================== */
int MediaPlayer:: getVolume()
{
    return SysVolume;
}
int MediaPlayer:: VolumeUp()
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

int MediaPlayer:: VolumeDown()
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
vector<MediaFile *> MediaPlayer::getMediaFiles()
{
    vector<MediaFile *> a;
    return a;
    // return mediaFiles;
}
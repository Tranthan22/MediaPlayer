#include "MediaPlayer.hpp"
#include <iostream>


bool MediaPlayer::Playing = false;
size_t MediaPlayer::fileIndexInList = 0;

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
    // if(bgm != NULL)
    // {
    //     Mix_FreeMusic(bgm);
    // }
    // Mix_CloseAudio();
    // SDL_Quit();
}
/*=================== Media Player =========================*/
int MediaPlayer::playMusic(/*const char* file*/)
{
    // char *file = 
    bgm = Mix_LoadMUS((*list)[fileIndexInList]->getPath().c_str());
    if (bgm == NULL)
    {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
        return -1;
    }
    else
    {
        // Phát nhạc
        if (Mix_PlayMusic(bgm, -1) == -1)
        {  // -1 để lặp lại vô hạn
            std::cerr << "Failed to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
            Mix_FreeMusic(bgm);
            Mix_CloseAudio();
            SDL_Quit();
            return -1;
        }
        else
        {
            Playing = true;
        }
    }
    // startStatusUpdate();
    return 0;
}

void MediaPlayer:: ResumePause()
{
    // Playing != Playing;
    if(Playing == true)
    {
        Playing = false;
    }
    else
    {
        Playing = true;
    }
}

void MediaPlayer:: nextMusic()
{
    // string MusicDir="";
    Mix_HaltMusic();
    if(++fileIndexInList > list->size()-1)
    {
        fileIndexInList = 0;
        // MusicDir = (*list)[fileIndexInList]->getPath();
        // playMusic(MusicDir.c_str());
    }
    else
    {
        /**/
        // MusicDir = (*list)[fileIndexInList]->getPath();
        // playMusic(MusicDir.c_str());
    }
    // string MusicDir = (*list)[fileIndexInList]->getPath();
    playMusic(/*MusicDir.c_str()*/);
    
}
void MediaPlayer:: preMusic()
{
    // string MusicDir="";
    Mix_HaltMusic();
    if(--fileIndexInList < 0)
    {
        fileIndexInList = list->size()-1;
    }
    else
    {
        
    }
    playMusic();
}

void MediaPlayer::setList(std::vector<MediaFile*> *list)
{
    this->list = list;
}
void MediaPlayer::setIndexInList(size_t index)
{
    fileIndexInList = index - 1;
}

string MediaPlayer::getPlayingMusicName()
{
    return (*list)[fileIndexInList]->getName();
}
string MediaPlayer::getPlayingMusicPath()
{
    return (*list)[fileIndexInList]->getPath();
}
bool MediaPlayer::isPlaying()
{
    return Playing;
}

/*================ Volume ================== */
size_t MediaPlayer:: getVolume()
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
void MediaPlayer::Exit_play()
{
    // Mix_CloseAudio();
    // Em làm mà nó đéo chạy sếp chạy thì nhớ thêm vào nhé
    Mix_CloseAudio();
    SDL_Quit();
}


// void MediaPlayer::updateStatus() {
//     while (isPlaying) {
//         {
//             std::lock_guard<std::mutex> lock(mtx);
//             // Update time and volume display logic
//             size_t duration = 180; // Example duration
//             size_t current = Mix_PlayingMusic() ? getMusicPosition() : 0;
//             // size_t current = 0;

//             // size_t volume = Mix_VolumeMusic(-1) * 100 / MIX_MAX_VOLUME;
//             size_t volume = 50;

//             // Call the method to display current status
//             mediaPlayerView.Time_Volume(duration, current, volume);
//         }
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }
// }
// void MediaPlayer::startStatusUpdate() {
//     isPlaying = true;
//     updateThread = std::thread(&MediaPlayer::updateStatus, this);
// }
// void MediaPlayer::stopStatusUpdate() {
//     isPlaying = false;
//     if (updateThread.joinable()) {
//         updateThread.join();
//     }
// }
// double MediaPlayer::getMusicPosition() {
//     if (isMusicPlaying) {
//         auto currentTime = std::chrono::steady_clock::now();
//         std::chrono::duration<double> elapsedSeconds = currentTime - startTime;
//         return elapsedSeconds.count();
//     }
//     return 0.0;
// }

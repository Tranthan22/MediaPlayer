#include "MediaPlayer.hpp"

bool MediaPlayer::Playing = false;
int MediaPlayer::fileIndexInList = 0;
bool MediaPlayer::checkInitSDL =true;

MediaPlayer::MediaPlayer(/* args */)
{
    InitSDL();
}

MediaPlayer::~MediaPlayer()
{
    ExitAudio();
}
/*=================== Media Player =========================*/

void MediaPlayer::InitSDL()
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

void MediaPlayer::ExitAudio()
{
    Mix_CloseAudio();
    SDL_Quit();
    checkInitSDL=false;
}

int MediaPlayer::playMusic(/*const char* file*/)
{

    if(!checkInitSDL)
    {
        InitSDL();
        checkInitSDL = true;
    }
    // char *file = 
    if((*list)[fileIndexInList]->getType()== 1)
    {
        bgm = Mix_LoadMUS((*list)[fileIndexInList]->getPath().c_str());
    }
    // Trích xuất âm thanh từ tệp video MP4 bằng FFmpeg
    else{
        std::string name_song = (*list)[fileIndexInList]->getPath();
        std::string command =  "ffmpeg -y -i "+ name_song +" -vn -acodec pcm_s16le -ar 44100 -ac 2 Music/output.wav";
        std::system(command.c_str());
        // Load và phát âm thanh đã trích xuất bằng SDL2_mixer
        bgm = Mix_LoadMUS("Music/output.wav");
    }
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
    std::lock_guard<std::mutex> lock(counter_mutex);
    if(++fileIndexInList > (int)(list->size()-1))
    {
        fileIndexInList = 0;
    }
    else
    {
        /**/
    }

    playMusic(/*MusicDir.c_str()*/);
}

void MediaPlayer:: preMusic()
{
    // string MusicDir="";
    Mix_HaltMusic();
    std::lock_guard<std::mutex> lock(counter_mutex);
    if(--fileIndexInList < 0)
    {
        fileIndexInList = list->size()-1;
    }
    else
    {
        
    }
    playMusic();
}

void MediaPlayer::autoMusic()
{
    if(flagAuto)
    {
        nextMusic();
    }else{
        /**/
    }
}
void MediaPlayer::setFlagAuto(bool flagAuto)
{
    this->flagAuto =flagAuto;
}
bool MediaPlayer::getFlagAuto()
{
    return flagAuto;
}
void MediaPlayer::setList(std::vector<MediaFile*> *_list)
{
    list = _list;
}
void MediaPlayer::setIndexInList(int index)
{
    fileIndexInList = index - 1;
}

string MediaPlayer::getPlayingMusicName()
{
    return (*list)[fileIndexInList]->getName();
}
string MediaPlayer::getPlayingMusicPath()
{
    if(fileIndexInList > (int)(*list).size() - 1)
    {
        return "";
    }
    else
    {
        return (*list)[fileIndexInList]->getPath();
    }
}

bool MediaPlayer::isPlaying()
{
    return Playing;
}

/*================ Change Volume ================== */
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
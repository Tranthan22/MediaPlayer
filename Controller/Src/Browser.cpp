#include "Browser.hpp"

Browser::Browser(/* args */)
{
}

Browser::~Browser()
{
    for(MediaFile* mediafile : vMediaFile)
    {
        delete mediafile;
    }
}

void Browser::setPath()
{
    do
    {
        Path = mediaPlayerView.input_path();
    }
    while(!(fs::exists(Path) && fs::is_directory(Path)));
}
int Browser::userInput()
{
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}
void Browser::menu()
{
    menuView.display_menu();
    // switch(choice)
    // {
    //     case 1:
    //         medialist();
    //         break;
    //     case 2:
    //         break;
    //     case 3:
    //         system("clear");
    //         playmusic();
    //         break;
    //     case 0:
    //         break;
    //     default:
    //         break;
    // }
}
void Browser::loadFile()
{
    for (const auto& entry : fs::directory_iterator(Path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".mp3")
        {
            vMediaFile.push_back(new MediaFile(entry.path().filename().string(), entry.path().string()));
        }
    }
}

void Browser::medialist()
{
    mediaFileView.display_MediaFile(vMediaFile, 1);
}

void Browser::playmusic()
{
    myPlayer.setList(&vMediaFile);
    myPlayer.nextMusic();
    int input;
    while(1)
    {
        std::cin >> input;
        switch (input)
        {
        case 0:
            std::cout << "exit";
            break;
        case 1:
            myPlayer.VolumeUp();
            std::cout << "up \n" << myPlayer.getVolume() << std::endl;
            break;

        case 2:
            myPlayer.VolumeDown();
            std::cout << "down"  << myPlayer.getVolume() << std::endl;
            break;

        case 3:
            Mix_PauseMusic();
            std::cout << "Pause"  << std::endl;
            break;
        
        case 4:
            Mix_ResumeMusic();
            std::cout << "Resume"  << std::endl;
            break;

        case 5:
            Mix_HaltMusic();
            std::cout << "Halt"  << std::endl;
            break;
        case 6:
            Mix_PlayMusic(myPlayer.bgm, -1);
            std::cout << "Again"  << std::endl;
            break;
        case 7:
            myPlayer.ResumePause();
            std::cout << "Switch state"  << std::endl;
            break;

        case 8:
            myPlayer.nextMusic();
            std::cout << "Next "  << std::endl;
            break;

        default:
            break;
        }
    }
}
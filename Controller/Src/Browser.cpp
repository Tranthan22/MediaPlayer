#include "Browser.hpp"
#include <stack>

#define START_PAGE 1

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
        Path = mediaPathView.input_path();
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
    int MenuInput = userInput();
    switch (MenuInput)
    {
    case MEDIA_LIST:
        medialist();
        break;
    case PLAY_LIST:
        
        break;
    case PLAY_MUSIC:
        playmusic();
    
    default:
        break;
    }
}
void Browser::loadFile()
{
    for (const auto& entry : fs::directory_iterator(Path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".mp3")
        {   
            int mp3_type =1;
            vMediaFile.push_back(new MediaFile(entry.path().filename().string(), entry.path().string(),mp3_type));
        }
    }
}

void Browser::medialist()
{
    size_t currentPage=START_PAGE;
    int choose_song;
    int user_input;
    mediaFileView.display_MediaFile(vMediaFile, currentPage);
    mediaFileView.check_choice(vMediaFile, currentPage);
    choose_song = mediaFileView.getChoice();
    while(true)
    { 
        user_input =userInput();
        switch (user_input)
        {
        case SHOW_METADATA:
            system("clear");
            metaData.viewMetadata(vMediaFile,choose_song);
            cout << "Input your command: " << endl;
            user_input=userInput();
            if(user_input==BACK_MENU)
                medialist();
            break;
        case UPDATE_METADATA:
            system("clear");
            metaData.updateMetadata(vMediaFile,choose_song);
            user_input=userInput();
            if(user_input==BACK_MENU)
                medialist();
            break;
        case BACK_MENU:
            system("clear");
            medialist();
            break;
        default:
            break;
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
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

vector<MediaFile *> Browser::getMediaFiles()
{
    return vMediaFile;
}
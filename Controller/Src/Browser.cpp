#include "Browser.hpp"
#include <stack>


Browser::Browser(/* args */)
{
}

Browser::~Browser()
{
    for(MediaFile* mediafile : vPlayList[0]->getPlaylist())
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
        flowID.push(MEDIA_LIST_ID);
        break;
    case PLAY_LIST:
        flowID.push(PLAY_LIST_ID);
        break;
    case PLAY_MUSIC:
        flowID.push(PLAY_MUSIC_ID);
        break;
    default:
        break;
    }
}
void Browser::loadFile()
{
    vPlayList.push_back(new Playlist("All"));
    for (const auto& entry : fs::directory_iterator(Path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".mp3"){
            int mp3_type =1;
            vPlayList[0]->addFile(new MediaFile(entry.path().filename().string(), entry.path().string(),mp3_type));
        }
    }
}

void Browser::medialist()
{
    size_t currentPage=START_PAGE;
    int choose_song;
    int user_input;
    mediaFileView.display_MediaFile(vPlayList[0]->getPlaylist(), currentPage);
    mediaFileView.check_choice(vPlayList[0]->getPlaylist(), currentPage);
    choose_song = mediaFileView.getChoice();
    while(true)
    { 
        user_input =userInput();
        switch (user_input)
        {
        case SHOW_METADATA:
            system("clear");
            metaData.viewMetadata(vPlayList[0]->getPlaylist(),choose_song);
            cout << "Input your command: " << endl;
            user_input=userInput();
            if(user_input==BACK_MENU)
                medialist();
            break;
        case UPDATE_METADATA:
            system("clear");
            metaData.updateMetadata(vPlayList[0]->getPlaylist(),choose_song);
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
    flowID.pop();
}

void Browser::playmusic()
{
    size_t currentPage = 1;
    int chosenList = 0;
    int chosenMusic = 0;
    bool flag = true;
    while(flag)
    {
        mediaPlayerView.display_PlayMucsic(vPlayList, currentPage);
        chosenList = mediaPlayerView.check_choice_PlayMusicView(vPlayList, currentPage);
        if(chosenList != 0)
        {
            while(1)
            {
                mediaPlayerView.display_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), 1);
                chosenMusic = mediaPlayerView.check_choice_PlayMusicView_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), 1);
                system("clear");

                cout << "aaaaaa";
                cout << "chosenMusic:" << chosenMusic;
                
                switch (chosenMusic)
                {
                case 0:
                    break;
                case -1:

                default:
                    vector<MediaFile*> *a = vPlayList[chosenList - 1]->getPlaylistPointer();
                    MediaFile * b = (*a)[chosenMusic];
                    myPlayer.playMusic(b->getName().c_str());
                }
            }
        }
        else
        {
            flowID.pop();
            flag = false;
        }
    }

    // myPlayer.setList(vPlayList[0]->getPlaylistPointer());
    // myPlayer.nextMusic();

    // int input;
    // while(1)
    // {
    //     std::cin >> input;
    //     switch (input)
    //     {
    //     case 0:
    //         std::cout << "exit";
    //         break;
    //     case 1:
    //         myPlayer.VolumeUp();
    //         std::cout << "up \n" << myPlayer.getVolume() << std::endl;
    //         break;

    //     case 2:
    //         myPlayer.VolumeDown();
    //         std::cout << "down"  << myPlayer.getVolume() << std::endl;
    //         break;

    //     case 3:
    //         Mix_PauseMusic();
    //         std::cout << "Pause"  << std::endl;
    //         break;
        
    //     case 4:
    //         Mix_ResumeMusic();
    //         std::cout << "Resume"  << std::endl;
    //         break;

    //     case 5:
    //         Mix_HaltMusic();
    //         std::cout << "Halt"  << std::endl;
    //         break;
    //     case 6:
    //         Mix_PlayMusic(myPlayer.bgm, -1);
    //         std::cout << "Again"  << std::endl;
    //         break;
    //     case 7:
    //         myPlayer.ResumePause();
    //         std::cout << "Switch state"  << std::endl;
    //         break;

    //     case 8:
    //         myPlayer.nextMusic();
    //         std::cout << "Next "  << std::endl;
    //         break;

    //     default:
    //         break;
    //     }
    // }
}

void Browser::programFlow()
{
    setPath();
    loadFile();
    flowID.push(MENU_ID); // Menu
    int current_screen;
    while(1)
    {
        current_screen = flowID.top();
        switch(current_screen)
        {
            case MENU_ID:
                menu();
                break;
            case MEDIA_LIST_ID:
                medialist();
                break;
            case PLAY_LIST_ID:
                break;
            case PLAY_MUSIC_ID:
                playmusic();
                // cin.ignore();
                break;
        }
    }
}

vector<MediaFile *> Browser::getMediaFiles()
{
    // return vPlayList[0];
}
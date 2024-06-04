#include "Browser.hpp"
#include <stack>

#define START_PAGE 1

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
    bool flag = true;
    int choose_song;
    int user_input;
    mediaFileView.display_MediaFile(vPlayList[0]->getPlaylist(), currentPage);
    choose_song = mediaFileView.check_choice(vPlayList[0]->getPlaylist(), currentPage);
    // choose_song = mediaFileView.getChoice();
    if(choose_song == -1)
    {
        flowID.pop();
        return;
    }
    while(flag)
    {   
        system("clear");
        mediaFileView.menuMetaView();
        user_input =userInput();
        // flowID.push(SHOW_METADATA);
        switch (user_input)
        {
            case SHOW_METADATA:
                system("clear");
                metaData.viewMetadata(vPlayList[0]->getPlaylist(),choose_song);
                cout << "Input your command: " << endl;
                user_input=userInput();
                if(user_input==0)
                    // flag = false;
                    break;
            case UPDATE_METADATA:
                system("clear");
                metaData.updateMetadata(vPlayList[0]->getPlaylist(),choose_song);
                break;
            case BACK_MENU:
                system("clear");
                flag = false;
                break;
            default:
                break;
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
    }
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
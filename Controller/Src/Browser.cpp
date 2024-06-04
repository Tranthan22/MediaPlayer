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
    mediaFileView.check_choice(vPlayList[0]->getPlaylist(), currentPage);
    choose_song = mediaFileView.getChoice();
    while(flag)
    { 
        user_input =userInput();
        // flowID.push(SHOW_METADATA);
        switch (user_input)
        {
            case SHOW_METADATA:
                system("clear");
                flowID.push(SHOW_METADATA);
                metaData.viewMetadata(vPlayList[0]->getPlaylist(),choose_song);
                cout << "Input your command: " << endl;
                user_input=userInput();
                if(user_input==0)
                    flowID.pop();
                    flag = false;
                break;
            case UPDATE_METADATA:
                system("clear");
                flowID.push(UPDATE_METADATA);
                metaData.updateMetadata(vPlayList[0]->getPlaylist(),choose_song);
                user_input=userInput();
                if(user_input==0)
                    flowID.pop();
                    flag = false;
                break;
            case 'e':
            case 'E':
                system("clear");
                flowID.pop();
                flag = false;
                break;
            default:
                break;
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
    }
    // flowID.pop();
}

void Browser::playmusic()
{
    size_t currentPageList = 1;
    size_t currentPageMusic = 1;
    int chosenList = 0;
    int chosenMusic = 0;
    bool flagPlaylist = true;
    bool flagMusic = true;
    while(flagPlaylist)
    {
        mediaPlayerView.display_PlayMucsic(vPlayList, currentPageList);
        chosenList = mediaPlayerView.check_choice_PlayMusicView(vPlayList, currentPageList);
        if(chosenList != 0)
        {   
            flagMusic = true;
            while(flagMusic)
            {
                mediaPlayerView.display_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), currentPageMusic);
                chosenMusic = mediaPlayerView.check_choice_PlayMusicView_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), currentPageMusic);
                
                switch (chosenMusic)
                {
                case 0:
                    flagMusic = false;
                    break;
                case -1:
                    myPlayer.VolumeUp();
                    break;
                case -2:
                    myPlayer.VolumeDown();
                    break;
                case -3:
                    myPlayer.ResumePause();
                    break;
                default:
                    vector<MediaFile*> *a = vPlayList[chosenList - 1]->getPlaylistPointer();
                    MediaFile * b = (*a)[chosenMusic - 1];
                    myPlayer.playMusic(b->getPath().c_str());
                    break;
                }
            }
        }
        else
        {
            flowID.pop();
            flagPlaylist = false;
        }
    }
}
void Browser::playlist()
{
    size_t currentPageList = 1;
    size_t currentPageMusic = 1;
    int chosenList = 0;
    int chosenMusic = 0;
    bool flagPlaylist = true;
    bool flagMusic = true;
    while(flagPlaylist)
    {
        mediaPlayerView.display_PlayMucsic(vPlayList, currentPageList);
        chosenList = mediaPlayerView.check_choice_PlayMusicView(vPlayList, currentPageList);
        if(chosenList != 0)
        {   
            flagMusic = true;
            while(flagMusic)
            {
                mediaPlayerView.display_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), currentPageMusic);
                chosenMusic = mediaPlayerView.check_choice_PlayMusicView_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), currentPageMusic);
                
                switch (chosenMusic)
                {
                case 0:
                    flagMusic = false;
                    break;
                case -1:
                    myPlayer.VolumeUp();
                    break;
                case -2:
                    myPlayer.VolumeDown();
                    break;
                case -3:
                    myPlayer.ResumePause();
                    break;
                default:
                    vector<MediaFile*> *a = vPlayList[chosenList - 1]->getPlaylistPointer();
                    MediaFile * b = (*a)[chosenMusic - 1];
                    myPlayer.playMusic(b->getPath().c_str());
                    break;
                }
            }
        }
        else
        {
            flowID.pop();
            flagPlaylist = false;
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
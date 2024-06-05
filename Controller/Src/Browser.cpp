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

string Browser::userInputString()
{
    string userInput;
    while(userInput.empty())
    {
        getline(cin, userInput);
    }
    return userInput;
}
// void Browser::CallbackRegister()
// {
//     Mix_HookMusicFinished(myPlayer.nextMusic);
// }

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
        chosenMusic = 0;
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
                    /* setlist + play continuously */
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
void Browser::playlist(size_t& chosenList, size_t& chosenMusic)
{
    int UserOption = 0;
    playListView.display_Playlist(vPlayList, chosenList);
    UserOption = playListView.check_choice_PlaylistView(vPlayList, chosenList);
    switch (UserOption)
    {
    /* Exit */
    case 0:
        flowID.pop();
        break;
    /* Create playlist */
    case -1:
        createList();
        break;

    case -2:
        deleteList();
        break;

    case -3:
        renameList();
        break;

    /* Choose list */
    default:
        chosenList = (size_t)UserOption;
        flowID.push(6);
        break;
    }
}
void Browser::playlist_music(size_t& chosenList)
{
    int UserOption = 0;
    playListView.display_PlaylistName(vPlayList[chosenList - 1]->getPlaylist(), chosenList);
    UserOption = playListView.check_choice_PlaylistView(vPlayList, chosenList);
    switch (UserOption)
    {
    /* Exit */
    case 0:
        flowID.pop();
        break;

    /* Add Music */
    case -1:
        flowID.push(7);
        break;

    /* Remove Music */
    case -2:
        break;

    default:
        flowID.push(8);
        break;
    }
}
/*Create Playlist*/
void Browser::createList()
{
    cout << "Name: " ;
    string newPlaylistName = userInputString();
    vPlayList.push_back(new Playlist(newPlaylistName));
}

/* Delete playlist */
void Browser::deleteList()
{
    cout << "Choose list number to delete: " ;
    int newPlaylistIndex = userInput() - 1;
    if (newPlaylistIndex < 0 || newPlaylistIndex >= vPlayList.size()) {
        cout << "Invalid list number." << endl;
        return;
    }
    else
    {
        vPlayList.erase(vPlayList.begin() + newPlaylistIndex);
    }
}

/* Rename playlist */
void Browser::renameList()
{
    cout << "Choose list number to rename: " ;
    int playlistIndex = userInput() - 1;
    cout << vPlayList.size();
    if (playlistIndex < 0 || playlistIndex >= vPlayList.size()) {
        cout << "Invalid list number." << endl;
        cin.ignore();
        return;
    }
    else
    {
        cout << "New name: " ;
        string newPlaylistName = userInputString();
        vPlayList[playlistIndex]->setName(newPlaylistName);
    }
}

/* Flow */
void Browser::programFlow()
{
    setPath();
    loadFile();
    flowID.push(MENU_ID); // Menu
    size_t current_screen;
    size_t chosenList = 1;
    size_t chosenMusic = 1;
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
                playlist(chosenList, chosenMusic);
                break;
            case PLAY_MUSIC_ID:
                playmusic();
                break;
            case 6:
                playlist_music(chosenList);
                break;

            default:
                flowID.pop();
                break;
        }
    }
}

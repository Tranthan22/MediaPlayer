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
void Browser::FreeAll()
{
    if(vPlayList[0] != nullptr)
    {
        for(MediaFile* mediafile : vPlayList[0]->getPlaylist())
        {
            delete mediafile;
        }
        for(Playlist* playlist : vPlayList)
        {
            delete playlist;
        }
    }
    vPlayList[0] = nullptr;
    vPlayList.clear();
}
int Browser::userInput()
{
    int choice;
    cin >> choice;
    if (std::cin.fail())
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice;
    }
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
void Browser::CallbackRegister()
{
    // Mix_HookMusicFinished(myPlayer.nextMusic);
}

/*===========================================  Menu =========================================================*/
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
    case EXIT:
        flowID.pop();
        flowID.push(-1);
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


/*========================================== Option 1 in Menu =========================================================*/
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
                cout << "Enter to back: " << endl;
                cin.ignore();

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


/*========================================== Option 2 in Menu =========================================================*/
void Browser::playlist(size_t& chosenList, size_t& chosenMusic)
{
    int UserOption = 0;
    playListView.display_Playlist(vPlayList, list);
    UserOption = playListView.check_choice_PlaylistView(vPlayList, list);
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

    /* Delete playlist */
    case -2:
        deleteList();
        break;

    /* Rename playlist */
    case -3:
        renameList();
        break;

    /* Choose list */
    default:
        chosenList = (size_t)UserOption;
        flowID.push(PLAY_LIST_MUSIC_ID);
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
/* ================================= Interact with Playlist ====================================== */
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
        // flowID.push(7);
        break;

    /* Remove Music */
    case -2:
        break;

    default:
        // flowID.push(8);
        break;
    }
}


/*========================================== Option 3 in Menu =========================================================*/
void Browser::playmusic(size_t& chosenList)
{
    mediaPlayerView.display_PlayMucsic(vPlayList, list);
    chosenList = mediaPlayerView.check_choice_PlayMusicView(vPlayList, list);
    if(chosenList > 0)
    {
        myPlayer.setList(vPlayList[chosenList - 1]->getPlaylistPointer());
        flowID.push(PLAY_MUSIC_PLAYER_ID);
    }
    else
    {
        /* Exit */
        list = 1;
        flowID.pop();
    }
}
void Browser::playmusic_player(size_t& chosenList, size_t& chosenMusic)
{
    mediaPlayerView.display_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), list);
    chosenMusic = mediaPlayerView.check_choice_PlayMusicView_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), list);
    
    switch (chosenMusic)
    {
    case 0:
        list = 1;
        flowID.pop();
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
    case -4:
        myPlayer.nextMusic();
        break;
    default:
        vector<MediaFile*> *a = vPlayList[chosenList - 1]->getPlaylistPointer();
        MediaFile * b = (*a)[chosenMusic - 1];
        myPlayer.playMusic(b->getPath().c_str());
        break;
    }

}
/*========================================== Program Flow =====================================================*/
void Browser::programFlow()
{
    while(1)
    {   
        setPath();
        loadFile();
        flowID.push(MENU_ID);
        bool flag =true;
        while (flag){
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
                    playmusic(chosenList);
                    break;
                case PLAY_LIST_MUSIC_ID:
                    playlist_music(chosenList);
                    break;
                case PLAY_MUSIC_PLAYER_ID:
                    playmusic_player(chosenList, chosenMusic);
                    break;
                default:
                    flag=false;
                    flowID.pop();
                    FreeAll();
                    break;
            }
        }
    }
}

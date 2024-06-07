#include "Browser.hpp"
#include <stack>

#define START_PAGE 1

// std::atomic<bool> flagAuto(false);

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
    // INPUT WRONG VALUES
    return -1;
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
    /*PUSH MEDIALIST TO STACK*/
    case MEDIA_LIST:
        flowID.push(MEDIA_LIST_ID);
        break;
    /*PUSH PLAYLIST TO STACK*/
    case PLAY_LIST:
        flowID.push(PLAY_LIST_ID);
        break;
    /*PUSH PLAYMUSC TO STACK*/
    case PLAY_MUSIC:
        flowID.push(PLAY_MUSIC_ID);
        break;
    /*EXIT TO PATH*/
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
    cout << "\nChoose song to modifie : ";
    choose_song = mediaFileView.check_choice(vPlayList[0]->getPlaylist(), currentPage);
    if(choose_song == -1)
    {
        flowID.pop();
        return;
    }
    else
    {
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
                    viewMetadata(choose_song);
                    cout << "Enter to back: " << endl;
                    cin.ignore();
                    break;
                case UPDATE_METADATA:
                    system("clear");
                    updateMetadata(choose_song);
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
}

void Browser::viewMetadata(int file_idx)
{
    string file_path = vPlayList[0]->getPlaylist()[file_idx-1]->getPath();
    string file_name = vPlayList[0]->getPlaylist()[file_idx-1]->getName();
    int file_type = vPlayList[0]->getPlaylist()[file_idx-1]->getType();
    // get  data from playlist to metaData
    metaData.set_FilePath(file_path);
    TagLib::FileRef fileRef=metaData.getfileRef();
    string header = "Displaying Metadata...";
    cout << string(tableWidth , '=')<<endl;
    cout << string(tableWidth / 2-header.length()/2-file_name.length()/2, ' ') << header <<file_name<<endl;
    cout << string(tableWidth, '=')<<endl;
    cout << endl;
    if (!fileRef.isNull() && fileRef.tag())
    {
        TagLib::Tag *tag = fileRef.tag();
        switch (file_type)
        {
        case AUDIO_FILE_TYPE:
            metadataView.displayAudioFileMetadata(tag, fileRef);
            return;
            // break;
        case VIDEO_FILE_TYPE:
            metadataView.displayVideoFileMetadata(tag, fileRef, file_path);
            return;
            // break;
        default:
            metadataView.getMediaFileTypeError();
            return;
        }
    }
    else
    {
        metadataView.getMetadataError();
        return;
    }
}

void Browser::updateMetadata(int file_idx)
{   
    string file_path = vPlayList[0]->getPlaylist()[file_idx-1]->getPath();
    string file_name = vPlayList[0]->getPlaylist()[file_idx-1]->getName();
    int file_type = vPlayList[0]->getPlaylist()[file_idx-1]->getType();
    // get  data from playlist to metaData
    metaData.set_FilePath(file_path);
    TagLib::FileRef fileRef=metaData.getfileRef();
    TagLib::Tag *tag = fileRef.tag();
    string new_value;
    bool flag =true;
    string header = "Updating Metadata...";
    int update_opt;
    while(flag){
        // ======================================================
        // Show data file mp3
        system("clear");
        cout << string(tableWidth , '=')<<endl;
        cout << string(tableWidth / 2-header.length()/2 -file_name.length()/2, ' ') << header << file_name<<endl;
        cout << string(tableWidth, '=')<<endl;
        cout << endl;
        metadataView.displayAudioFileMetadata(tag, fileRef);
        cout<<endl;
        cout << left << setw(30) << "0. Back" << endl;
        cout<<endl;
        cout << string(tableWidth, '=')<<endl;
        metadataView.chooseMetadataField();
        update_opt = userInput();
        // ======================================================
        if(update_opt == 0)
        {
            return;
            
        }else if(update_opt<0 || update_opt >6){
            menuView.InvalidChoiceInterface();
            cin.ignore();
        }else{
        // update_opt = browser->userInput();
        metadataView.enterMetadataValue();
        getline(cin, new_value);    
        if (file_type == AUDIO_FILE_TYPE)
        {
                switch (update_opt)
                {
                case MODIFY_NAME:
                    tag->setTitle(new_value.c_str());
                    flag =false;
                    break;
                case MODIFY_ALBUM:
                    tag->setAlbum(new_value.c_str());
                    flag =false;
                    break;
                case MODIFY_ARTIST:
                    tag->setArtist(new_value.c_str());
                    flag =false;
                    break;
                case MODIFY_YEAR:
                    tag->setYear(stoi(new_value));
                    flag =false;
                    break;
                case MODIFY_GENRE:
                    tag->setGenre(new_value.c_str());
                    flag =false;
                    break;
                case MODIFY_AUDIO_DURATION:
                    return;
                default:
                    menuView.InvalidChoiceInterface();
                    flag =true;
                    cin.ignore();
                    return;
                }
            }else{
                switch (update_opt)
                {
                case MODIFY_VIDEO_NAME:
                    tag->setTitle(new_value.c_str());
                    flag =false;
                    break;
                case MODIFY_SIZE:
                    metadataView.modifyMetadataError();
                    cin.ignore();
                    flag =false;
                    return;
                case MODIFY_BIT_RATE:
                    metadataView.modifyMetadataError();
                    flag =false;
                    cin.ignore();
                    return;
                case MODIFY_VIDEO_DURATION:
                    metadataView.modifyMetadataError();
                    flag =false;
                    cin.ignore();
                    return;
                default:
                    menuView.InvalidChoiceInterface();
                    cin.ignore();
                    flag =true;
                    return;
                }
            }
        if (fileRef.save() == true){
            metadataView.modifyMetadataSuccess();
            return;
        }
        }
    }
}

/*========================================== Option 2 in Menu =========================================================*/
void Browser::playlist(int& chosenList, int& chosenMusic)
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
    if (newPlaylistIndex < 0 || newPlaylistIndex >= (int)vPlayList.size()) {
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
    if (playlistIndex < 0 || playlistIndex >= (int)vPlayList.size()) {
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

void Browser::playlist_music(int& chosenList)
{
    system("clear");
    int choose_remove;
    int choose_add;
    bool check_add;
    int UserOption = 0;
    size_t currentPage =1;
    playListView.display_PlaylistName(vPlayList[chosenList - 1]->getPlaylist(), currentPage);
    UserOption = playListView.check_choice_PlaylistName(vPlayList[chosenList - 1]->getPlaylist(), currentPage);
    switch (UserOption)
    {
    /* Exit */
    case EXIT_MUSIC:
        flowID.pop();
        break;
    /* Add Music */
    case ADD_MUSIC:
        // flowID.push(7);
        mediaFileView.display_MediaFile(vPlayList[0]->getPlaylist(), currentPage);
        cout<<"\n Choose media to Add: ";
        choose_add = mediaFileView.check_choice(vPlayList[0]->getPlaylist(), currentPage);
        if(choose_add != -1){
            check_add=playListView.check_choice_PlaylistName_ADD(vPlayList[chosenList - 1]->getPlaylist(),vPlayList[0]->getPlaylist(),choose_add);
            if(check_add){
                vPlayList[chosenList - 1]->getPlaylist().push_back(vPlayList[0]->getPlaylist()[choose_add-1]);
                return;
            }
        }
        break;
    /* Remove Music */
    case REMOVE_MUSIC:
        system("clear");
        playListView.display_PlayNameRemove(vPlayList[chosenList - 1]->getPlaylist(), currentPage);
        choose_remove = playListView.check_choice_PlaylistName_REMOVE(vPlayList[chosenList - 1]->getPlaylist(), currentPage);
        vPlayList[chosenList - 1]->getPlaylist().erase( vPlayList[chosenList - 1]->getPlaylist().begin()+choose_remove-1);
        break;
    default:
        // flowID.push(8);
        break;
    }
}


/*========================================== Option 3 in Menu =========================================================*/
void Browser::playmusic(int& chosenList)
{
    mediaPlayerView.display_PlayMucsic(vPlayList, list);
    chosenList = mediaPlayerView.check_choice_PlayMusicView(vPlayList, list);
    if(chosenList > 0)
    {
        myPlayer.setList(vPlayList[chosenList - 1]->getPlaylistPointer());
        flowID.push(PLAY_MUSIC_PLAYER_ID);
        startThread();
    }
    else
    {
        /* Exit */
        list = 1;
        flowID.pop();
    }
}
void Browser::playmusic_player(int& chosenList, int& chosenMusic)
{
    chosenMusic = mediaPlayerView.check_choice_PlayMusicView_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), list);
    switch (chosenMusic)
    {
    case 0:
        list = 1;
        flowID.pop();
        myThread.join();
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
    case -5:
        {
        std::lock_guard<std::mutex> lock1(mtx1);
        myPlayer.preMusic();
        break;}
    case -6:
        // Case auto or update'
        if(myPlayer.getFlagAuto() ==true)
        {
            myPlayer.setFlagAuto(false);
        }else{
            myPlayer.setFlagAuto(true);
        }
        
        break;
    default:
        // vector<MediaFile*> *a = vPlayList[chosenList - 1]->getPlaylistPointer();
        // MediaFile * b = (*a)[chosenMusic - 1];
        startTime = std::chrono::steady_clock::now();
        myPlayer.setList(vPlayList[chosenList - 1]->getPlaylistPointer());
        myPlayer.setIndexInList(chosenMusic);
        myPlayer.playMusic(/*b->getPath().c_str()*/);
        break;
    }

}
/*============================== Thread ===============================*/

void Browser::updatePlayerView() {
    size_t current_screen;
    size_t progressLong;
    do
    {
        std::lock_guard<std::mutex> lock1(mtx1);
        std::lock_guard<std::mutex> lock2(mtx2);
        fileRef = TagLib::FileRef(myPlayer.getPlayingMusicPath().c_str());
        size_t duration = fileRef.audioProperties()->lengthInSeconds();
        
        if(myPlayer.isPlaying())
        {
            timeElape = std::chrono::steady_clock::now() - startTime;
            if(timeElape.count() >= duration)
            {
                startTime = std::chrono::steady_clock::now();
                timeElape = std::chrono::duration<double>::zero();
                myPlayer.autoMusic();
            }
        }
        else
        {
            startTime = std::chrono::steady_clock::now() - std::chrono::duration_cast<std::chrono::steady_clock::duration>(timeElape);
        }
        progressLong = timeElape.count() / duration * 50;
        
        mediaPlayerView.display_ShowPlay(vPlayList[chosenList - 1]->getPlaylist(), list, progressLong, myPlayer);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        current_screen = flowID.top();
    }
    while(current_screen  == PLAY_MUSIC_PLAYER_ID);
}

void Browser::startThread()
{
    myThread = std::thread(&Browser::updatePlayerView, this);
}

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

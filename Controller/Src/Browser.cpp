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
void Browser::menu()
{
    switch(menuView.check_choice())
    {
        case MEDIA_LIST:
            std::cout << "MEDIA_LIST";
            break;
        case PLAY_LIST:
            std::cout << "PLAY_LIST";
            break;
        case PLAY_MUSIC:
            std::cout << "PLAY_MUSIC";
            break;
        case EXIT:
            std::cout << "Exit";
            break;
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
            // std::cout << entry.path().filename() << std::endl;
            vMediaFile.push_back(new MediaFile(entry.path().filename().string(), entry.path().string()));
        }
    }
}

void Browser::medialist()
{
    mediaFileView.display_MediaFile(vMediaFile, 1);
}
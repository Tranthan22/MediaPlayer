#include "Browser.hpp"

Browser::Browser(/* args */)
{
}

Browser::~Browser()
{
}

void Browser::setPath()
{
    Path = mediaPlayerView.input_path();
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
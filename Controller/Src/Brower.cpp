#include "Brower.hpp"

Brower::Brower(/* args */)
{
}

Brower::~Brower()
{
}

void Brower::setPath()
{
    Path = mediaPlayerView.input_path();
}
void Brower::menu()
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
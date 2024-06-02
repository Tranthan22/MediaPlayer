#include <string>
#include "MediaPlayerView.hpp"
#include "MenuView.hpp"

class Browser
{
private:
    std::string Path;
    MediaPlayerView mediaPlayerView; 
    MenuView menuView;

public:
    Browser(/* args */);
    ~Browser();

    /* View */
    void setPath();
    void menu();

    /* Model */

};


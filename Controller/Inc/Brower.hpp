#include <string>
#include "MediaPlayerView.hpp"
#include "MenuView.hpp"

class Brower
{
private:
    std::string Path;
    MediaPlayerView mediaPlayerView; 
    MenuView menuView;

public:
    Brower(/* args */);
    ~Brower();

    /* View */
    void setPath();
    void menu();

    /* Model */

};


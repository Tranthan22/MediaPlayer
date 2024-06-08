#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include "main.hpp"

enum MenuChoices
{
    EXIT = 0,
    MEDIA_LIST,
    PLAY_LIST,
    PLAY_MUSIC
};

using namespace std;

class MenuView
{
private:
public:
    MenuView()=default;
    ~MenuView()= default;
    void display_menu();
    void InvalidChoiceInterface();
    void exitProgram();
};
#endif
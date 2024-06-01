#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <iostream>
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
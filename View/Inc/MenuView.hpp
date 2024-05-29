#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <iostream>
using namespace std;

class MenuView
{
private:
    /* data */
    size_t choice;
public:
    MenuView()=default;
    ~MenuView()= default;

    void display_menu();
    void check_choice();
    void set_choice(int choice)
    {
       this->choice = choice;
    }
    size_t get_choice()
    {
        return choice;
    }
};

#endif

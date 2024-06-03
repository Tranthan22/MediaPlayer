#include "MenuView.hpp"
#include <cstdlib>
#include <iomanip> // Để sử dụng setw()

void MenuView::display_menu()
{
    system("clear");
    cout << "                                  Menu                                  " << endl;
    cout << "==============================================================================\n" << endl;
    cout << left << setw(30) << "1. Media List"
         << left << setw(30) << "2. Play list"
         << left << setw(30) << "3. Play music"<<endl;
    cout << left<<"\n0. Exit\n";
    cout << "==============================================================================\n" << endl;
    cout << "Choose option:" << endl;
}

void MenuView::InvalidChoiceInterface()
{
    cout << "Invalid choice. Please try again." << endl;
}

void MenuView::exitProgram()
{
    cout << "Exiting the application !!!" << endl;
}


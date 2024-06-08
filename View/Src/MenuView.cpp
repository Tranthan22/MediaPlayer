#include "MenuView.hpp"


/*========================================================================================================================================================*/
//                                                              SHOW MENU
/*========================================================================================================================================================*/

void MenuView::display_menu()
{
    system("clear");
    string header = "Menu";
    cout<< string(tableWidth , '=')<<endl;
    cout<< string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout<< string(tableWidth, '=')<<"\n"<<endl;
    cout<< left << setw(10)<<" "
        << left << setw(tableWidth/4) << "1. Media List"
        << left << setw(tableWidth/4) << "2. Play list"
        << left << setw(tableWidth/4) << "3. Play music"
        << left << setw(tableWidth/4) << "0. Exit\n"<<endl;
    cout<< string(tableWidth, '=')<<endl;
    cout << "Choose option:";
} 

void MenuView::InvalidChoiceInterface()
{
    cout << "Invalid choice. Please try again." << endl;
}

void MenuView::exitProgram()
{
    cout << "Exiting the application !!!" << endl;
}


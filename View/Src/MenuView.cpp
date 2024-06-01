#include "../Inc/MenuView.hpp"
#include <cstdlib>
#include <iomanip> // Để sử dụng setw()
void MenuView::display_menu()
{
    cout << "                                  Menu                                  " << endl;
    cout << "==============================================================================\n" << endl;
    cout << left << setw(30) << "1. Media List"
         << left << setw(30) << "2. Play list"
         << left << setw(30) << "3. Play music"<<endl;
    cout << left<<"\n0. Exit\n";
    cout << "==============================================================================\n" << endl;
    // cout << "Choose page to show: " << endl;
}

void MenuView::check_choice(){
    display_menu();

    cout << "Choose action : " ;
    size_t choice;
    do {
        
        cin >> choice;
        set_choice(choice);
        switch (choice) {
            case 1:
                // mediaList();
                system("clear");
                cout << "hello." << endl;
                break;
            case 2:
                // playlist();
                system("clear");
                cout << "hello." << endl;
                break;
            case 3:
                // playMusic();
                system("clear");
                cout << "hello." << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                cin.ignore(); // Để chờ người dùng nhấn Enter trước khi tiếp tục
                system("clear");
                // cin.get();
                break;
            default:
                system("clear");
                display_menu();
                cout << "==============================================================================\n" << endl;
                cout << "Choose page to show: " << endl;
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);
}


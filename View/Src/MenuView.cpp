#include "../Inc/MenuView.hpp"
#include <cstdlib>

void MenuView::display_menu()
{
    cout << "                             Menu                            " << endl;
    cout << "==============================================================================\n" << endl;
    cout << "1. Media List";
    cout << "\t\t\t 2. Playlist";
    cout << "\t\t\t 3. Play Music\n\n";
    cout << "0. Exit\n" << endl;
    // cout << "==============================================================================\n" << endl;
    // cout << "Choose page to show: " << endl;
}

void MenuView::check_choice(){
    display_menu();
    cout << "==============================================================================\n" << endl;
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



int main()
{
    MenuView a;
    a.check_choice();
    return 0;
}


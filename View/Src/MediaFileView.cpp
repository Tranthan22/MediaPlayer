#include "MediaFileView.hpp"
#include <cstdlib>

#include "MediaFileView.hpp"

void MediaFileView::display_MediaFile(vector<MediaFile*>& songs, size_t currentpage)
{
    system("clear");
    std::cout << "                                           Media List                                   " << endl;
    cout << "============================================================================================\n" << endl;
    cout << left << setw(5) << "No."
         << left << setw(30) << "Name"
         << left << setw(60) << "Path"<<endl;
        //  << left << setw(15) << "Duration"
        //  << left << setw(20) << "Publisher" << endl;
    displaySongsPerPage(songs, currentpage);
    
    cout << "\n============================================================================================" << endl;
    cout << "Total Media list: " << songs.size() << "\n" << endl;
    cout << "Page: " << currentpage;
    cout << setw(10) << " " << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit" << endl;
    cout << "\nChoose song to modifie : ";
    // check_choice(songs, currentpage);
}

void MediaFileView::displaySongsPerPage(vector<MediaFile*>& songs, size_t& currentpage) {
    size_t startIndex = (currentpage - 1) * PAGE_SIZE;
    size_t endIndex = min(startIndex + PAGE_SIZE, songs.size());
    for (size_t i = startIndex; i < endIndex; ++i) {
        cout << left << setw(5) << i + 1
             << left << setw(30) << truncate(songs[i]->getName(), 30)
             << left << setw(60) << truncate(songs[i]->getPath(), 60)<<endl;
            //  << left << setw(15) << truncate(std::to_string(songs[i]->getType()), 15)<<endl;
            //  << left << setw(20) << truncate("Hellooo", 20) << endl;
    }
}

inline void MediaFileView::Invalid_choice()
{
    cout << "Invalid choice. Please enter a valid option." << endl;
}

int MediaFileView::getChoice()
{
    return choice;
}
void MediaFileView::setChoice(int choice)
{
    this->choice =choice;
}
void MediaFileView::check_choice(vector<MediaFile*>& songs, size_t& currentPage) {
    string userInput;
    bool flag = true;
    while(flag)
    {
        getline(cin, userInput);
        if (!userInput.empty()) {
            stringstream ss(userInput);
            size_t Song_Choice;
            if (ss >> Song_Choice)
            {
                if (Song_Choice > 0 && Song_Choice <= songs.size())
                {
                    system("clear");
                    // display_MediaFile(songs, currentPage);
                    menuView();
                    setChoice(Song_Choice);
                    flag = false;

                }
                else
                {
                    system("clear");
                    display_MediaFile(songs, currentPage);
                    Invalid_choice();
                }
            }
            else
            {
                char command = userInput[0];
                switch (command)
                {
                    case 'N':
                    case 'n':
                        if (currentPage < (songs.size() + PAGE_SIZE - 1) / PAGE_SIZE)
                        {
                            currentPage++;
                        }
                        system("clear");
                        display_MediaFile(songs, currentPage);
                        break;
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        system("clear");
                        display_MediaFile(songs, currentPage);
                        break;
                    case 'E':
                    case 'e':
                        flag = false;
                        break;
                    default:
                        // system("clear");
                        display_MediaFile(songs, currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            display_MediaFile(songs, currentPage);
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}


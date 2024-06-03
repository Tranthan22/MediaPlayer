#include "MediaFileView.hpp"
#include <cstdlib>

#include "MediaFileView.hpp"

void MediaFileView::display_MediaFile(const vector<MediaFile*>& songs, size_t currentpage)
{
    system("clear");
    std::cout << "                                           Media List                                   " << endl;
    cout << "============================================================================================\n" << endl;
    cout << left << setw(5) << "No."
         << left << setw(30) << "Name"
         << left << setw(25) << "Artist"
         << left << setw(15) << "Duration"
         << left << setw(20) << "Publisher" << endl;
    displaySongsPerPage(songs, currentpage);
    
    cout << "\n============================================================================================" << endl;
    cout << "Total Media list: " << songs.size() << "\n" << endl;
    cout << "Page: " << currentpage;
    cout << setw(10) << " " << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit" << endl;
    cout << "\nChoose song : ";
}

void MediaFileView::displaySongsPerPage(const vector<MediaFile*>& songs, size_t& currentpage) {
    size_t startIndex = (currentpage - 1) * PAGE_SIZE;
    size_t endIndex = min(startIndex + PAGE_SIZE, songs.size());
    for (size_t i = startIndex; i < endIndex; ++i) {
        cout << left << setw(5) << i + 1
             << left << setw(30) << truncate(songs[i]->getName(), 30)
             << left << setw(25) << truncate("Hellooo", 25)
             << left << setw(15) << truncate("Hellooo", 15)
             << left << setw(20) << truncate("Hellooo", 20) << endl;
    }
}

inline void MediaFileView::Invalid_pageNumber()
{
    cout << "Invalid page number. Please enter a valid option." << endl;
}

inline void MediaFileView::Invalid_choice()
{
    cout << "Invalid choice. Please enter a valid option." << endl;
}

void MediaFileView::check_choice(const vector<MediaFile*>& songs, size_t& currentPage) {
    string userInput;
    bool flag = true;
    while(flag)
    {
        getline(cin, userInput);
        if (!userInput.empty()) {
            stringstream ss(userInput);
            size_t pageChoice;
            if (ss >> pageChoice)
            {
                if (pageChoice > 0 && pageChoice <= (songs.size() + PAGE_SIZE - 1) / PAGE_SIZE)
                {
                    currentPage = pageChoice;
                    system("clear");
                    display_MediaFile(songs, currentPage);
                }
                else
                {
                    system("clear");
                    display_MediaFile(songs, currentPage);
                    cout << "Invalid page number. Media list number between 1 and " << (songs.size() + PAGE_SIZE - 1) / PAGE_SIZE << "." << endl;
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
            
        }
    }
}


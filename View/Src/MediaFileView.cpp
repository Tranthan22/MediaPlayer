#include "MediaFileView.hpp"
#include <cstdlib>

void MediaFileView::display_MediaFile(vector<MediaFile*>& songs, size_t currentpage)
{
    system("clear");
    std::cout << "                                                             Media List                                                " << endl;
    std::cout << "=====================================================================================================================\n" << endl;
    std::cout << left << setw(5) << "No."
         << left << setw(40) << "Name"
         << left << setw(40) << "Artist"
         << left << setw(20) << "Duration (s)"
         << left << setw(20) << "Publisher" << endl;
    displaySongsPerPage(songs, currentpage);
    
    std::cout << "\n======================================================================================================================\n" << endl;
    std::cout << "Total Media list: " << songs.size() << "\n" << endl;
    std::cout << "Page: " << currentpage;
    std::cout << setw(10) << " " << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit" << endl;
    std::cout << "\nChoose song to modifie : ";
    // check_choice(songs, currentpage);
}

void MediaFileView::displaySongsPerPage(vector<MediaFile*>& songs, size_t& currentpage) {
    
    size_t startIndex = (currentpage - 1) * PAGE_SIZE;
    size_t endIndex = min(startIndex + PAGE_SIZE, songs.size());
    for (size_t i = startIndex; i < endIndex; ++i) {
        string file_name = songs[i]->getName();
        string file_path = songs[i]->getPath();
        int file_type = songs[i]->getType();
        TagLib::FileRef fileRef(file_path.c_str());
    if (!fileRef.isNull() && fileRef.tag()){
        TagLib::Tag *tag = fileRef.tag();
        std::cout << left << setw(5) << i + 1
            << left << setw(40) << truncate(tag->title().toCString(),40)
            << left << setw(40) << truncate(tag->artist().toCString(),40)
            << left << setw(20) << fileRef.audioProperties()->lengthInSeconds()
            << left << setw(20) << tag->year()<< endl;
        
    }
    }
    std::cout<<endl;
}

inline void MediaFileView::Invalid_choice()
{
    cout << "Invalid choice. Please enter a valid option." << endl;
}

int MediaFileView::check_choice(vector<MediaFile*>& songs, size_t& currentPage) {
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
                    // setChoice(Song_Choice);
                    return Song_Choice;
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
                        return -1;
                        // setChoice(Song_Choice);
                        break;
                    default:
                        system("clear");
                        display_MediaFile(songs, currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }
        else
        {
            system("clear");
            display_MediaFile(songs, currentPage);
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}


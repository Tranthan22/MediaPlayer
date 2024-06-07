#include "MediaFileView.hpp"
#include <cstdlib>
#include <string>


#define tableWidth 120


/*========================================================================================================================================================*/
//                                                                     SHOW SONGS IN MEDIALIST                                                            //
/*========================================================================================================================================================*/

void MediaFileView::display_MediaFile(vector<MediaFile*>& songs, size_t currentpage)
{
    system("clear");
    string header = "Media List";
    cout << string(tableWidth , '=')<<endl;
    cout << string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout << string(tableWidth, '=')<<endl;
    cout <<"|"<< left << setw(10) << " No."
         <<"|"<< left << setw(tableWidth/3) << "Name"
         <<"|"<< left << setw(tableWidth/4) << "Artist"
         <<"|"<< left << setw(tableWidth/8) << "Duration (s)"
         <<"|"<< left << setw(tableWidth/8) << "Publisher"<<endl;
    cout << string(tableWidth ,'-')<<"\n"<<endl;

    displaySongsPerPage(songs, currentpage);
    
    cout <<"\n"<< string(tableWidth , '-')<<endl;
    cout << "Total Media list: " << songs.size() << endl;
    cout << "Page: " << currentpage<<endl;
    cout <<string(tableWidth/4, ' ')
         << left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit"<< endl;
    cout<<endl;
    cout<< string(tableWidth , '=')<<endl;
}

// // Hàm tính kích thước chuỗi UTF-8 (số ký tự Unicode)
// size_t utf8_strlen(const std::string& str) {
//     // Chuyển đổi từ UTF-8 sang wstring (UTF-32)
//     std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
//     std::u32string u32_str = converter.from_bytes(str);

//     // Trả về kích thước của chuỗi UTF-32
//     return u32_str.length();
// }

void MediaFileView::displaySongsPerPage(vector<MediaFile*>& songs, size_t& currentpage) {
    size_t startIndex = (currentpage - 1) * PAGE_SIZE;
    size_t endIndex = min(startIndex + PAGE_SIZE, songs.size());
    for (int i = (int)startIndex; i < (int)endIndex; ++i) {
        string file_path = songs[i]->getPath();
        TagLib::FileRef fileRef(file_path.c_str());
    if (!fileRef.isNull() && fileRef.tag()){
        TagLib::Tag *tag = fileRef.tag();   
        // size_t length_title = utf8_strlen(tag->title().toCString(true));
        // size_t length_artist = utf8_strlen(tag->artist().toCString(true));
        std::cout <<"|"<< left << setw(10) << i+1
            <<"|"<< left << left_align(truncate_utf8(tag->title().toCString(true), 35),40)
            <<"|"<< left << left_align(truncate_utf8(tag->artist().toCString(true), 30),30)
            <<"|"<< left << setw(tableWidth/8) << fileRef.audioProperties()->lengthInSeconds()
            <<"|"<< left << setw(tableWidth/8) << tag->year()<< endl;
        std::cout<<endl;
    }
    }
}
/*========================================================================================================================================================*/
inline void MediaFileView::Invalid_choice()
{
    cout << "Invalid choice. Please enter a valid option." << endl;
}

// ==================================================== CHECK USING FOR CHOOSE SONG IN MEDIALIST TO MODIFIED =============================================//

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
                    return Song_Choice;
                    flag = false;

                }else{
                    system("clear");
                    display_MediaFile(songs, currentPage);
                    Invalid_choice();
                }
            }else{
                char command = userInput[0];
                switch (command)
                {
                    /*NEXT PAGE*/
                    case 'N':
                    case 'n':
                        if (currentPage < (songs.size() + PAGE_SIZE - 1) / PAGE_SIZE)
                        {
                            currentPage++;
                        }
                        system("clear");
                        display_MediaFile(songs, currentPage);
                        break;
                    /*PRERIOUS PAGE*/
                    case 'P':
                    case 'p':
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                        system("clear");
                        display_MediaFile(songs, currentPage);
                        break;
                    /*EXIT PAGE*/
                    case 'E':
                    case 'e':
                        flag = false;
                        return -1;
                        break;
                    default:
                        system("clear");
                        display_MediaFile(songs, currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        }else{
            system("clear");
            display_MediaFile(songs, currentPage);
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    /*RETURN PAGE*/
    return -1;
}

/*========================================================================================================================================================*/

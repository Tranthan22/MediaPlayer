#include "MetadataView.hpp"


void MetadataView::display_MediaList(const vector<Media_list>& lists, size_t currentpage)
{
    std::cout << "                                       Media play list                                   " << endl;
    cout << "============================================================================================\n" << endl;
    cout << left << setw(10) << "No."
         << left << setw(40) << "List"
         << left << setw(40) << "Last modified" << endl;

    display_MedialistPerPage(lists,currentpage);
    
    cout << "\n============================================================================================" << endl;
    cout<< "Total Media list: "<<lists.size()<<"\n"<<endl;
    cout<< "Page: "<<currentpage;
    cout<<setw(10)<<" "<<left << setw(25) << "P. Previous"
         << left << setw(25) << "N. Next"
         << left << setw(25) << "E. Exit\n" << endl;
    cout<< left << setw(5)<< "Volume: "
        << left << setw(10)<<"100%"
        << left << setw(25) << "U. Up"
        << left << setw(25) << "D. Down" << endl; 
    cout << "\nChoose list to play : ";
}

// Hien thi data doc duoc va hien thi ra
void MetadataView::display_MedialistPerPage(const vector<Media_list>& lists, size_t currentpage) {
    int startIndex = (currentpage - 1) * 10;
    int endIndex = min(startIndex + 10, static_cast<int>(lists.size()) - 1);
    // static_cast<int> chuyen doi sang so int
    for (size_t i = startIndex; i < endIndex; ++i) {
        cout << left << setw(10) << i + 1
             << left << setw(40) << truncate(lists[i].list, 40)
             << left << setw(40) << truncate(lists[i].Lastmodified, 40) << endl;
    }
}


// Ham dung cho he thong phia duoi controll de xac nhan thong tin
void MetadataView::choose_list(const vector<Media_list>& lists, size_t& currentPage) {
        string userInput;    
        display_MediaList(lists, currentPage);
        cout << "\nChoose list to play : ";
    do {    
        getline(cin, userInput);
        if (!userInput.empty()) {
            std::stringstream ss (userInput);
            size_t choose_Playlist;
            if (ss >> choose_Playlist) {
                if (choose_Playlist > 0 && choose_Playlist <= lists.size()) {
                    // system("clear");
                    // display_MediaList();
                    // display_MedialistPerPage(lists, currentPage);
                    // cout << "\nChoose list to play : ";
                    
                    //chon playlist de phat nhac  
                } 
            } else {
                char command = userInput[0];
                switch (command) {
                    case 'N':
                    case 'n':
                    if(currentPage<(lists.size()/10)+1){
                        currentPage++;
                    }
                        system("clear");
                         display_MediaList(lists, currentPage);
                        break;
                    case 'P':
                    case 'p':
                        if (currentPage > 1) {
                            currentPage--;
                        }
                        display_MediaList(lists, currentPage);
                        break;
                    case 'E':
                    case 'e':
                        return;
                    case 'U':
                    case 'u':
                        // display_MediaList();
                        // display_MedialistPerPage(lists, currentPage);
                        // cout << "\nChoose list to play : ";
                        
                        // tang am luong 

                        break;
                    case 'D':
                    case 'd':
                        // if (currentPage > 1) {
                        //     currentPage--;
                        // }
                        // display_MediaList();
                        // display_MedialistPerPage(lists, currentPage);
                        // cout << "\nChoose list to play : ";

                        // giam am luong 
                        
                        break;
                    default:
                        display_MediaList(lists, currentPage);
                        cout << "Invalid choice. Please enter a valid option." << endl;
                }
            }
        } else {
            system("clear");
            display_MediaList(lists, currentPage);
        }
    } while (true);
}



// void Choose_list();
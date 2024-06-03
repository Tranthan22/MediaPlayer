#include "PlaylistView.hpp"

void PlaylistView::display_Playlist(const vector<Playlist*>& plists, size_t currentpage){
     cout << "                                       Playlist                                   " << endl;
     cout << "============================================================================================\n" << endl;
     cout << left << setw(10) << "No."
         << left << setw(40) << "List Name"
         << left << setw(40) << "Number" << endl;

     display_PlaylistPerPage(plists,currentpage);

     cout << "\n============================================================================================" << endl;
     cout<< "Total Media list: "<<plists.size()<<endl;
     cout<< "Page: "<<currentpage<<"\n"<<endl;
     cout <<left << setw(25) << "C. Create"
         << left << setw(25) << "D. Delete"
         << left << setw(25) << "R. Rename"
         << left << setw(25) << "E. Exit\n" << endl;
     cout<<"\n Choose Playlist: "<<endl;
     cout << "\n============================================================================================" << endl;

}

// Ham lay du lieu tu model de truyen du lieu len
void PlaylistView::display_PlaylistPerPage(const vector<Playlist*>& plists, size_t currentpage) {
    int startIndex = (currentpage - 1) * LIST_SIZE;
    int endIndex = min(startIndex + LIST_SIZE, static_cast<int>(plists.size()) - 1);
    // static_cast<int> chuyen doi sang so int
    for (size_t i = startIndex; i < endIndex; ++i) {
        cout << left << setw(10) << i + 1
        // dung de lay ten 
             << left << setw(40) << truncate(plists[i]->getName(), 40)
             << left << setw(40) <<plists[i]->getSize() <<"Songs"<< endl;
    }
    
}

void PlaylistView::display_PlaylistName(const vector<MediaFile*>plist_name, size_t currentpage) {
    cout << "                                           Playlist name                                   " << endl;
    cout << "============================================================================================\n" << endl;
    cout << left << setw(10) << "No."
         << left << setw(35) << "Name"
         << left << setw(20) << "Artist"
         << left << setw(10) << "Duration"
         << left << setw(20) << "Publisher"<< endl;

     display_PlaylistNamePerPage(plist_name,currentpage);

     cout << "\n============================================================================================" << endl;
     cout<< "Total Media list: "<<plist_name.size()<<"\n"<<endl;
     cout<< "Page: "<<currentpage;
     cout<<setw(10)<<" "<<left << setw(25) << "P. Previous"
          << left << setw(25) << "N. Next"
          << left << setw(25) << "E. Exit" <<"\n"<< endl;
     cout<<setw(17)<<" "<<left << setw(25) << "R. Remove"
          << left << setw(25) << "A. Add";
}

void PlaylistView::display_PlaylistNamePerPage(const vector<MediaFile*>plist_name, size_t currentpage) {
    int startIndex = (currentpage - 1) * LIST_NAME_SIZE;
    int endIndex = min(startIndex + LIST_NAME_SIZE, static_cast<int>(plist_name.size()) - 1);
    // static_cast<int> chuyen doi sang so int
    for (size_t i = startIndex; i < endIndex; ++i) {
        cout << left << setw(10) << i + 1
             << left << setw(35) << truncate(plist_name[i]->getName(), 35)
             << left << setw(20) << truncate(plist_name[i]->getName(), 20)
             << left << setw(10) << truncate(plist_name[i]->getName(), 10)
             << left << setw(20) << truncate(plist_name[i]->getName(), 20) << endl;
    }
    
}

void PlaylistView::display_PlayNameAdd(vector<MediaFile*>& plist_name, size_t currentPage)
{
     display_PlaylistName(plist_name,currentPage);
     cout<<"\n Choose media to Add: ";

}
void PlaylistView::display_PlayNameRemove(vector<MediaFile*>& plists_name, size_t& currentPage)
{
     display_PlaylistName(plists_name,currentPage);
     cout<<"\n Choose media to Remove: ";
}



// void PlaylistView::display_MediaPlaylist(const vector<Media_list>& lists, size_t currentpage)
// {
//     std::cout << "                                       Media play list                                   " << endl;
//     cout << "============================================================================================\n" << endl;
//     cout << left << setw(10) << "No."
//          << left << setw(40) << "List"
//          << left << setw(40) << "Last modified" << endl;

//     display_MedialistPerPage(lists,currentpage);
    
//     cout << "\n============================================================================================" << endl;
//     cout<< "Total Media list: "<<lists.size()<<"\n"<<endl;
//     cout<< "Page: "<<currentpage;
//     cout<<setw(10)<<" "<<left << setw(25) << "P. Previous"
//          << left << setw(25) << "N. Next"
//          << left << setw(25) << "E. Exit\n" << endl;
//     cout<< left << setw(5)<< "Volume: "
//     // Change volume
//         << left << setw(10)<<"100%"
//         << left << setw(25) << "U. Up"
//         << left << setw(25) << "D. Down" << endl; 
//     cout << "\nChoose list to play : ";
// }
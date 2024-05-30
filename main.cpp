
// #include "main.hpp"
// #include "PlaylistController.hpp"
#include "View/Inc/PlaylistView.hpp"


int main() {
    
    vector<play_list> lists = {
        {"Song 1", "Artist 1"},
        {"Song 2", "Artist 2"},
        // Thêm các bài hát khác vào đây...
        {"Song 2", "Artist 2"},
        {"Song 2", "Artist 2"},
        {"Song 2", "Artist 2"},
        {"Song 2", "Artist 2"},
        {"Song 2", "Artist 2"},
        {"Song 2", "Artist 2"},
        {"Song 2", "Artist 2"},
        {"Song 25", "Artist 25"}
    };
     vector<playlist_name> plists=
     {
        {"Song 1", "Artist 1", "3:45", "Publisher 1"},
        {"Song 2", "Artist 2", "4:12", "Publisher 2"},
        {"Song 3", "Artist 3", "2:58", "Publisher 3"},
        {"Song 4", "Artist 4", "5:23", "Publisher 4"},
        {"Song 5", "Artist 5", "3:15", "Publisher 5"},
        {"Song 6", "Artist 6", "4:20", "Publisher 6"},
        {"Song 7", "Artist 7", "3:50", "Publisher 7"},
        {"Song 8", "Artist 8", "4:05", "Publisher 8"},
        {"Song 9", "Artist 9", "3:30", "Publisher 9"},
        {"Song 10", "Artist 10", "3:10", "Publisher 10"},
        // Thêm các bài hát khác vào đây...
        {"Song 11", "Artist 11", "3:00", "Publisher 11"},
        {"Song 12", "Artist 12", "4:40", "Publisher 12"},
        {"Song 13", "Artist 13", "3:55", "Publisher 13"},
        {"Song 14", "Artist 14", "2:45", "Publisher 14"},
        {"Song 15", "Artist 15", "3:20", "Publisher 15"},
        {"Song 16", "Artist 16", "3:35", "Publisher 16"},
        {"Song 17", "Artist 17", "4:15", "Publisher 17"},
        {"Song 18", "Artist 18", "3:25", "Publisher 18"},
        {"Song 19", "Artist 19", "3:48", "Publisher 19"},
        {"Song 20", "Artist 20", "4:02", "Publisher 20"},
        // Thêm các bài hát khác vào đây...
        {"Song 21", "Artist 21", "3:33", "Publisher 21"},
        {"Song 22", "Artist 22", "3:18", "Publisher 22"},
        {"Song 23", "Artist 23", "4:10", "Publisher 23"},
        {"Song 24", "Artist 24", "3:28", "Publisher 24"},
        {"Song 25", "Artist 25", "3:52", "Publisher 25"},
    };

    // Số trang hiện tại
    int currentPage = 1;
    PlaylistView check;
    // Hiển thị các bài hát trên trang đầu tiên
    // check.display_Playlist();
    // check.display_PlaylistPerPage(lists,currentPage);
    check.display_PlaylistName();
    check.display_PlaylistNamePerPage(plists,currentPage);
    

}
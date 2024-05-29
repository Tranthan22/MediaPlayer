
#include "main.hpp"
#include "PlaylistController.hpp"


extern Mix_Music *bgm;
std::string musicPath;

int main() {
    
    PlaylistController myPlayer;
    std::vector<char *> mylist;

    mylist.push_back("DungKhoc-ChiDan-11809293.mp3");
    mylist.push_back("DungKhoc-ChiDan-11809293.mp3");
    mylist.push_back("DungKhoc-ChiDan-11809293.mp3");


    myPlayer.nextMusic(mylist);
    std::cout << "playing\n" ;
    int input;
    while(1)
    {
        std::cin >> input;
        if(input == 1)
        {
            myPlayer.VolumeUp();
            std::cout << "up \n" << myPlayer.getVolume() << std::endl;
        }
        else if(input == 2)
        {
            myPlayer.VolumeDown();
            std::cout << "down"  << myPlayer.getVolume() << std::endl;
        }
        else if(input == 0)
        {
            Mix_FreeMusic(bgm);
            std::cout << "exit";
            return 0;
        }
    }
}
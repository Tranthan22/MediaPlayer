
#include "main.hpp"
// #include "MediaPlayer.hpp"
#include "Browser.hpp"

int main()
{
    Browser myBrowser;
    myBrowser.setPath();
    myBrowser.loadFile();
    myBrowser.menu();


}


//       /myData/MediaPlayer/Music



// extern Mix_Music *bgm;
// int main() {
    
//     MediaPlayer myPlayer;
//     std::vector<char *> mylist;

//     mylist.push_back("./Music/DungKhoc.mp3");
//     mylist.push_back("./Music/DieuAnhBiet.mp3");
//     mylist.push_back("./Music/TruyenThaiY.mp3");

//     myPlayer.setList(&mylist);

//     myPlayer.nextMusic();

//     std::cout << mylist.size() <<std::endl;

//     std::cout << "playing\n" ;
//     int input;
//     while(1)
//     {
//         std::cin >> input;
//         switch (input)
//         {
//         case 0:
//             std::cout << "exit";
//             return 0;
//             break;
//         case 1:
//             myPlayer.VolumeUp();
//             std::cout << "up \n" << myPlayer.getVolume() << std::endl;
//             break;

//         case 2:
//             myPlayer.VolumeDown();
//             std::cout << "down"  << myPlayer.getVolume() << std::endl;
//             break;

//         case 3:
//             Mix_PauseMusic();
//             std::cout << "Pause"  << std::endl;
//             break;
        
//         case 4:
//             Mix_ResumeMusic();
//             std::cout << "Resume"  << std::endl;
//             break;

//         case 5:
//             Mix_HaltMusic();
//             std::cout << "Halt"  << std::endl;
//             break;
//         case 6:
//             Mix_PlayMusic(bgm, -1);
//             std::cout << "Again"  << std::endl;
//             break;
//         case 7:
//             myPlayer.ResumePause();
//             std::cout << "Switch state"  << std::endl;
//             break;

//         case 8:
//             myPlayer.nextMusic();
//             std::cout << "Next "  << std::endl;
//             break;

//         default:
//             break;
//         }
//     }
        
// }
#include "MediaPathView.hpp"


void MediaPathView::display_MediaPath()
{
    system("clear");
    std::cout << "                                         Media Path                                   " << std::endl;
    std::cout << "============================================================================================\n\n\n" << std::endl;
    std::cout <<"                        Please, input your media path you want to play"<< std::endl;
    std::cout << "\n\n\n============================================================================================\n" << std::endl;
}
// Ham nay sep dung o phia controll
std::string MediaPathView::input_path(){
    display_MediaPath();
    std::cout << "\nPath : ";
    std::string directoryPath;
    getline(std::cin, directoryPath);
    return directoryPath;
}

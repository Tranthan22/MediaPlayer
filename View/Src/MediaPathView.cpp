#include "MediaPathView.hpp"


/*========================================================================================================================================================*/
//                                                           SHOW INPUT PATH TO RUN
/*========================================================================================================================================================*/
void MediaPathView::display_MediaPath()
{
    system("clear");
    string header = "Media Path";
    string show_notic ="Please, input your media path you want to play";
    cout<< string(tableWidth , '=')<<endl;
    cout<< string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout<< string(tableWidth, '=')<<endl;
    cout<<"\n\n"<<endl;
    cout<< string(tableWidth / 2-show_notic.length()/2, ' ') << show_notic <<endl;
    cout<<"\n\n"<<endl;
    cout<< string(tableWidth ,'=')<<endl;
}

// ===================================-===================    INPUT PATH      ============================================================================//
std::string MediaPathView::input_path()
{
    display_MediaPath();
    cout << "Press < x > to Exit programe"<<endl;
    cout << "Path : ";
    string directoryPath;
    getline(cin, directoryPath);
    if(directoryPath == "x")
    {
        exit(1);     
    }
    return directoryPath;
}

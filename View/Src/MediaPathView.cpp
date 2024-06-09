#include "MediaPathView.hpp"


/*========================================================================================================================================================*/
//                                                           SHOW INPUT PATH TO RUN
/*========================================================================================================================================================*/
void MediaPathView::display_MediaPath(vector<string>& devices)
{
    // system("clear");
    string header = "Media Path";
    string show_notic ="Choose your option";
    cout<< string(tableWidth , '=')<<endl;
    cout<< string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout<< string(tableWidth, '=')<<endl;
    cout<<"\n\n"<<endl;
    cout<< string(tableWidth / 2-show_notic.length()/2, ' ') << show_notic <<endl;
    cout << "0. Exit" << endl;
    cout << "1. Input your path" << endl;
    size_t i = 2;
    for (const auto &device : devices) {
        std::cout << i++ << ". "<< device << std::endl;
    }
    cout<<"\n\n"<<endl;
    cout<< string(tableWidth ,'=')<<endl;
}
void MediaPathView::display_MediaPath()
{
    // system("clear");
    string header = "Media Path";
    string show_notic ="Please, input your media path you want to play";
    cout<< string(tableWidth , '=')<<endl;
    cout<< string(tableWidth / 2-header.length()/2, ' ') << header <<endl;
    cout<< string(tableWidth, '=')<<endl;
    cout<<"\n\n"<<endl;
    cout<< string(tableWidth / 2-show_notic.length()/2, ' ') << show_notic <<endl;
    cout << "0. Exit" << endl;
    cout<<"\n\n"<<endl;
    cout<< string(tableWidth ,'=')<<endl;
}

// ===================================-===================    INPUT PATH      ============================================================================//
std::string MediaPathView::input_path()
{
    display_MediaPath();
    cout << "Path : ";
    string directoryPath;
    getline(cin, directoryPath);
    return directoryPath;
}

int MediaPathView::PathSelection()
{
    int choice;
    cin >> choice;
    if (std::cin.fail())
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice;
    }
    // INPUT WRONG VALUES
    return -1;
}
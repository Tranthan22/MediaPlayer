
#include "main.hpp"
#include "Browser.hpp"

int main()
{
    Browser myBrowser;
    myBrowser.setPath();
    myBrowser.loadFile();
    myBrowser.menu();
}

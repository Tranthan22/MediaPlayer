
#include "main.hpp"
#include "Browser.hpp"
#include "USB.hpp"

int main()
{
    // Thiết lập môi trường mã hóa UTF-8
    std::setlocale(LC_ALL, "");
    Browser myBrowser;
    myBrowser.programFlow();
    return 0;
}

// int main() {
//     USBDeviceMonitor usbDeviceMonitor;

//     std::thread monitorThread(&USBDeviceMonitor::waitForUSBEvents, &usbDeviceMonitor);
//     monitorThread.detach();

//     // Do something else...
//     std::cin.ignore();

//     // Get USB devices
//     std::vector<std::string> devices = usbDeviceMonitor.getUSBDevices();
//     std::cout << "USB Devices: " << std::endl;
//     for (const auto &device : devices) {
//         std::cout << device << std::endl;
//     }

//     return 0;
// }
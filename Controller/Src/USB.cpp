    #include "USB.hpp"
    #include  <string.h>

    
    USBDeviceScanner::USBDeviceScanner() {
        udev = udev_new();
        if (!udev) {
            std::cerr << "Cannot create udev context." << std::endl;
        }
    }

    USBDeviceScanner::~USBDeviceScanner() {
        if (udev) {
            udev_unref(udev);
        }
    }

    void USBDeviceScanner::scanDevices() {
        usbDevices.clear();
        usbMountPoints.clear();

        struct udev_enumerate *enumerate = udev_enumerate_new(udev);
        udev_enumerate_add_match_subsystem(enumerate, "block");
        udev_enumerate_scan_devices(enumerate);

        struct udev_list_entry *devices, *dev_list_entry;
        devices = udev_enumerate_get_list_entry(enumerate);
        udev_list_entry_foreach(dev_list_entry, devices) {
            const char *path = udev_list_entry_get_name(dev_list_entry);
            struct udev_device *dev = udev_device_new_from_syspath(udev, path);
            if (dev) {
                const char *devType = udev_device_get_devtype(dev);
                const char *devNode = udev_device_get_devnode(dev);

                if (devType && strcmp(devType, "partition") == 0 && devNode && isUSBDevice(dev)) {
                    usbDevices.push_back(devNode);
                }
                udev_device_unref(dev);
            }
        }

        udev_enumerate_unref(enumerate);

        mapDeviceNodesToMountPoints();
    }

std::vector<std::string> USBDeviceScanner::getUSBMountPoints() const {
        return usbMountPoints;
    }

 bool USBDeviceScanner::isUSBDevice(struct udev_device *dev) {
        struct udev_device *parent = udev_device_get_parent_with_subsystem_devtype(dev, "usb", "usb_device");
        return parent != nullptr;
    }

    void USBDeviceScanner::mapDeviceNodesToMountPoints() {
        std::ifstream mounts("/proc/mounts");
        if (!mounts.is_open()) {
            std::cerr << "Cannot open /proc/mounts." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(mounts, line)) {
            std::istringstream iss(line);
            std::string device, mountPoint;
            iss >> device >> mountPoint;

            if (std::find(usbDevices.begin(), usbDevices.end(), device) != usbDevices.end()) {
                usbMountPoints.push_back(unescapeMountPoint(mountPoint));
            }
        }

        mounts.close();
    }

    std::string USBDeviceScanner::unescapeMountPoint(const std::string &mountPoint) {
        std::string unescaped;
        size_t length = mountPoint.length();
        for (size_t i = 0; i < length; ++i) {
            if (mountPoint[i] == '\\' && i + 3 < length) {
                std::string octal = mountPoint.substr(i + 1, 3);
                char ch = static_cast<char>(std::stoi(octal, nullptr, 8));
                unescaped += ch;
                i += 3;
            } else {
                unescaped += mountPoint[i];
            }
        }
        return unescaped;
    }

    struct udev *udev;
    std::vector<std::string> usbDevices;
    std::vector<std::string> usbMountPoints;
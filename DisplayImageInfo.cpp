#include<iostream>
#include<fstream>
#include<string>
#include"DisplayImageInfo.h"

#define API_VERSION_NUMBER_MAJOR 1
#define API_VERSION_NUMBER_MINOR 0
#define API_VERSION_NUMBER_PATCH 1

using namespace std;

namespace WPEFramework {
namespace Plugin {
    SERVICE_REGISTRATION(DisplayImageInfo, API_VERSION_NUMBER_MAJOR, API_VERSION_NUMBER_MINOR, API_VERSION_NUMBER_PATCH);

    DisplayImageInfo::DisplayImageInfo() {
    }

    DisplayImageInfo::~DisplayImageInfo() {
    }

    const string DisplayImageInfo::Initialize(PluginHost::IShell* /* service */) {
        getDisplayImageInfo();
        return (string());
    }

    void DisplayImageInfo::Deinitialize(PluginHost::IShell* /* service */) {
    }

    string DisplayImageInfo::Information() const {
        return (string());
    }

   uint32_t getDisplayImageInfo() {
        bool success = false;
        string line;
        fstream file;
        file.open("/version.txt");

        if (file.is_open()) {
            while (getline (file,line)) {
                cout << line << endl;
            }
            file.close();
            success = true;
        }
        return(success);
    }
}
}

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
        TRACE(Trace::Information, (_T("DisplayImageInfo :: Initialize")));
        DisplayImageInfo::getDisplayImageInfo();
        return (string());
    }

    void DisplayImageInfo::Deinitialize(PluginHost::IShell* /* service */) {
        TRACE(Trace::Information, (_T("DisplayImageInfo :: Deinitialize")));
    }

    string DisplayImageInfo::Information() const {
        return (string());
    }

   void DisplayImageInfo::getDisplayImageInfo() {
        string line;
        fstream file;
        file.open("/version.txt");

        if (file.is_open()) {
            while (getline (file,line)) {
            TRACE(Trace::Information, (_T("%s\n"),line.c_str()));
            }
            file.close();
        } else {
              TRACE(Trace::Information, (_T("DisplayImageInfo :: Unable to open file")));
        }
    }
}
}

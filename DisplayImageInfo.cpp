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
    static Core::ProxyPoolType<Web::JSONBodyType<DisplayImageInfo::Data>> jsonResponseFactory(4);

    const string DisplayImageInfo::Initialize(PluginHost::IShell*  service ) {
        TRACE(Trace::Information, (_T("DisplayImageInfo :: Plugin :: Initialize")));
        _skipURL = static_cast<uint8_t>(service->WebPrefix().length());
        return (string());
    }


    void DisplayImageInfo::Deinitialize(PluginHost::IShell* service ) {
        TRACE(Trace::Information, (_T("DisplayImageInfo :: Plugin :: Deinitialize")));
    }

    string DisplayImageInfo::Information() const {
        return (string());
    }

    void DisplayImageInfo::Inbound(Web::Request& /* request */) {
    }

    Core::ProxyType<Web::Response> DisplayImageInfo::Process(const Web::Request& request) {
        TRACE(Trace::Information, (_T("DisplayImageInfo : webRequest : GET method Entry")));
        ASSERT(_skipURL <= request.Path.length());
        Core::ProxyType<Web::Response> result(PluginHost::IFactories::Instance().Response());
        Core::TextSegmentIterator index(Core::TextFragment(request.Path, _skipURL, static_cast<uint32_t>(request.Path.length()) - _skipURL), false, '/');
        index.Next();

        result->ErrorCode = Web::STATUS_OK;
        result->Message = "Ok";
        

        if(request.Verb == Web::Request::HTTP_GET) {
            TRACE(Trace::Information, (_T("DisplayImageInfo : webRequest : Recevied GET method URL")));
            Core::ProxyType<Web::JSONBodyType<Data>> response(jsonResponseFactory.Element());
            index.Next();
            
            if (index.Current().Text() == "imagedetails") {
                string _imageName;
                string _branch;
                string _yoctoversion;
                string _version;
                string _spin;
                string _buildTime;
                string _buildDate; 
            
            getDisplayImageInfo(_imageName, _branch, _yoctoversion, _version, _spin, _buildTime, _buildDate);
           
            response->ImageName = _imageName;
            response->Branch = _branch;
            response->YoctoVersion = _yoctoversion;
            response->Version = _version;
            response->Spin = _spin;
            response->BuildTime = _buildTime;
            response->BuildDate = _buildDate;
            
            result->ContentType = Web::MIMETypes::MIME_JSON;
            result->Body(response);
            
            } else {
                  result->ErrorCode = Web::STATUS_BAD_REQUEST;
                  result->Message = _T("Unsupported request for the [DisplayImageInfo] service.");
              } 
        }
        
            TRACE(Trace::Information, (_T("DisplayImageInfo : webRequest : GET method Exit")));
            return result;
    }

    void DisplayImageInfo::getDisplayImageInfo(string& _imageName, string& _branch, string& _yoctoversion,string& _version, string& _spin, string& _buildTime, string& _buildDate) const {
        fstream file;
        file.open("/version.txt");

        if (file.is_open()) {
            getline (file, _imageName);
            getline (file, _branch);
            getline (file, _yoctoversion);
            getline (file, _version);
            getline (file, _spin);
            getline (file, _buildTime);
            getline (file, _buildDate);
            file.close();
        } else {
              TRACE(Trace::Error, (_T("DisplayImageInfo : Unable to open the file")));
          }
    } 
}
}

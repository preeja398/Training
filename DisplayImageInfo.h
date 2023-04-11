#pragma once
#include"Module.h"
#include <interfaces/json/JsonData_DisplayImageInfo.h>

namespace WPEFramework {
namespace Plugin {
    class DisplayImageInfo:public PluginHost::IPlugin, public PluginHost::IWeb, public PluginHost::JSONRPC {
        public:
            class Data:public Core::JSON::Container {
                public:
                    Data() 
                        : Core::JSON::Container() 
                        ,ImageName()
                        ,Branch()
                        ,YoctoVersion()
                        ,Version()
                        ,Spin()
                        ,BuildTime()
                        ,BuildDate()
                    {
                        Add(_T("imagename"), &ImageName);
                        Add(_T("branch"), &Branch);
                        Add(_T("yoctoversion"), &YoctoVersion);
                        Add(_T("version"), &Version);
                        Add(_T("spin"), &Spin);
                        Add(_T("buildtime"), &BuildTime);
                        Add(_T("builddate"), &BuildDate);
                    }

                     ~Data() {
                    }
                public:
                    Core::JSON::String ImageName;
                    Core::JSON::String Branch;
                    Core::JSON::String YoctoVersion;
                    Core::JSON::String Version;
                    Core::JSON::String Spin;
                    Core::JSON::String BuildTime;
                    Core::JSON::String BuildDate;
            };
        public:
            DisplayImageInfo():_skipURL(0){
                TRACE(Trace::Information, (_T("DisplayImageInfo :: Plugin :: constructor")));
                RegisterAll();
            }

            virtual ~DisplayImageInfo() {
                TRACE(Trace::Information, (_T("DisplayImageInfo :: Plugin :: Destructor")));
                UnregisterAll();
            }

            virtual const string Initialize(PluginHost::IShell* service) override;
            virtual void  Deinitialize(PluginHost::IShell* service) override;
            virtual string Information()const override;

            virtual void Inbound(Web::Request& request) override;
            virtual Core::ProxyType<Web::Response> Process(const Web::Request& request) override;

        public:
            void RegisterAll();
            void UnregisterAll();
            
            uint32_t get_displayimageinfo(JsonData::DisplayImageInfo::DisplayimageinfoData& response) const;
          
            void getDisplayImageInfo(string& _imageName, string& _branch, string& _yoctoversion, string& _version, string& _spin, string& _buildTime, string& _buildDate) const;
            

            BEGIN_INTERFACE_MAP(DisplayImageInfo)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IWeb)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
            END_INTERFACE_MAP

        private:
            uint32_t _skipURL;
    };
}
}

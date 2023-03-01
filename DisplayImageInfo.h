#pragma once
#include"Module.h"

namespace WPEFramework {
namespace Plugin {
    class DisplayImageInfo:public PluginHost::IPlugin {
        private:
            uint32_t getDisplayImageInfo();

        public:
            DisplayImageInfo();
            virtual ~DisplayImageInfo();
            virtual const string Initialize(PluginHost::IShell* service) override;
            virtual void  Deinitialize(PluginHost::IShell* service) override;
            virtual string Information()const override;

            BEGIN_INTERFACE_MAP(DisplayImageInfo)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            END_INTERFACE_MAP
    };
}
}

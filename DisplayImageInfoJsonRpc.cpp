#include "DisplayImageInfo.h"

namespace WPEFramework {

namespace Plugin {

    using namespace JsonData::DisplayImageInfo;

    void DisplayImageInfo::RegisterAll() {
        TRACE(Trace::Information, (_T("DisplayImageInfo : RegisterAll()")));
        Property<DisplayimageinfoData>(_T("imagedetails"), &DisplayImageInfo::get_displayimageinfo, nullptr, this);
    }
   
    void DisplayImageInfo::UnregisterAll() {
        TRACE(Trace::Information, (_T("DisplayImageInfo : UnregisterAll()")));
        Unregister(_T("imagedetails"));
    }
 
    uint32_t DisplayImageInfo::get_displayimageinfo(DisplayimageinfoData& response) const {
        TRACE(Trace::Information, (_T("DisplayImageInfo : get_displayimageinfo()")));
        string _imageName;
        string _branch;
        string _yoctoversion; 
        string _version; 
        string _spin;
        string _buildTime;
        string _buildDate;
        
        getDisplayImageInfo(_imageName,  _branch, _yoctoversion, _version, _spin, _buildTime, _buildDate); 
        
        response.Imagename = _imageName;
        response.Branch = _branch;
        response.Yoctoversion = _yoctoversion;
        response.Version = _version;
        response.Spin = _spin;
        response.Buildtime = _buildTime;
        response.Builddate = _buildDate;
        
        return Core::ERROR_NONE;
    }
}
}

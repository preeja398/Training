
// C++ classes for Display Image Info API JSON-RPC API.
// Generated automatically from 'DisplayImageInfo.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    namespace DisplayImageInfo {

        // Method params/result classes
        //

        class DisplayimageinfoData : public Core::JSON::Container {
        public:
            DisplayimageinfoData()
                : Core::JSON::Container()
            {
                Add(_T("imagename"), &Imagename);
                Add(_T("branch"), &Branch);
                Add(_T("yoctoversion"), &Yoctoversion);
                Add(_T("version"), &Version);
                Add(_T("spin"), &Spin);
                Add(_T("buildtime"), &Buildtime);
                Add(_T("builddate"), &Builddate);
            }

            DisplayimageinfoData(const DisplayimageinfoData&) = delete;
            DisplayimageinfoData& operator=(const DisplayimageinfoData&) = delete;

        public:
            Core::JSON::String Imagename; // Display  current image name
            Core::JSON::String Branch; // Display  current image branch
            Core::JSON::String Yoctoversion; // Display  current image yocto version
            Core::JSON::String Version; // Display  current image version
            Core::JSON::String Spin; // Display  current image spin
            Core::JSON::String Buildtime; // Display  current image built time
            Core::JSON::String Builddate; // Display  current image built date
        }; // class DisplayimageinfoData

    } // namespace DisplayImageInfo

} // namespace JsonData


}


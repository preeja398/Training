#pragma once
#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL ITest : virtual public Core::IUnknown {
        enum { ID = ID_ITest };

        virtual void HelloWorld() = 0;
    };
}
}

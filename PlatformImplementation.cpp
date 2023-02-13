Index: git/DisplayInfo/RPI/PlatformImplementation.cpp
===================================================================
--- git.orig/DisplayInfo/RPI/PlatformImplementation.cpp
+++ git/DisplayInfo/RPI/PlatformImplementation.cpp
@@ -19,6 +19,7 @@
  
 #include "../Module.h"
 #include <interfaces/IDisplayInfo.h>
+#include <interfaces/ITest.h>
 
 #include <bcm_host.h>
 #include <fstream>
@@ -26,7 +27,7 @@
 namespace WPEFramework {
 namespace Plugin {
 
-class DisplayInfoImplementation : public Exchange::IGraphicsProperties, public Exchange::IConnectionProperties {
+class DisplayInfoImplementation : public Exchange::IGraphicsProperties, public Exchange::IConnectionProperties, public Exchange::ITest {
 
 public:
     DisplayInfoImplementation()
@@ -159,11 +160,16 @@ public:
         }
 
         _adminLock.Unlock();
+    } 
+    
+    void HelloWorld() {
+        printf("Hello world\n");
     }
 
     BEGIN_INTERFACE_MAP(DisplayInfoImplementation)
         INTERFACE_ENTRY(Exchange::IGraphicsProperties)
         INTERFACE_ENTRY(Exchange::IConnectionProperties)
+        INTERFACE_ENTRY(Exchange::ITest)
     END_INTERFACE_MAP
 
 private:

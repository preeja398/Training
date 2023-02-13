Index: git/DisplayInfo/DisplayInfo.cpp
===================================================================
--- git.orig/DisplayInfo/DisplayInfo.cpp
+++ git/DisplayInfo/DisplayInfo.cpp
@@ -215,6 +215,8 @@ namespace Plugin {
             displayInfo.Hdrtype = static_cast<JsonData::DisplayInfo::DisplayinfoData::HdrtypeType>(hdrType);
         }
     }
+    ITest *iTest = new ITest();
+    iTest->HelloWorld();
 
 } // namespace Plugin
 } // namespace WPEFramework

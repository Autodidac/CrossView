
#include "EntryPoint_Crossplatform.h"
#include "EntryPoint_Headless.h"
#include "Utilities.h"

#include <memory>

#ifdef _WIN32
    #ifndef _CONSOLE
        #include "EntryPoint_Win32.h"
    #endif
#elif defined(__linux__)
    #include "EntryPoint_X11.h"
#elif defined(__APPLE__)
    #if TARGET_OS_IOS
        #include "EntryPoint_iOS.mm"
    #else
        #include "EntryPoint_Cocoa.mm"
    #endif
#elif defined(__ANDROID__)
    #include "EntryPoint_Android.cpp"
#elif defined(__EMSCRIPTEN__)
    #include "EntryPoint_Emscripten.cpp"
#elif defined(_XBOX)
    #include "EntryPoint_XboxSeriesXS.h"
#elif defined(_PS5)
    #include "EntryPoint_PS5.h"
#endif

namespace almond {

    // Modern Factory vs Singleton, substituting unique_ptr for single instance
    std::unique_ptr<EntryPoint_Crossplatform> EntryPoint_Crossplatform::create() {
        if (isConsoleApplication()) {
            //std::cout << "Creating HeadlessEntryPoint" << std::endl; // Debug output
        #ifdef _CONSOLE
            return std::make_unique<HeadlessEntryPoint>();
        #endif
        }

            // std::cout << "Creating platform-specific entry point" << std::endl; // Debug output

    #ifdef _WIN32
        #ifndef _CONSOLE
                return std::make_unique<Win32EntryPoint>();
        #endif
       
    #elif defined(__linux__)
                return std::make_unique<X11EntryPoint>();
    #elif defined(__APPLE__)
        #if TARGET_OS_IOS
                return std::make_unique<IOSEntryPoint>();
        #else
                return std::make_unique<CocoaEntryPoint>();
        #endif
    #elif defined(__ANDROID__)
            return std::make_unique<AndroidEntryPoint>();
    #elif defined(__EMSCRIPTEN__)
            return std::make_unique<WasmEntryPoint>();
    #elif defined(_XBOX)
            return std::make_unique<XboxEntryPoint>();
    #elif defined(_PS5)
            return std::make_unique<PS5EntryPoint>();
    #else
            static_assert(false, "Platform not supported");
    #endif
        
        return nullptr;
    }
}
 // namespace almond

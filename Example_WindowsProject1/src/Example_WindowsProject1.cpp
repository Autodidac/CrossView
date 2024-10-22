
#include "Example_WindowsProject1.h"
#include "..\..\CrossView\src\CrossView.h"

#include <iostream>

//#pragma comment(linker, "/entry:wWinMainCRTStartup")

struct EntryPointInitializer {
    EntryPointInitializer(int width, int height, const wchar_t* title) {
        almond::EntryPoint entryPoint(width, height, title);
        // Call any other initialization or setup here if needed
    }
};

// Example usage to trigger initialization
EntryPointInitializer init(800, 600, L"Game Title");


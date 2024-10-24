<img align="left" src="image/1.jpg" width="100px"/>


# CrossView - Minimal Modern Cross-Platform Window (OS Entry Point) Management System Library in C++20
CrossView is a cross-platform library designed for creating and managing windows across multiple platforms. It abstracts platform-specific window (OS Entry Point) management code into a unified interface, allowing you to create and manipulate windows in a platform-agnostic way. 


<img align="left" src="image/gpt.jpg" width="40px"/>GPT-4



## Features


- Cross-platform support for Windows, macOS, Linux, Android, iOS, WebAssembly, PS5, Xbox, and a No-op/Console mode.
- Window Creation and Management.
- Platform-specific implementation details hidden behind a common interface.
- Namespace 'CrossViewer' Prevents Global Code Leaks
- C++20 and Factory Pattern Design
- Platform-Specific Factories - Oh yeah did I mention it has FACTORIES?! :D
- Memory Management and Error Handling
You’re using std::unique_ptr to manage the CrossView object, which is a safe and efficient choice.

- Split-Screen and VR Features
In CrossViewNoop, the setSplitScreen and setupVR methods are stubbed out. Ensure that these features are appropriately implemented in the platform-specific classes where applicable.



## Tested

- Tested in Windows 10/11 With Console headless and WindowsDesktopApplication + headless mode.

<img align="left" src="image/1.png" width="200px"/>

<img align="left" src="image/4.png" width="200px"/>

```cpp



## Supported Platforms

- **Windows** (Win32)
- **macOS** (Cocoa)
- **Linux** (XCB or XLib)
- **Android**
- **iOS** (UIKit)
- **WebAssembly** (Emscripten)
- **PlayStation 5** (PS5)
- **Xbox**
- **No-op** (Headless mode)
```



## Installation



### Prerequisites

- C++20 or later
- CMake 3.10 or later



### Building

1. Clone the repository:
```sh
   git clone https://github.com/Autodidac/CrossView.git
   cd CrossView
```





### Build using WIN32 (Windows 11 64bit) and vs2022:
Simply run the provided vs solution file `CrossView.sln` in the main folder




### Generate build files using CMake:
Run cmake to generate the build files, then compile:





### Build the project:
Basic Build:
```sh
mkdir build
cd build
cmake ..
cmake --build .
```
Enable Headless Mode:

To build with headless mode enabled, pass the option when running cmake:
```sh
cmake .. -DENABLE_HEADLESS=ON
cmake --build .
```
Run:

After building, you can run the generated executable. If you built with headless mode, the console window will be allocated as needed.




### Usage


##### Example Console Batch
```batch
@echo off
CrossViewExample.exe --headless
pause
```


##### Example
```cpp
#include "CrossView.h"

int main() {
    auto crossView = CrossViewer::CrossView::createCrossView();
    if (crossView->init()) {
        crossView->createWindow(L"Example Window", 800, 600);
        // Main loop or additional logic here
        crossView->shutdown();
    }
    return 0;
}
```


### Example Implementation (for Win32)
```cpp
#include "CrossViewWin32.h"  // Platform-specific include

namespace CrossViewer {

    std::unique_ptr<CrossView> CrossView::createCrossView() {
#if defined(_WIN32)  // Platform check
        return std::make_unique<CrossViewWin32>();
#else
        return std::make_unique<CrossViewNoop>();  // Fallback or other platform-specific class
#endif
    }

}
```


### API Reference

```cpp
CrossViewer::CrossView
static std::unique_ptr<CrossView> createCrossView()
bool init()
bool createWindow(const wchar_t* title, int width, int height)
void shutdown()

```



### Platform-specific Implementations
The platform-specific implementation files are organized into separate source files. Each implementation file contains the initialization, window creation, and shutdown code for a specific platform.

-Windows: `CrossViewWin32.cpp` and `CrossViewWin32.h`

-macOS: `CrossViewMac.cpp` and `CrossViewMac.h`

-Linux: `CrossViewLinux.cpp` and `CrossViewLinux.h`

-Android: `CrossViewAndroid.cpp` and `CrossViewAndroid.h`

-iOS: `CrossViewIOS.cpp` and `CrossViewIOS.h`

-WebAssembly: `CrossViewWebAssembly.cpp` and `CrossViewWebAssembly.h`

-PlayStation 5: `CrossViewPS5.cpp` and `CrossViewPS5.h`

-Xbox: `CrossViewXbox.cpp` and `CrossViewXbox.h`

-No-op mode: `CrossViewNoop.cpp` and `CrossViewNoop.h`





### License
This project is licensed under the MIT License. See the LICENSE file for details.




### Contributing
Contributions are welcome! Please see the CONTRIBUTING.md file for guidelines.




## Acknowledgements
This project was developed with the support of OpenAI's GPT-4, which provided valuable assistance in generating code and design ideas. We appreciate the power and capabilities of GPT-4 in aiding the creation of this project.



<img align="left" src="image/2.jpg" width="80px"/>
<img align="center" src="image/gpt4all.png" width="80px"/>

CrossView - A GPT4 Crossplatform Library For All! Almost Entirely Built and Designed by AI - Even much of this readme and the CMakeLists.txt are written by GPT-4.. what a wonderful tool Thank You Again!



-Also Shout Out to [CrossWindow](https://github.com/alaingalvan/CrossWindow) - Referenced Project and Alternate Library using C++11-17.




//#include "pch.h"
#include "Coroutine.h"
#include "EntryPoint.h"
#include "EntryPoint_Headless.h"
#include "ThreadPool.h"

// for windows.h
//#include "framework.h"

#ifdef _CONSOLE

// Game logic coroutine function
inline almond::Coroutine gameLogicCoroutine() {
    for (int i = 0; i < 5; ++i) {
        co_yield i; // Yield game logic frame state
    }
}

// Coroutine for simulating physics updates
inline almond::Coroutine physicsCoroutine() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Physics update (coroutine)..." << std::endl;
        co_yield i;
    }
}

// Coroutine for simulating audio updates
inline almond::Coroutine audioCoroutine() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Audio update (coroutine)..." << std::endl;
        co_yield i;
    }
}

// Coroutine for simulating game system updates
inline almond::Coroutine gameSystemCoroutine() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Game system update (coroutine)..." << std::endl;
        co_yield i;
    }
}

//int main() {

    /*
    // Create the entry point for the headless or windowed application
    almond::EntryPoint entryPoint(1280, 720, L"Almond Engine - Console Application");
    entryPoint.show();       // Show the application window (for GUI)
    entryPoint.pollEvents(); // Poll input events (for GUI or headless input)

    // Example coroutine instances for different systems
    auto gameLogic = gameLogicCoroutine();
    auto physics = physicsCoroutine();
    auto audio = audioCoroutine();
    auto gameSystem = gameSystemCoroutine();

    // Initialize the thread pool for more resource-heavy tasks if needed
    ThreadPool threadPool(std::thread::hardware_concurrency() - 1);

    // Main loop for coroutine-based game logic, physics, audio, etc.
    try {
        while (gameLogic.resume() || physics.resume() || audio.resume() || gameSystem.resume()) {
            // Output coroutine result for game logic
            std::cout << "Game logic yielded: " << gameLogic.current_value() << std::endl;

            // Simulate a frame sleep for 60 FPS
            std::this_thread::sleep_for(std::chrono::milliseconds(16));

            // Optionally, use thread pool for heavy tasks like loading resources
            threadPool.enqueue([] {
                std::cout << "Heavy asset loading on thread." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulating work
                });
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;*/
//}

//#endif


// Example coroutine function
inline almond::Coroutine exampleCoroutine() {
    for (int i = 0; i < 5; ++i) {
        co_yield i; // This pauses the coroutine and returns `i`
    }
}
/*
int main() {
    try {
        auto coroutine = exampleCoroutine();

        // Resume the coroutine until it's done
        while (coroutine.resume()) {
            std::cout << "Coroutine yielded: " << coroutine.current_value() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
*/
int main() {

    std::cout << "running!\n";

    while(true)
    {
        //printf("running!!!!!!!!");
    }
    /*
    
    almond::EntryPoint entryPoint(1280, 720, L"Almond Engine - Console Application");
    entryPoint.show();       // Show the application window (for GUI)
    entryPoint.pollEvents(); // Poll input events (for GUI or headless input)

    // Initialize the thread pool with hardware concurrency minus 1 thread
    ThreadPool threadPool(std::thread::hardware_concurrency() - 1);

    // Example: Running a coroutine
    try {
        auto coroutine = exampleCoroutine(); // Coroutine for game logic

        // Resume the coroutine until it's done
        while (coroutine.resume()) {
            std::cout << "Coroutine yielded: " << coroutine.current_value() << std::endl;

            // Offload tasks to thread pool
            threadPool.enqueue([] {
                std::cout << "Physics update on thread." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate physics
            });

            threadPool.enqueue([] {
                std::cout << "Audio update on thread." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(30)); // Simulate audio
            });

            threadPool.enqueue([] {
                std::cout << "Game system task on thread." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Simulate systems
            });
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;*/
}
#endif


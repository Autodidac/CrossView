#include <iostream>
#include <stdexcept>
#include <memory>
#include <thread>
#include "..\..\CrossView\src\CrossView.h" // Ensure this includes your EntryPoint header

namespace almond {
    class EntryPoint; // Forward declaration if needed
}

// Structure to handle initialization and run logic
struct EntryPointInitializer {
    EntryPointInitializer(int width, int height, const wchar_t* title) {
    }
};

// Example usage to trigger initialization
EntryPointInitializer init(800, 600, L"Game Title");

// No explicit int main() is required here

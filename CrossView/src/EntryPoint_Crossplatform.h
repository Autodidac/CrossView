#pragma once

#include <memory>

namespace almond {
    class EntryPoint_Crossplatform {
    public:
        virtual ~EntryPoint_Crossplatform() = default;

        // Platform-specific functions must implement these
        virtual void createEntryPoint(int width, int height, const wchar_t* title) = 0;
        virtual void show() = 0;
        virtual bool pollEvents() = 0;

        // Cross-platform functionality
        static std::unique_ptr<EntryPoint_Crossplatform> create();
    };
}

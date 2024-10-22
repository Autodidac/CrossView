#pragma once

#include "EntryPoint_Crossplatform.h"
#include <memory>
#include <stdexcept>

namespace almond {

    class EntryPoint {
    public:
        EntryPoint(int width, int height, const wchar_t* title) {
            entryPoint = EntryPoint_Crossplatform::create();
            if (!entryPoint) {
                throw std::runtime_error("Failed to create EntryPoint_Crossplatform instance.");
            }
            entryPoint->createEntryPoint(width, height, title);
        }

        void show() {
            if (entryPoint) {
                entryPoint->show();
            }
        }

        bool pollEvents() {
            return entryPoint ? entryPoint->pollEvents() : false;
        }

    private:
        std::unique_ptr<EntryPoint_Crossplatform> entryPoint;
    };

} // namespace almond

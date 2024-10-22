#pragma once 

#include "EntryPoint_Crossplatform.h"
#include "Utilities.h"

namespace almond {
    class HeadlessEntryPoint : public EntryPoint_Crossplatform {
    public:
        void createEntryPoint(int width, int height, const wchar_t* title) override {}

        void show() override {}

        bool pollEvents() override {
            return false;
        }
    };
}
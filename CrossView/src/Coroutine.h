#pragma once

#include <coroutine>
#include <iostream>
#include <exception>

namespace almond {
    class Coroutine {
    public:
        struct promise_type {
            Coroutine get_return_object() {
                return Coroutine{ std::coroutine_handle<promise_type>::from_promise(*this) };
            }

            std::suspend_always initial_suspend() { return {}; }
            std::suspend_always final_suspend() noexcept { return {}; }

            void unhandled_exception() {
                std::cerr << "Unhandled exception in coroutine." << std::endl;
                std::exit(1);
            }

            void return_void() {}

            std::suspend_always yield_value(int value) {
                currentValue = value;
                return {};
            }

            int currentValue;
        };

        using handle_type = std::coroutine_handle<promise_type>;

        Coroutine(handle_type h) : handle(h) {}

        // Move constructor and assignment
        Coroutine(Coroutine&& other) noexcept : handle(other.handle) {
            other.handle = nullptr; // Avoid double destruction
        }

        Coroutine& operator=(Coroutine&& other) noexcept {
            if (this != &other) {
                if (handle) handle.destroy(); // Clean up current coroutine
                handle = other.handle;
                other.handle = nullptr; // Avoid double destruction
            }
            return *this;
        }

        ~Coroutine() { if (handle) handle.destroy(); }

        // Resume the coroutine
        bool resume() {
            if (handle) {
                handle.resume();
                return !handle.done();
            }
            return false;
        }

        int current_value() const {
            return handle.promise().currentValue;
        }

    private:
        handle_type handle;
    };
}

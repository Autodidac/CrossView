#pragma once

#include <atomic>
#include <vector>
#include <optional>

template<typename T>
class WaitFreeQueue {
public:
    explicit WaitFreeQueue(size_t capacity);

    bool enqueue(const T& item); // Add an item to the queue
    bool dequeue(T& item);       // Remove an item from the queue

private:
    std::vector<std::optional<T>> buffer;  // Buffer for queue items
    std::atomic<size_t> head;               // Head index
    std::atomic<size_t> tail;               // Tail index
};

template<typename T>
WaitFreeQueue<T>::WaitFreeQueue(size_t capacity)
    : buffer(capacity), head(0), tail(0) {}

template<typename T>
bool WaitFreeQueue<T>::enqueue(const T& item) {
    size_t currentTail = tail.load(std::memory_order_relaxed); // Load tail index
    size_t nextTail = (currentTail + 1) % buffer.size();      // Calculate next tail

    if (nextTail == head.load(std::memory_order_acquire)) {
        return false; // Queue full
    }

    buffer[currentTail] = item;                               // Place item in the buffer
    tail.store(nextTail, std::memory_order_release);          // Update tail
    return true;
}

template<typename T>
bool WaitFreeQueue<T>::dequeue(T& item) {
    size_t currentHead = head.load(std::memory_order_relaxed); // Load head index

    if (currentHead == tail.load(std::memory_order_acquire)) {
        return false; // Queue empty
    }

    if (buffer[currentHead].has_value()) {
        item = std::move(buffer[currentHead].value());  // Move item from the buffer
        buffer[currentHead].reset();                   // Clear the value
        head.store((currentHead + 1) % buffer.size(), std::memory_order_release); // Update head
        return true;
    }

    return false;
}

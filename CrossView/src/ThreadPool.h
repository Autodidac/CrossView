#pragma once

#include "WaitFreeQueue.h"

#include <atomic>
#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>

class ThreadPool {
public:
    explicit ThreadPool(size_t threadCount);
    ~ThreadPool();

    void enqueue(std::function<void()> job);

private:
    void workerThread(); // Worker function for threads

    std::vector<std::thread> workers; // Worker threads
    WaitFreeQueue<std::function<void()>> jobQueue; // Job queue
    std::atomic<bool> isRunning; // Running status
};

ThreadPool::ThreadPool(size_t threadCount)
    : jobQueue(threadCount), isRunning(true) {
    for (size_t i = 0; i < threadCount; ++i) {
        workers.emplace_back(&ThreadPool::workerThread, this);
    }
}

ThreadPool::~ThreadPool() {
    isRunning = false; // Stop accepting new jobs
    for (auto& worker : workers) {
        worker.join(); // Wait for all worker threads to finish
    }
}

void ThreadPool::enqueue(std::function<void()> job) {
    jobQueue.enqueue(std::move(job)); // Enqueue the job
}

void ThreadPool::workerThread() {
    while (isRunning) {
        std::function<void()> job;
        if (jobQueue.dequeue(job)) {
            if (job) {   // Ensure job is valid before invoking
                job();   // Execute the job
            }
        } else {
            std::this_thread::yield(); // Yield CPU if no job is available
        }
    }
}


#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <queue>
#include <mutex>
#include "Process.hpp"

class Scheduler {
private:
    std::queue<Process> readyQueue;
    mutable std::mutex queueMutex; // Protects the ready queue from race conditions

public:
    void addProcess(const Process& proc);
    bool hasProcesses() const;
    
    // Thread-safe atomic fetch to prevent multi-core race conditions
    bool tryGetNextProcess(Process& proc);
    
    void requeueProcess(const Process& proc);
    size_t getQueueSize() const;
};

#endif

#include "Scheduler.hpp"

void Scheduler::addProcess(const Process& proc) {
    std::lock_guard<std::mutex> lock(queueMutex);
    readyQueue.push(proc);
}

bool Scheduler::hasProcesses() const {
    std::lock_guard<std::mutex> lock(queueMutex);
    return !readyQueue.empty();
}

bool Scheduler::tryGetNextProcess(Process& proc) {
    std::lock_guard<std::mutex> lock(queueMutex);
    if (readyQueue.empty()) return false;
    proc = readyQueue.front();
    readyQueue.pop();
    return true;
}

void Scheduler::requeueProcess(const Process& proc) {
    std::lock_guard<std::mutex> lock(queueMutex);
    readyQueue.push(proc);
}

size_t Scheduler::getQueueSize() const {
    std::lock_guard<std::mutex> lock(queueMutex);
    return readyQueue.size();
}

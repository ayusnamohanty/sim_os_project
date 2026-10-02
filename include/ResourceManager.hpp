#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <mutex>
#include <iostream>

class ResourceManager {
private:
    int totalResources;
    int availableResources;
    std::mutex resourceMutex; // Mutex to ensure thread-safe resource allocation

public:
    // Constructor
    ResourceManager(int total);

    // Try to allocate resources for a process
    bool allocate(int count, int pid);

    // Release resources back to the system
    void release(int count, int pid);

    // Getters
    int getAvailableResources() const;
};

#endif

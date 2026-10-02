#include "ResourceManager.hpp"

ResourceManager::ResourceManager(int total) 
    : totalResources(total), availableResources(total) {}

bool ResourceManager::allocate(int count, int pid) {
    std::lock_guard<std::mutex> lock(resourceMutex); // Thread-safe locking
    if (availableResources >= count) {
        availableResources -= count;
        std::cout << "[Resource Manager] PID " << pid << " successfully acquired " << count << " resources. Remaining: " << availableResources << "\n";
        return true;
    }
    std::cout << "[Resource Manager] PID " << pid << " FAILED to acquire " << count << " resources. (Not enough available)\n";
    return false;
}

void ResourceManager::release(int count, int pid) {
    std::lock_guard<std::mutex> lock(resourceMutex); // Thread-safe locking
    availableResources += count;
    if (availableResources > totalResources) {
        availableResources = totalResources;
    }
    std::cout << "[Resource Manager] PID " << pid << " released " << count << " resources. Available now: " << availableResources << "\n";
}

int ResourceManager::getAvailableResources() const {
    return availableResources;
}

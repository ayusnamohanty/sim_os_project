#include <iostream>
#include <vector>
#include <thread>
#include "Process.hpp"
#include "Scheduler.hpp"
#include "ResourceManager.hpp"

// Function executed by each independent CPU core thread
void cpuCoreWorker(int coreId, Scheduler& scheduler, ResourceManager& resourceManager) {
    Process currentProc(0, "", 0, 0);

    while (scheduler.hasProcesses()) {
        if (scheduler.tryGetNextProcess(currentProc)) {
            currentProc.setState(ProcessState::RUNNING);

            std::cout << "[CPU Core " << coreId << "] Executing -> ";
            currentProc.printProcessInfo();

            if (resourceManager.allocate(2, currentProc.getPid())) {
                currentProc.reduceRemainingTime(3);
                resourceManager.release(2, currentProc.getPid());
            } else {
                currentProc.reduceRemainingTime(2);
            }

            if (currentProc.getRemainingTime() > 0) {
                currentProc.setState(ProcessState::READY);
                std::cout << "[Scheduler] Core " << coreId << " requeueing PID " << currentProc.getPid() << "\n";
                scheduler.requeueProcess(currentProc);
            } else {
                currentProc.setState(ProcessState::TERMINATED);
                std::cout << "[SimOS] Process " << currentProc.getPid() << " (" << currentProc.getName() << ") has TERMINATED on Core " << coreId << ".\n";
            }
        }
        std::this_thread::yield();
    }
}

int main() {
    std::cout << "=== Starting SimOS Multi-Core Threaded Scheduler & Resource Manager ===\n\n";

    Scheduler cpuScheduler;
    ResourceManager resourceManager(5);

    std::vector<Process> initialProcesses = {
        Process(101, "Process_Alpha", 6, 2),
        Process(102, "Process_Beta", 4, 1),
        Process(103, "Process_Gamma", 8, 3),
        Process(104, "Process_Delta", 5, 2),
        Process(105, "Process_Epsilon", 7, 1)
    };

    for (const auto& p : initialProcesses) {
        cpuScheduler.addProcess(p);
        std::cout << "[SimOS] Loaded " << p.getName() << " (PID: " << p.getPid() << ") into Ready Queue.\n";
    }

    std::cout << "\n=== Spawning Multi-Core CPU Threads (3 Concurrent Cores) ===\n\n";

    std::vector<std::thread> cpuCores;
    int numCores = 3;

    for (int i = 1; i <= numCores; ++i) {
        cpuCores.emplace_back(cpuCoreWorker, i, std::ref(cpuScheduler), std::ref(resourceManager));
    }

    for (auto& core : cpuCores) {
        core.join();
    }

    std::cout << "\n=== SimOS Multi-Core Simulation Completed Successfully ===\n";
    return 0;
}

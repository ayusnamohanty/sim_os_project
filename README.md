# SimOS - Multi-Core Operating System Simulator

**SimOS** is an advanced, multi-threaded Operating System simulator built from scratch in modern **C++17**. It models foundational kernel-level operations—including concurrent multi-core CPU execution, a thread-safe task scheduling queue, process lifecycle management, and system resource allocation—ensuring robust performance and zero data races.

---

## 🚀 Key Features

1. **Multi-Core CPU Simulation**
   - Spawns independent worker threads using C++17 threading primitives to simulate concurrent execution across multiple physical CPU cores.
2. **Thread-Safe Process Scheduling**
   - Implements a central task dispatch queue protected by synchronization primitives (`std::mutex`, locks) to completely eliminate race conditions and prevent multiple cores from colliding over tasks.
3. **Process Lifecycle & State Tracking**
   - Manages dynamic process state transitions (`Ready` $\rightarrow$ `Running` $\rightarrow$ `Terminated`) with unique Process IDs (PIDs), priorities, and execution tracking.
4. **System Resource Manager (`ResourceManager`)**
   - Simulates hardware and system resource allocation, ensuring safe distribution and reclamation of system blocks during active processing.
5. **Rigorous Quality & Stability Testing**
   - Extensively tested and verified using **Valgrind** to guarantee 100% memory safety with **zero memory leaks** and **0 error contexts**.

---

## 📂 Project Directory Structure

```text
sim_os_project/
│
├── include/
│   ├── Process.hpp          # Process metadata and state definitions
│   ├── Scheduler.hpp        # Thread-safe queue and scheduling logic
│   └── ResourceManager.hpp  # System resource allocation handler
│
├── src/
│   ├── Process.cpp          # Process lifecycle implementation
│   ├── Scheduler.cpp        # Concurrency and queue control
│   ├── ResourceManager.cpp  # Resource tracking and release logic
│   └── main.cpp             # Entry point, multi-core thread spawner
│
├── Makefile                 # Automated build and compilation pipeline
└── README.md                # Project documentation

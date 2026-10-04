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

🛠️️ Build and Run Instructions
Prerequisites
A Linux environment (Ubuntu / WSL)

GNU C++ Compiler (g++) with C++17 support

make utility

1. Clone & Navigate to Project
Bash
cd ~/sim_os_project
2. Compile the Project
Clean any cached binaries and build fresh using the Makefile:

Bash
make clean
make
3. Run the Simulation
Execute the compiled binary:

Bash
./sim_os
🧪 Testing & Diagnostics
To prove system stability, memory safety, and thread concurrency to reviewers:

Memory Leak Verification (Valgrind):

Bash
valgrind --leak-check=full ./sim_os
Result: Confirmed 0 errors and All heap blocks were freed -- no leaks are possible.

Concurrency & Race Condition Control:
Protected by robust mutual exclusion locks ensuring secure multi-core thread synchronization.

💡 Technical Concepts Demonstrated
Systems Programming: Low-level kernel mechanics, CPU scheduling, and resource control.

Concurrency & Synchronization: Mutex locking, critical sections, and thread safety in C++17.

Memory Management: Dynamic allocation, scope tracking, and leak-free resource handling.

Build Automation: Custom Makefile compilation pipelines.

👤 Author
Ayusna Mohanty

B.Tech in Computer Science and Engineering

Institute of Technical Education & Research (ITER), SOA University


---

### How to update it on GitHub:
1. Go back to your GitHub repository page where your `README.md` is.
2. Click the **pencil (Edit)** icon on the right side above the README contents.
3. Select everything currently inside, delete it, and **paste** the markdown code block provided above.
4. Click the green **Commit changes...** button in the top right, and click commit again. Your profile and repository will instantly look world-class!

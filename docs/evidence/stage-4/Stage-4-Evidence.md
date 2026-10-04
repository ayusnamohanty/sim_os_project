# Stage 4 – Progress Evidence

## Project

SimOS – Multi-Core Operating System Simulator

## Stage

Stage 4 – Initial Implementation & Prototype

---

## Evidence 1 – Core Implementation

The core modules of the SimOS simulator have been implemented using C++.

The implementation includes:

- Process Management
- Scheduler
- Resource Manager
- Multi-Core CPU execution
- Main Simulation Controller

These modules are integrated to provide the initial working prototype.

---

## Evidence 2 – Project Build

The project was built using the Make build system.

Command used:

```text
make

The terminal reported:

make: Nothing to be done for 'all'.

This indicates that the project was already compiled and no source changes
required a new build.

Evidence 3 – Prototype Execution

The SimOS prototype was successfully executed using:

./sim_os

The simulator completed the multi-core simulation successfully.

Final output:

=== SimOS Multi-Core Simulation Completed Successfully ===
Evidence 4 – Multi-Core Execution

The prototype demonstrates execution using multiple CPU cores.

Example:

[CPU Core 3] Executing -> [Process] ID: 105 | Name: Process_Epsilon

The output confirms that a process was assigned to a specific CPU core
during simulation.

Evidence 5 – Process Scheduling

The Scheduler successfully selects processes and assigns them to CPU cores.

The prototype also demonstrates process re-queuing when the process has
remaining execution time.

Example:

[Scheduler] Core 3 requeueing PID 105

This demonstrates that an incomplete process can return to the scheduler
for further execution.

Evidence 6 – Resource Management

The Resource Manager successfully allocates and releases resources during
process execution.

Example:

[Resource Manager] PID 105 successfully acquired 2 resources. Remaining: 3

[Resource Manager] PID 105 released 2 resources. Available now: 5

This confirms that resource allocation and release are integrated into the
process execution flow.

Evidence 7 – Process Termination

The prototype successfully detects process completion.

Example:

[SimOS] Process 105 (Process_Epsilon) has TERMINATED on Core 3.

This confirms that the process reaches the terminated state after completing
its required execution.

Evidence 8 – Complete Simulation

The complete SimOS simulation runs from process execution through process
termination.

The final output confirms successful completion:

=== SimOS Multi-Core Simulation Completed Successfully ===
Evidence 9 – Stage 4 Functional Verification

The following functionality was verified:

 Core C++ modules implemented
 Project builds successfully
 SimOS executable runs successfully
 Processes are scheduled
 Multiple CPU cores execute processes
 Resources are allocated
 Resources are released
 Processes are re-queued
 Processes terminate successfully
 Complete simulation finishes successfully
Evidence 10 – Issues and Solutions
Issue

The project initially required verification after implementation to ensure
that the existing executable and build system were working correctly.

Solution

The project was checked using the Make build system and the simulator was
executed directly.

The build reported that there was nothing new to compile, and the simulator
ran successfully to completion.

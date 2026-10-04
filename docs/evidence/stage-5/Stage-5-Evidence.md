# Stage 5 – Progress Evidence

## Project

SimOS – Multi-Core Operating System Simulator

## Stage

Stage 5 – Testing, Integration & Improvement

---

## Evidence 1 – System Test Execution

The complete SimOS simulator was executed successfully using:

```text
./sim_os

The simulation completed without stopping before process completion.

Final output:

=== SimOS Multi-Core Simulation Completed Successfully ===
Evidence 2 – Multi-Core Execution

The test demonstrated process execution across multiple CPU cores.

Examples observed during testing:

[CPU Core 2] Executing -> Process_Beta
[CPU Core 3] Executing -> Process_Delta
[CPU Core 1] Executing -> Process_Epsilon

This confirms that multiple CPU cores participate in the simulation.

Evidence 3 – Scheduler Testing

The Scheduler successfully selected processes and assigned them to CPU cores.

The test also demonstrated process re-queuing.

Example:

[Scheduler] Core 1 requeueing PID 105

This confirms that an incomplete process can return to the ready queue for
continued execution.

Evidence 4 – Resource Manager Testing

Resource allocation and release were successfully verified.

Example:

[Resource Manager] PID 102 successfully acquired 2 resources. Remaining: 3
[Resource Manager] PID 102 released 2 resources. Available now: 5

The resource count returned to the available state after release.

Evidence 5 – Process Termination Testing

Multiple processes successfully reached the terminated state.

Examples:

[SimOS] Process 102 (Process_Beta) has TERMINATED on Core 2.
[SimOS] Process 104 (Process_Delta) has TERMINATED on Core 3.
[SimOS] Process 103 (Process_Gamma) has TERMINATED on Core 2.
[SimOS] Process 105 (Process_Epsilon) has TERMINATED on Core 1.

This confirms successful process completion and termination.

Evidence 6 – Process Re-Queue Testing

Process 105 was observed being re-queued because it still had remaining
execution time.

Example:

[Scheduler] Core 1 requeueing PID 105

The process was subsequently executed again:

[CPU Core 1] Executing -> [Process] ID: 105 | Name: Process_Epsilon | Remaining Time: 4 | Priority: 1

The process continued execution until its remaining time reached completion.

Evidence 7 – Integration Testing

The following major components were verified together:

Process Management
Scheduler
CPU Cores
Resource Manager

The successful end-to-end execution demonstrates that these components
are integrated correctly for the tested simulation.

Evidence 8 – Issue Identified

During concurrent execution, some terminal output appeared interleaved.

An example from the captured test output was:

7 | Priority: 1

This appears to be caused by multiple CPU threads writing to the terminal
concurrently.

The simulation itself continued successfully and the affected processes
completed execution.

Evidence 9 – Improvement Identified

A possible improvement is to synchronize console output using a mutex.

This would ensure that messages from different CPU threads are printed as
complete lines.

Expected benefits include:

Improved console readability
Easier debugging
Clearer testing evidence
Better monitoring of concurrent execution
Evidence 10 – Testing Summary
Test	Result
Process Management	Passed
Scheduler	Passed
Multi-Core Execution	Passed
Resource Allocation	Passed
Resource Release	Passed
Process Re-Queue	Passed
Process Termination	Passed
End-to-End Simulation	Passed
Console Output	Improvement Identified

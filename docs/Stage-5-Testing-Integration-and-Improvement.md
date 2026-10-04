# Stage 5 – Testing, Integration and Improvement

## 1. Project

SimOS – Multi-Core Operating System Simulator

## 2. Stage

Stage 5 – Testing, Integration & Improvement

## 3. Stage Objective

The objective of Stage 5 is to test the implemented SimOS prototype,
verify the integration of its major components, identify issues, and
improve the reliability and quality of the system.

The testing focuses on:

- Unit-level functionality
- Component integration
- Complete system execution
- Process scheduling
- Multi-core execution
- Resource management
- Process termination
- Reliability of the simulation

## 4. Testing Environment

Testing was performed using:

- Linux / Ubuntu
- C++ programming language
- GNU C++ compiler
- Make build system
- Git and GitHub

The simulator was executed using:

```text
./sim_os
5. Unit-Level Testing

The major components of the simulator were verified through their behavior
during execution.

Process Management

Process information was successfully created and processed by the simulator.

The output displayed:

Process ID
Process name
Remaining execution time
Priority
Process termination status
Scheduler

The Scheduler was verified by observing process selection, CPU assignment,
and process re-queuing.

Example:

[Scheduler] Core 1 requeueing PID 105

This confirms that a process with remaining execution time can be returned
to the scheduler for further execution.

Resource Manager

The Resource Manager was tested by observing resource allocation and release.

Example:

[Resource Manager] PID 105 successfully acquired 2 resources. Remaining: 3
[Resource Manager] PID 105 released 2 resources. Available now: 5

The output confirms that resources are allocated and subsequently released.

6. Integration Testing

Integration testing verifies that the major SimOS components work together.

The following components were integrated:

Process Management
        |
        v
Scheduler
        |
        v
CPU Cores
        |
        v
Resource Manager
        |
        v
Process Completion

The successful simulation demonstrates that these components can operate
together during the same execution.

7. Multi-Core System Testing

The simulator was tested using multiple CPU cores.

The test output demonstrated processes executing on different cores.

Examples include:

[CPU Core 2] Executing -> Process_Beta
[CPU Core 3] Executing -> Process_Delta
[CPU Core 1] Executing -> Process_Epsilon

This confirms that the multi-core execution functionality is active.

8. Process Re-Queue Testing

The simulator was tested with processes whose execution time was greater
than a single execution cycle.

For example:

[Scheduler] Core 1 requeueing PID 105

Process 105 was subsequently executed again:

[CPU Core 1] Executing -> [Process] ID: 105 | Name: Process_Epsilon | Remaining Time: 4 | Priority: 1

The process was re-queued again until its remaining execution time reached
completion.

9. Resource Allocation Testing

Resource allocation was tested during process execution.

The simulator successfully demonstrated:

Resource acquired
        |
        v
Process execution
        |
        v
Resource released

Example:

[Resource Manager] PID 102 successfully acquired 2 resources. Remaining: 3
[Resource Manager] PID 102 released 2 resources. Available now: 5

The available resource count returned to 5 after release.

10. Process Termination Testing

Process termination was verified for multiple processes.

Examples from the test run include:

[SimOS] Process 102 (Process_Beta) has TERMINATED on Core 2.
[SimOS] Process 104 (Process_Delta) has TERMINATED on Core 3.
[SimOS] Process 103 (Process_Gamma) has TERMINATED on Core 2.
[SimOS] Process 105 (Process_Epsilon) has TERMINATED on Core 1.

This demonstrates that processes successfully reach the terminated state
after completing their execution.

11. System Testing

The complete simulator was executed as an end-to-end system test.

The test verified:

Process creation
Scheduling
CPU core assignment
Resource allocation
Process execution
Resource release
Process re-queuing
Process termination
Simulation completion

The final output was:

=== SimOS Multi-Core Simulation Completed Successfully ===

This confirms that the complete simulation executed successfully.

12. Issue Identified During Testing

During concurrent execution, some terminal output lines may appear
interleaved because multiple CPU core threads write to the console at the
same time.

For example, one captured output contained a partial/interleaved line:

7 | Priority: 1

This does not by itself indicate that process execution failed. The
remaining simulation continued successfully and all observed processes
terminated.

13. Improvement Consideration

The concurrent console output can be improved by introducing synchronized
console output.

A shared output mechanism protected by a mutex can ensure that each log
message is printed as a complete line.

This would improve:

Console readability
Debugging
Progress monitoring
Reliability of development evidence

This improvement can be considered as part of the code-quality refinement
of the simulator.

14. Reliability Verification

The simulator successfully completed the test execution without stopping
before process completion.

The following behavior was observed:

Processes executed on multiple CPU cores.
Resources were acquired successfully.
Resources were released after execution.
Incomplete processes were re-queued.
Processes eventually terminated.
The complete simulation reached the successful completion message.
15. Testing Summary
Test Area	Result
Process Management	Passed
Scheduler	Passed
Multi-Core Execution	Passed
Resource Allocation	Passed
Resource Release	Passed
Process Re-Queue	Passed
Process Termination	Passed
End-to-End Simulation	Passed
Console Output Readability	Improvement identified
16. Stage 5 Completion Criteria

Stage 5 is considered complete when:

Unit-level functionality is tested.
Component integration is tested.
Complete system execution is tested.
Process scheduling is verified.
Multi-core execution is verified.
Resource allocation and release are verified.
Process termination is verified.
Issues are identified and documented.
Improvement opportunities are documented.
Testing evidence is recorded.
Documentation is updated.
Changes are committed to Git.
17. Conclusion

Stage 5 testing confirms that the major SimOS components operate together
as an integrated multi-core simulation.

The testing demonstrated successful process scheduling, multi-core
execution, resource management, process re-queuing, and process
termination.

A console-output synchronization improvement was identified to make
multi-threaded logging clearer and easier to debug.

The project is now ready for final implementation, refinement, and
presentation in Stage 6

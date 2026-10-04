# SimOS – Sequence Diagram

## Process Execution Sequence

```text
+------+       +-----------+       +-------+       +-----------------+
| Main |       | Scheduler |       |  CPU  |       | ResourceManager |
+--+---+       +-----+-----+       +---+---+       +--------+--------+
   |                 |                 |                     |
   | Create Process  |                 |                     |
   +---------------->|                 |                     |
   |                 |                 |                     |
   | Add Process     |                 |                     |
   +---------------->|                 |                     |
   |                 |                 |                     |
   |                 | Select Process  |                     |
   |                 +---------------->|                     |
   |                 |                 |                     |
   |                 |                 | Request Resource    |
   |                 |                 +-------------------->|
   |                 |                 |                     |
   |                 |                 |<--------------------+
   |                 |                 |   Resource Granted  |
   |                 |                 |                     |
   |                 |                 | Execute Process     |
   |                 |                 |                     |
   |                 |                 | Release Resource    |
   |                 |                 +-------------------->|
   |                 |                 |                     |
   |                 |                 |<--------------------+
   |                 |                 |   Resource Released |
   |                 |                 |                     |
   |                 |                 | Process Completed   |
   |                 |                 |                     |
   |<--------------------------------------------------------+
   |                 Simulation Progress                      |
Sequence Description
1.The Main module starts the simulation.
2.Processes are created and added to the Scheduler.
3.The Scheduler selects a process from the ready queue.
4.The selected process is assigned to a CPU core.
5.The CPU core requests the resources required by the process.
6.The Resource Manager checks and allocates the required resources.
7.The CPU core executes the process.
8.After execution, the CPU core releases the resources.
9.The Resource Manager updates the available resources.
10.The process is marked as completed.
11.The simulation continues until all processes are completed.

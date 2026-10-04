# SimOS – State Machine Diagram

## Process State Machine

```text
                  +-------+
                  |       |
                  | START |
                  |       |
                  +---+---+
                      |
                      v
                +-----------+
                |   READY   |
                +-----+-----+
                      |
                      | Scheduler
                      | selects process
                      v
                +-----------+
                |  RUNNING  |
                +-----+-----+
                  /         \
                 /           \
        Execution complete   Execution not complete
               |                    |
               v                    v
        +-------------+       +-----------+
        | TERMINATED  |       |   READY   |
        +-------------+       +-----------+
                                   |
                                   |
                              Scheduler
                                   |
                                   v
                                RUNNING
State Descriptions
READY

The process has been created and is waiting in the scheduler's ready queue
for assignment to a CPU core.

RUNNING

The process has been assigned to a CPU core and is currently executing.

TERMINATED

The process has completed its required execution and no longer needs CPU
resources.



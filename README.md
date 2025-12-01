# Philosophers 🍽️

### Dining Philosophers simulation

`philo` is a small C program that simulates the Dining Philosophers problem using POSIX threads and mutexes. The goal is to implement a concurrent program where philosophers alternately think, eat, and sleep while sharing forks (mutexes) and avoiding deadlocks and starvation.

This repository contains a clear, small implementation focused on correctness, proper synchronization, and clean resource management.

---
## Features
- Command-line argument validation (number of philosophers, times, optional meal limit)
- Uses `pthread` threads and `pthread_mutex_t` for forks and synchronization
- Per-philosopher routine: thinking → picking forks → eating → sleeping
- Timekeeping with `gettimeofday` and relative timestamps printed to stdout
- Proper cleanup of threads and mutexes
- Death detection: a philosopher dies if they don't eat within `time_to_die` ms
- Optional `number_of_times_each_philosopher_must_eat` stops the simulation once reached
- Simple, readable code structure split into init, checks, routines, and utils

---
## Typical Command-line Usage

Build the program (requires a POSIX C toolchain):

```bash
make
```

Run the simulation:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

Arguments (all integers in milliseconds except the first):
- `number_of_philosophers` — how many philosopher threads to create
- `time_to_die` — time (ms) after which a philosopher dies if they didn't start eating
- `time_to_eat` — time (ms) that a philosopher spends eating
- `time_to_sleep` — time (ms) that a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat` (optional) — simulation stops when each philosopher has eaten at least this many times

Example:

```bash
./philo 5 800 200 200
./philo 4 410 200 200 7
```

Expected behaviour examples:
- Philosophers pick up left/right forks (mutexes) and print timestamps + actions
- If a philosopher doesn't eat for `time_to_die` ms, the program prints the death message and exits
- If the optional meal limit is reached for all philosophers, the simulation exits cleanly

---
## Project Structure / Architecture

```
include/            Public headers (`philo.h`)
src/
  main.c             Program entry + orchestration
  check/             Argument & philosopher validation (`check_args.c`, `check_philos.c`)
  init/              Initialization helpers: forks, input, philosophers, threads
  routine/           Philosopher routines (eating, sleeping, thinking, main loop)
  utils/             Helpers: atoi, destroy, error, gettimeofday wrapper, printing, usleep
```

Flow at runtime:
1. Parse and validate arguments (`src/check/*.c`).
2. Initialize program state: input parameters, forks (mutexes), philosopher structs (`src/init/*.c`).
3. Create philosopher threads and a monitor (if present) to watch for death and meal counts (`init_threads.c`).
4. Each philosopher runs a loop: try to pick forks (mutex lock ordering prevents deadlocks), eat, sleep, think (`src/routine/*.c`).
5. Monitor detects death or completion and triggers cleanup.
6. Join threads and free resources (`utils/ft_destroy.c`).

Contract (small):
- Input: validated integers from the command line
- Output: deterministic timestamped messages to stdout (actions, death)
- Error modes: invalid args -> program prints a usage/error and exits non-zero

---
## Key Modules & Notes
- `check/` — validates argument count, ranges, and consistency. Important to prevent UB from bad input.
- `init/` — sets up `pthread_mutex_t` forks and philosopher structures. Ensures all mutexes are created before threads start.
- `routine/` — contains the logic for eating, sleeping, thinking and timestamped printing. The eating function usually locks two mutexes (forks) and updates last-meal time.
- `utils/` — contains small helpers: `ft_atoi`, `ft_usleep` (better than plain `usleep` for millisecond sleeps), `ft_gettimeofday`, and `ft_print_msg` for consistent, timestamped output.

Edge cases and synchronization
- Ordering of mutex locks and careful timing avoid classic deadlocks. Many implementations use an ordering trick or staggered start to avoid deadlock in the 2+ philosopher case.
- The monitor must safely read shared timestamps with mutex protection to avoid data races.

---
## Error Handling
- The program tries to fail early on invalid input with clear messages (see `src/check/check_args.c`).
- If a runtime error occurs (mutex init, thread create), the program prints an error and performs best-effort cleanup before exiting.

---
## Building & Cleaning
- Build: `make` (produces `philo` executable)
- Clean objects: `make clean`
- Full clean: `make fclean`
- Rebuild: `make re`

Makefile notes: the project compiles object files into an `objects/` folder and links with `-pthread`.

---
## Running & Examples

Start a small simulation of 5 philosophers:

```bash
./philo 5 800 200 200
```

Start with a meal limit (stop after each philosopher ate 7 times):

```bash
./philo 4 410 200 200 7
```

Typical output lines (timestamp in ms, philosopher id, action):

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
400 1 is thinking
...
800 3 died
```

Notes:
- Times are relative to program start (ms).
- The exact output formatting is implemented in `src/utils/ft_print_msg.c`.

---
## Development & Tests
- Add small scenario tests by running with different argument combinations to exercise edge cases (1 philosopher, fast death, many philosophers, with/without meal limit).
- Consider running under ThreadSanitizer or valgrind to catch races or leaks when making changes.

---
## Credits
Built as a Codam project. Author: mahkilic (see repository). The project implements the classic concurrency exercise (Dining Philosophers) to learn thread synchronization and safe resource cleanup.

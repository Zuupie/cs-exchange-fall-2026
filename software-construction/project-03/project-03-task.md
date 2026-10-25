# Project 3 – Truel of the Fates

**Course:** COMP 2710 (Software Construction) · Fall 2026
**Language:** C++ (compiled with g++ on the AU server)
**Topics:** Test drivers, `assert()`, random numbers, call by reference

> Task description summarized in my own words. The original assignment sheet is the instructor's material and is not included here.

## Problem

Three marksmen fight a "truel" (a three-way duel) until only one is left:

| Shooter | Hit probability |
|---------|-----------------|
| Aaron   | 1/3 |
| Bob     | 1/2 |
| Charlie | 1 (never misses) |

They take turns in a fixed order (Aaron → Bob → Charlie, then repeat), skipping anyone who is dead. A hit always kills.

Simulate the truel with random numbers, run it 10,000 times per strategy, and report how often each shooter wins.

### Strategy 1
Everyone shoots at the most accurate opponent still alive.

### Strategy 2
Same as Strategy 1, except Aaron deliberately misses his very first shot.

### Goal
Compare both strategies from Aaron's point of view and print which one is better for him. Strategy 2 should come out ahead (roughly 41% vs. 36% win rate for Aaron).

## Required Functions

| Function | Purpose |
|----------|---------|
| `bool at_least_two_alive(bool A, bool B, bool C)` | True if two or more shooters are still alive |
| `Aaron_shoots1(bool& B_alive, bool& C_alive)` | Aaron's turn under Strategy 1 |
| `Bob_shoots(bool& A_alive, bool& C_alive)` | Bob's turn |
| `Charlie_shoots(bool& A_alive, bool& B_alive)` | Charlie's turn |
| `Aaron_shoots2(bool& B_alive, bool& C_alive)` | Aaron's turn under Strategy 2 (misses on purpose if both opponents are alive) |

The shooting functions use call by reference to set a target's flag to `false` when he is killed.

## Other Requirements

- **Five unit-test drivers**, one per function above, each using `assert()`:
  - `at_least_two_alive`: all 8 alive/dead combinations
  - Each shooting function: 3 cases (both opponents alive / one dead / the other dead), printing who is being targeted
- **Four constants** (`const`): number of runs (10,000) and the three accuracies.
- Seed the RNG once with `srand(time(0))` and decide hits with `rand()`.
- Pause with "Press Enter to continue..." between test sections and before each simulation.

## Expected Program Flow

1. Welcome banner with the student's name
2. Unit tests 1–5, each case reporting that it passed or which target was chosen
3. Strategy 1 simulation: wins and percentage for each shooter (e.g. `Aaron won 3593/10000 truels or 35.93%`)
4. Strategy 2 simulation: same output
5. Conclusion line stating which strategy is better for Aaron

Results vary slightly between runs because of randomness.

## Build & Run

```bash
g++ project3.cpp
./a.out
```

No user input is needed apart from pressing Enter.
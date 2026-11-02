# Project 4 – A Song of Files & Data (Part 1)

**Course:** COMP 2710 (Software Construction) · Fall 2026
**Language:** C++ (compiled with g++ on the AU server)
**Topics:** File input streams, input validation, arrays/vectors, string-to-number conversion, functions

> Task description summarized in my own words. The original assignment sheet is the instructor's material and is not included here.

## Problem

A lab experiment produces N text files, each holding K (K > 0) signed decimal numbers in random order. Write a program that reads all N files, merges and sorts the values, and reports the **mean**, **median** and **mode** of the combined data.

## Input

- The number of files N to read
- One filename per file, either relative to the current directory (e.g. `folderA/input1.txt`) or an absolute path

A valid file has exactly one number per line, and the last line also ends with a newline:

```
-79
55.83919992
11.49
0.0001
4493.33
-44.5712
```

## Output

1. Welcome banner with the student's name
2. For each file: the number of values it holds and the values themselves, one per line
3. A "Summarized Statistics" section with:
   - the combined list sorted in ascending order
   - the mean, median and mode, rounded to 4 decimal places
4. Goodbye message

Example (3 files, 15 values in total):

```
The mean is -50.9448
The median is 4.1700
The mode is 90.1200
```

## Requirements & Edge Cases

- **Multiple functions:** the code must not sit entirely in `main()`. Use separate functions for reading files, sorting, and each statistic.
- **Non-existing file:** print `File not found. Please try again.` and ask for the same file again. The program must not crash.
- **Malformed file:** if any line is not a valid number, or the file is empty, reject the whole file and ask again:
  `Not an input file. Illegal content/structure detected. Please try again.`
- **Number of files:** reject invalid input (non-numeric, zero, negative) with a custom message and re-prompt.
- **Mode:** if several values share the highest count, print the average of all of them.
- Lines are read as strings and must be converted to numbers (e.g. `stod`).
- Sorting is ascending. Writing your own sorting algorithm is recommended but not required.
- Every opened file must be closed.
- The code must compile with **no errors and no warnings**.

## Test Cases

| File | Content | Expected |
|------|---------|----------|
| `ideal.txt` | One valid number per line | Accepted |
| `malform_1.txt` | Junk like `453<<<392`, `3<>{{{kf`, `Rr,4` | Rejected |
| `malform_2.txt` | Empty file | Rejected |
| `malform_3.txt` | Comma numbers (`65,495`) and several numbers on one line | Rejected |
| `non_existing_file` | (does not exist) | "File not found", re-prompt |

## Deliverable

A tarball `Project4_username_Firstname_Lastname.tgz` containing the `.cpp` file and the four test files (`ideal.txt`, `malform_1.txt`, `malform_2.txt`, `malform_3.txt`):

```bash
tar vfzc Project4_username_Firstname_Lastname.tgz Project4_username_Firstname_Lastname
```

The source file needs a header comment with the student's name, username, filename, compile/run instructions, any external help used, and how file paths are resolved.

## Grading Breakdown

| Part | Points |
|------|--------|
| Read multiple files from any legal path | 15 |
| Detect non-existing files, malformed files, invalid number of files | 15 |
| Functional decomposition (not all in `main()`) | 10 |
| Four test case files included | 20 |
| Files closed after use | 10 |
| Header comment | 10 |
| Correct tarball name | 10 |
| Output follows the specified user interface | 10 |

## Build & Run

```bash
g++ -std=c++11 project4.cpp
./a.out
```

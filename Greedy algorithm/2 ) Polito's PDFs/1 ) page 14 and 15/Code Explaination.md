# Activity Selection Program

## Overview
This program implements the **Activity Selection Problem**, which is a classic problem in computer science. The problem is to select the maximum number of non-overlapping activities from a given list, each with a start and end time. This solution uses a **greedy algorithm** approach to achieve optimal results by selecting activities that finish the earliest, allowing for more activities to be chosen.

The program reads activities from a file, sorts them by their stop times, and selects the optimal subset of activities to maximize the number of non-overlapping activities.

## Features
- Reads activity data from an input file specified at runtime.
- Sorts activities by their stop times using the `qsort` function.
- Selects the maximum number of non-overlapping activities using a greedy algorithm.
- Prints the selected activities to the terminal.

## How to Use the Program
### Requirements
- **C Compiler**: Any C compiler such as GCC.
- **Input File**: A text file containing activity data.

### Compilation
To compile the program, use a C compiler such as GCC:
```bash
gcc -o activity_selection program.c
```
This will generate an executable named `activity_selection`.

### Input File Format
The input file should contain the following format:
1. The first line contains an integer `n`, representing the number of activities.
2. Each of the following `n` lines contains the **name**, **start time**, and **stop time** of an activity, separated by spaces.

Example (`activities.txt`):
```
6
A 1 3
B 2 5
C 4 7
D 1 8
E 5 9
F 8 10
```
- `6`: The number of activities.
- `A 1 3`: Activity name is `A`, it starts at time `1` and stops at time `3`.

### Running the Program
After compiling, run the program and pass the input file as an argument:
```bash
./activity_selection activities.txt
```
The program will read the activities, sort them by their stop times, and print the selected activities.

## Program Structure and Functions
### 1. `main(int argc, char *argv[])`
This is the entry point of the program.
- **Input Handling**: Ensures the user provides the correct filename as an argument.
- **Loading Data**: Calls `load()` to read activities from the file.
- **Sorting Activities**: Uses `qsort()` with the comparator function `cmp()` to sort the activities by their stop time.
- **Selecting Activities**: Calls `choose()` to select the optimal set of activities.
- **Printing Results**: Calls `print_activities()` to output the selected activities.
- **Memory Management**: Frees dynamically allocated memory for activities.

### 2. `activity_t *load(const char *filename, int *n)`
- **Purpose**: Loads activities from the input file into an array of `activity_t` structures.
- **Parameters**: Takes the filename and a pointer to an integer `n` to store the number of activities.
- **Functionality**: Reads the activities and dynamically allocates memory for them.
- **Returns**: A pointer to the array of activities.

### 3. `int cmp(const void *p1, const void *p2)`
- **Purpose**: Comparator function used by `qsort` to sort activities by their stop time.
- **Parameters**: Takes two pointers (`p1` and `p2`) representing activities.
- **Returns**: A positive, zero, or negative value based on the difference in stop times.
- **Sorting Criteria**: Activities are sorted in ascending order of their stop times to facilitate the greedy selection.

### 4. `void choose(activity_t *acts, int n)`
- **Purpose**: Selects the maximum number of non-overlapping activities.
- **Algorithm**: Implements a greedy algorithm to select the activities that finish the earliest.
- **Parameters**: Takes the array of activities and the total number of activities `n`.
- **Functionality**: Always selects the first activity, then iterates through the sorted list and selects the next activity if its start time is greater than or equal to the last selected activity's stop time.

### 5. `void print_activities(activity_t *acts, int n)`
- **Purpose**: Prints the selected activities.
- **Parameters**: Takes the array of activities and the number of activities `n`.
- **Output**: Prints the names and start/stop times of the activities that were selected.

## Example Execution
Consider the following input file (`activities.txt`):
```
6
A 1 3
B 2 5
C 4 7
D 1 8
E 5 9
F 8 10
```
### Output:
```
Selected activities:
A (1, 3)
C (4, 7)
F (8, 10)
```
This output shows that activities `A`, `C`, and `F` were selected as they are non-overlapping and maximize the total number of activities.

## Algorithm Explanation
The **greedy algorithm** approach used in this program aims to select activities that leave as much room as possible for subsequent activities. By sorting the activities by their end times, the algorithm ensures that it selects the activity that finishes first, thereby allowing for more activities to follow.

The steps involved in the algorithm are:
1. **Sort** all activities by their stop times.
2. **Select** the first activity (since it has the earliest stop time).
3. **Iterate** through the list, selecting an activity if its start time is greater than or equal to the stop time of the last selected activity.

This approach guarantees that the maximum number of compatible activities are selected.

## Memory Management
The program uses dynamic memory allocation to handle the activities. The memory for the activities is allocated in the `load` function and is freed at the end of the `main` function. This ensures efficient use of memory, especially for larger input files.

## How to Extend the Program
1. **User Input**: Modify the program to take user input directly rather than from a file.
2. **Graphical Output**: Extend the output to show a graphical representation of the selected activities on a timeline.
3. **Custom Sorting**: Add options to sort activities by different criteria (e.g., by start time).
4. **Validation**: Add validation to check for incorrect or missing data in the input file.

## Conclusion
This program demonstrates the use of a greedy algorithm to solve the **Activity Selection Problem** efficiently. By sorting activities based on their stop times and using a greedy selection approach, the program ensures that the maximum number of non-overlapping activities are selected.

The code is well-structured, and each function serves a clear purpose, making it easy to read, maintain, and extend. This example is a practical application of greedy algorithms and is useful for learning purposes in both algorithm design and implementation.

Feel free to modify the code to suit your specific requirements or to extend its functionality for more complex scheduling problems.

---

**Usage Reminder**: Always compile and test the program with different inputs to ensure it behaves as expected and handles all edge cases.


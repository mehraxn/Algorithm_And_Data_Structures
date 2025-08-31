# README: Linked List Processing Program

## Overview
This program processes a text file containing a list of names and associated integers, storing the data in a linked list structure. It groups and counts integers associated with each unique name, allowing for organized storage and easy traversal of data.

---

## Features
- **Nested Linked List Structure**: Two levels of linked lists for grouping data:
  1. Outer list: Each node corresponds to a unique name.
  2. Inner list: Each node stores an integer and its count (number of occurrences).
- **File Input**: Reads data from a text file with lines formatted as `name integer`.
- **Dynamic Memory Management**: Allocates and frees memory dynamically to handle varying input sizes.
- **Data Deduplication**: Groups identical integers under the same name, tracking their occurrence count.

---

## Code Structure

### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Calls `insert` to read and process data from a file.
  - Traverses the linked lists to print and free all allocated memory.
- **Output**:
  - Displays the names and their associated integers with counts.
  
---

#### 2. **insert**
```c
list1_t *insert(char *filename);
```
- **Purpose**: Reads data from a file and populates the linked lists.
- **Parameters**:
  - `filename`: Path to the input file.
- **Logic**:
  - Opens the file and reads `name integer` pairs.
  - Searches for the name in the outer linked list using `search`.
  - If the name exists, updates its inner list with the integer using `add_n`.
  - If the name does not exist, creates a new node in the outer list.
- **Returns**: Pointer to the head of the outer linked list.

---

#### 3. **search**
```c
list1_t *search(list1_t *list, char *name);
```
- **Purpose**: Searches for a name in the outer linked list.
- **Parameters**:
  - `list`: Pointer to the head of the outer linked list.
  - `name`: Name to search for.
- **Logic**:
  - Traverses the list and compares each node's `name` field with the target name.
- **Returns**: Pointer to the matching node if found, otherwise `NULL`.

---

#### 4. **add_n**
```c
list1_t *add_n(list1_t *item, int n);
```
- **Purpose**: Adds an integer to the inner linked list of a given name.
- **Parameters**:
  - `item`: Pointer to a node in the outer linked list.
  - `n`: Integer to add.
- **Logic**:
  - Checks if the integer already exists in the inner list.
  - If it exists, increments its count.
  - If not, creates a new node in the inner list and links it.
- **Returns**: Pointer to the updated outer list node.

---

## Input File Format
The input file should contain lines in the format:
```
name integer
```
Example:
```
Alice 3
Bob 5
Alice 3
Alice 4
Bob 2
```

---

## Example Execution
### Input File (`input.txt`):
```
Alice 3
Bob 5
Alice 3
Alice 4
Bob 2
```

### Output:
```
Alice
   -> 3 (2) -> 4 (1)
Bob
   -> 5 (1) -> 2 (1)
```
- The program reads the input, groups integers under each name, and counts their occurrences.

---

## Data Structures

### 1. **Outer Linked List (list1_t)**
```c
struct list1_s {
    char *name;
    struct list2_s *list;
    struct list1_s *next;
};
```
- Represents a unique name.
- Fields:
  - `name`: Pointer to the name string.
  - `list`: Pointer to the inner linked list for integers.
  - `next`: Pointer to the next node in the outer list.

### 2. **Inner Linked List (list2_t)**
```c
struct list2_s {
    int n;
    int rep;
    struct list2_s *next;
};
```
- Represents an integer and its count.
- Fields:
  - `n`: Integer value.
  - `rep`: Count of occurrences.
  - `next`: Pointer to the next node in the inner list.

---

## Memory Management
- **Dynamic Allocation**: Memory is allocated dynamically for both outer and inner linked lists.
- **Deallocation**: Frees all allocated memory after processing:
  - Inner list nodes are freed first.
  - Outer list nodes are freed afterward.

---

## Limitations
- **File Validation**: Assumes the input file exists and is formatted correctly.
- **Error Handling**: Limited error handling for file operations and memory allocation failures.

---

## Future Improvements
- Add input validation and error handling for file reading and memory allocation.
- Extend functionality to allow dynamic addition of data without relying on a file.
- Implement sorting of integers or names for better presentation.
- Allow user-defined output formats.

---

## How to Compile and Run
1. Save the code in a file (e.g., `linked_list_processor.c`).
2. Compile the program:
   ```bash
   gcc -o linked_list_processor linked_list_processor.c
   ```
3. Run the program:
   ```bash
   ./linked_list_processor
   ```


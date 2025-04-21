# README: List of Lists Implementation

## Overview
This code defines a `list of lists` data structure, designed to parse input from a file and store it in a hierarchical format. It consists of two types of linked lists: a **primary list** (containing strings as keys) and a **secondary list** (containing unique integer values associated with each key). The implementation supports creating, updating, printing, and freeing this structure.

### File Format
The input file should contain lines formatted as follows:
```
<string> <count> <int1> <int2> ... <intN>
```
- `<string>`: A name (used as the key for the primary list).
- `<count>`: The number of integers associated with the string.
- `<int1> <int2> ... <intN>`: A list of integers associated with the key.

### Example Input File
```
alice 3 10 20 30
bob 2 40 50
alice 2 30 40
```

## Data Structures

### Primary List Node (`list1_t`)
```c
typedef struct list1 {
    char *name;          // String key
    list2_t *values;     // Pointer to the secondary list
    struct list1 *next;  // Pointer to the next primary list node
} list1_t;
```
- **Fields**:
  - `name`: The key (a dynamically allocated string).
  - `values`: A pointer to the secondary list for this key.
  - `next`: A pointer to the next primary list node.

### Secondary List Node (`list2_t`)
```c
typedef struct list2 {
    int value;          // Integer value
    struct list2 *next; // Pointer to the next secondary list node
} list2_t;
```
- **Fields**:
  - `value`: A unique integer.
  - `next`: A pointer to the next secondary list node.

## Functions

### 1. Creating Nodes

#### `list1_t *create_list1_node(const char *name)`
Creates a new primary list node.
- **Input**: A string `name` (key for the primary list).
- **Output**: A pointer to the newly created node.
- **Details**:
  - Dynamically allocates memory for the node and the string.
  - Initializes `values` and `next` to `NULL`.

#### `list2_t *create_list2_node(int value)`
Creates a new secondary list node.
- **Input**: An integer `value`.
- **Output**: A pointer to the newly created node.
- **Details**:
  - Dynamically allocates memory for the node.
  - Initializes `next` to `NULL`.

### 2. Adding Values

#### `void add_value_to_list2(list2_t **head, int value)`
Adds a unique value to the secondary list.
- **Input**:
  - `head`: A pointer to the head of the secondary list.
  - `value`: The integer value to add.
- **Details**:
  - Checks for duplicates before adding the value.
  - Adds new values at the head of the secondary list.

#### `void add_or_update_list1(list1_t **head, const char *name, int *values, int count)`
Adds or updates a primary list node and its associated values.
- **Input**:
  - `head`: A pointer to the head of the primary list.
  - `name`: The key for the primary list.
  - `values`: An array of integers to add to the secondary list.
  - `count`: The number of integers in the array.
- **Details**:
  - Searches for a node with the given name.
  - Creates a new node if none exists.
  - Adds values to the associated secondary list.

### 3. Searching Nodes

#### `list1_t *find_list1_node(list1_t *head, const char *name)`
Finds a primary list node by name.
- **Input**:
  - `head`: The head of the primary list.
  - `name`: The name to search for.
- **Output**: A pointer to the found node or `NULL` if not found.

### 4. File Parsing

#### `list1_t *file_to_list_of_lists(const char *name)`
Parses the input file and constructs the list of lists.
- **Input**: The file name as a string.
- **Output**: The head of the primary list.
- **Details**:
  - Reads the file line by line.
  - Extracts the string key, integer count, and associated values.
  - Adds or updates the primary list with the parsed data.

### 5. Printing

#### `void print_list_of_lists(list1_t *head)`
Prints the contents of the list of lists.
- **Input**: The head of the primary list.
- **Output**: None (prints to `stdout`).
- **Format**: Each line contains the key followed by its associated values.
  - Example: `alice: 10 20 30`

### 6. Freeing Memory

#### `void free_list_of_lists(list1_t *head)`
Frees all memory used by the list of lists.
- **Input**: The head of the primary list.
- **Details**:
  - Frees all nodes in the secondary list.
  - Frees the name string and primary list nodes.

### 7. Main Function
```c
int main() {
    const char *filename = "input.txt";
    list1_t *list = file_to_list_of_lists(filename);

    if (list) {
        printf("List of lists:\n");
        print_list_of_lists(list);
        free_list_of_lists(list);
    }

    return 0;
}
```
- Parses the input file `input.txt`.
- Prints the constructed list of lists.
- Frees the allocated memory.

## Example Execution
### Input File: `input.txt`
```
alice 3 10 20 30
bob 2 40 50
alice 2 30 40
```
### Output
```
List of lists:
alice: 40 30 20 10
bob: 50 40
```

## Key Features
- **Dynamic Memory Management**: Uses `malloc` and `free` to manage memory.
- **Duplicate Prevention**: Ensures no duplicate values in the secondary lists.
- **File Parsing**: Reads and parses structured data from a file.

## Notes
- Ensure the input file exists and is formatted correctly.
- Always free the allocated memory to prevent leaks.

## Limitations
- Assumes a fixed maximum line size of 256.
- Does not handle malformed lines gracefully.

## Improvements
- Add error handling for malformed input lines.
- Allow for configurable maximum line size.


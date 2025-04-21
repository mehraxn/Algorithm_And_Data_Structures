# README: String to FIFO List Program

## Overview
This program processes a string containing sequences of lowercase letters and decimal digits, splits it into separate substrings of letters and digits, and stores these substrings into two circular FIFO (First-In-First-Out) linked lists. The program demonstrates modular programming, dynamic memory allocation, and the use of linked lists in C.

## Problem Statement
The goal is to:
1. Split a string into substrings of contiguous letters and contiguous digits.
2. Store these substrings in two separate circular FIFO linked lists:
   - One for substrings of letters.
   - One for substrings of digits.
3. Print the content of the linked lists.

For example, given the input string:
```
abc12345xyz333fgew
```
The program will produce:
- Letter list: `{abc, xyz, fgew}`
- Digit list: `{12345, 333}`

## Functionalities

### Main Function (`main`)
1. Initializes pointers to the letter and digit FIFO lists as `NULL`.
2. Calls `string_to_fifo` to process the input string and populate the two FIFO lists.
3. Debugging output displays the content of the digit and letter lists.
4. Ends the program without deallocating memory (deallocation would be added for completeness).

### `string_to_fifo`
This function processes the input string, splits it into substrings, and stores them in the appropriate FIFO list.

#### Parameters:
- `char *s`: The input string.
- `node_t **letter`: Pointer to the FIFO list for letters.
- `node_t **digit`: Pointer to the FIFO list for digits.

#### Process:
1. **Initialization:**
   - Allocate a temporary buffer `tmp` to store the current substring.
   - Use a variable `ndl` (nothing-digit-letter) to track the current state:
     - `0`: No characters processed yet.
     - `1`: Current substring contains digits.
     - `2`: Current substring contains letters.

2. **String Parsing:**
   - Iterate through each character of the string:
     - If the character type changes (from digit to letter or vice versa):
       - Terminate the current substring with `\0`.
       - Store it in the appropriate FIFO list using `enqueue`.
       - Reset `tmp` for the next substring.
     - Otherwise, append the character to `tmp`.

3. **Final Substring:**
   - Add the last substring to the corresponding FIFO list.

4. **Error Handling:**
   - Exits the program if memory allocation fails.

### `enqueue`
Adds a new node containing the substring to the tail of the FIFO list.

#### Parameters:
- `node_t **tail`: Pointer to the tail of the FIFO list.
- `char *s`: The substring to add.

#### Process:
1. Create a new node using `new_node`.
2. Duplicate the substring `s` into the node.
3. If the list is empty, set the node to point to itself (circular).
4. Otherwise, insert the node at the tail and update the tail pointer.

### `new_node`
Allocates memory for a new node and initializes it.

#### Process:
1. Allocate memory for a `node_t` structure.
2. Print an error and terminate if allocation fails.
3. Return the newly created node.

### `traversal`
Prints the content of a FIFO list for debugging purposes.

#### Parameters:
- `node_t *tail`: Pointer to the tail of the FIFO list.

#### Process:
1. Check if the list is empty.
2. If not, iterate through the list starting from the tail's next node and print each substring.

## Data Structures

### `node_t`
The `node_t` structure represents a node in the circular FIFO list.

#### Fields:
- `char *s`: Pointer to the string stored in the node.
- `node_t *next`: Pointer to the next node in the list.

## Example Execution

### Input:
```
abc12345xyz333fgew
```

### Output:
```
Digit List : -> 12345 -> 333
Letter List: -> abc -> xyz -> fgew
```

### Explanation:
- The input string is split into `{abc, xyz, fgew}` for letters and `{12345, 333}` for digits.
- These substrings are stored in separate circular FIFO lists.

## Memory Management
- Dynamic memory allocation is used for:
  - Temporary buffers.
  - Nodes in the FIFO lists.
- No explicit memory deallocation is implemented in this example, but it should be added for completeness in a production environment.

## Compilation and Execution
1. Save the code to a file (e.g., `string_to_fifo.c`).
2. Compile using a C compiler:
   ```bash
   gcc -o string_to_fifo string_to_fifo.c
   ```
3. Run the executable:
   ```bash
   ./string_to_fifo
   ```

## Limitations
- Assumes the input string is valid and non-empty.
- Does not handle memory deallocation, which should be implemented for better resource management.

## Conclusion
This program effectively demonstrates how to parse and categorize a string into separate substrings using circular FIFO lists. It employs modular design and highlights the importance of dynamic memory management in C.


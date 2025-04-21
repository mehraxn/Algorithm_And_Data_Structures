# README: Optimal Order and Linked List Operations

## Overview
This program provides two key functionalities:

1. **Optimal Order of Balances:** Finds the optimal order of an array of numbers to minimize the difference between the maximum and minimum cumulative balances.
2. **String Splitting into Linked List:** Splits a string into substrings based on a delimiter (`.`) and stores them in a dynamically created linked list.

### Key Features:
- **Optimal Balance Order:**
  - Calculates all possible permutations of an array.
  - Computes the difference between maximum and minimum cumulative sums for each permutation.
  - Identifies the permutation with the smallest difference.
- **Linked List Operations:**
  - Creates a linked list of substrings from a delimited string.
  - Provides functions to display and free the linked list.

---

## File Structure

### 1. **Optimal Balance Order Functions**

#### **`difference` Function**
- **Purpose:** Calculates the difference between the maximum and minimum cumulative sums of an array.
- **Parameters:**
  - `float *array`: Pointer to the array of numbers.
  - `int number`: Size of the array.
- **Returns:** The difference between the maximum and minimum cumulative sums.
- **Logic:**
  1. Initialize `max`, `min`, and `sum`.
  2. Traverse the array, updating the cumulative sum (`sum`).
  3. Track the largest (`max`) and smallest (`min`) cumulative sums.
  4. Return the difference (`max - min`).

#### **`permutation` Function**
- **Purpose:** Recursively generates all permutations of an array and evaluates the optimal order to minimize the balance difference.
- **Parameters:**
  - `float *numbers`: Array of numbers to permute.
  - `float *sol`: Temporary array to store the current permutation.
  - `int *mark`: Array to track which numbers are used.
  - `float *final_array`: Array to store the best permutation.
  - `int pos`: Current position in the permutation.
  - `int n`: Size of the array.
  - `float *final`: Pointer to store the minimum difference.
- **Logic:**
  1. If `pos == n`, a complete permutation is generated.
  2. Compute the difference using the `difference` function.
  3. Update the `final` and `final_array` if the current difference is smaller.
  4. Otherwise, iterate through unused numbers, mark them as used, and recursively call the function for the next position.
  5. Backtrack by unmarking the number.

#### **`balance` Function**
- **Purpose:** Finds the optimal permutation of numbers to minimize the balance difference.
- **Parameters:**
  - `float *flow`: Array of numbers.
  - `int n`: Size of the array.
- **Returns:** An array of indices representing the optimal order.
- **Logic:**
  1. Allocate memory for temporary arrays (`sol`, `final_array`, `mark`).
  2. Initialize the best difference (`final`) as the maximum possible value.
  3. Call `permutation` to generate all permutations and identify the optimal solution.
  4. Convert the best solution into indices of the original array.
  5. Free temporary arrays and return the indices.

---

### 2. **Linked List Operations**

#### **`create_node` Function**
- **Purpose:** Creates a new node in the linked list to store a substring.
- **Parameters:**
  - `const char *substring`: Pointer to the substring.
  - `int length`: Length of the substring.
- **Returns:** Pointer to the new node.
- **Logic:**
  1. Allocate memory for a new `node_t` structure.
  2. Allocate memory for the substring and copy it.
  3. Set the `next` pointer of the node to `NULL`.
  4. Return the node.

#### **`split_str` Function**
- **Purpose:** Splits a string into substrings using `.` as a delimiter and stores them in a linked list.
- **Parameters:**
  - `char *str`: Input string.
- **Returns:** Pointer to the head of the linked list.
- **Logic:**
  1. Initialize `head` and `tail` pointers for the linked list.
  2. Traverse the string, identifying substrings between `.` delimiters.
  3. For each substring, create a node using `create_node`.
  4. Append the node to the linked list.
  5. Handle the last substring after the final `.`.

#### **`display_list` Function**
- **Purpose:** Displays the linked list of substrings.
- **Parameters:**
  - `node_t *head`: Pointer to the head of the linked list.
- **Returns:** None.
- **Logic:**
  1. Traverse the list starting from `head`.
  2. Print each substring stored in the `data` field of the node.

#### **`free_list` Function**
- **Purpose:** Frees the memory allocated for the linked list.
- **Parameters:**
  - `node_t *head`: Pointer to the head of the linked list.
- **Returns:** None.
- **Logic:**
  1. Traverse the list starting from `head`.
  2. Free the memory allocated for the substring and the node itself.

---

## Example Input and Output

### Input:
#### String Input:
```c
char input_str[] = "a.bb.ccc.dddd.eeeee.fffff";
```
#### Array Input:
```c
float array[4] = {-5, 10, -8, 7};
```

### Output:
#### Linked List:
```
The list of substrings:
a
bb
ccc
dddd
eeeee
fffff
```
#### Optimal Order of Numbers:
```
Optimal order of numbers are:
-8.000000 -5.000000 10.000000 7.000000
```

---

## Complexity Analysis

### Time Complexity:
1. **Optimal Balance Order:**
   - Generating all permutations: \(O(n!)\).
   - Evaluating each permutation: \(O(n)\).
   - Total: \(O(n! \cdot n)\).
2. **Linked List Operations:**
   - Splitting the string: \(O(m)\), where \(m\) is the length of the string.
   - Creating nodes: \(O(k)\), where \(k\) is the number of substrings.

### Space Complexity:
1. **Optimal Balance Order:**
   - Temporary arrays (`sol`, `final_array`, `mark`): \(O(n)\).
   - Recursive stack: \(O(n)\).
   - Total: \(O(n)\).
2. **Linked List Operations:**
   - Dynamically allocated substrings and nodes: \(O(m)\).

---

## Limitations
- **Optimal Balance Order:**
  - Computationally expensive for large arrays due to factorial growth.
- **Linked List Operations:**
  - Assumes substrings fit within available memory.

---

## Extensions and Improvements
1. **Optimal Balance Order:**
   - Implement dynamic programming or greedy approaches for larger inputs.
2. **Linked List Operations:**
   - Allow splitting by multiple delimiters.
   - Provide additional operations like searching or deleting nodes.

---

## Conclusion
This program provides a comprehensive solution for both optimizing the order of balances and splitting a string into a linked list. While computationally intensive for large inputs, it ensures precise results for small to medium-sized datasets.


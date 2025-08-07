# README for `deleteDuplicates` Function

Overview
This C code defines a function called `deleteDuplicates` which removes duplicate values from a sorted linked list.
It operates by iterating through each node and removing any subsequent nodes that have the same value. The function
makes sure that the resulting linked list contains only unique values.

Function Prototype:
struct ListNode* deleteDuplicates(struct ListNode* head);


Parameters:
head: A pointer to the head node of the linked list. The linked list must be sorted in ascending order for the function to work correctly.

Return Value:
The function returns a pointer to the head of the modified linked list, where all duplicate nodes have been removed.

## Detailed Explanation
1. **Initial Checks**:
   - If the list is empty (`head == NULL`), the function returns `NULL`.
   - If the list contains only one node, it returns the head as no duplicates are possible.

2. **Main Logic**:
   - The function uses two pointers:
     - `temp` to traverse the entire linked list.
     - `temp_temp` to handle the removal of duplicates.
   - For each value in the list, it checks the subsequent nodes for duplicate values.
   - If a duplicate is found, the corresponding node is removed, and memory is freed to avoid memory leaks.

3. **Memory Management**:
   - The function carefully frees the memory of the removed duplicate nodes using the `free()` function to prevent memory leaks.

## Complexity
- **Time Complexity**: O(n), where `n` is the number of nodes in the linked list. Each node is visited, and all duplicates are removed in a single traversal.
- **Space Complexity**: O(1), as the function operates in-place without using extra data structures.

## Example Usage
Suppose you have a linked list like the following:

```
1 -> 1 -> 2 -> 3 -> 3 -> 4
```
After running `deleteDuplicates(head)`, the linked list would be:

```
1 -> 2 -> 3 -> 4
```

## Notes
- The linked list should be sorted for this function to work as intended.
- The function does not handle unsorted linked lists; if the list is not sorted, the behavior is undefined.

## Limitations
- The function assumes the linked list is sorted. If the list is not sorted, duplicates may not be correctly removed.
- Make sure to properly initialize the linked list before passing it to the function to avoid undefined behavior.

## Usage
This function can be used in scenarios where you need to ensure that a linked list has no duplicate values, such as:
- Cleaning up data structures for unique data representation.
- Preparing linked lists for further operations that require unique elements.

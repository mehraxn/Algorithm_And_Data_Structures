# README: Sorting a Linked List of Students

## Overview
The `sort_list` function is designed to sort a linked list of student records in ascending order using insertion sort. The sorting is based on the following criteria:

1. **Last Name**: Primary key, sorted lexicographically.
2. **First Name**: Secondary key, sorted lexicographically if the last names are identical.
3. **Number of Examinations Passed (`n`)**: Tertiary key, sorted numerically if both last and first names are identical.

---

## Data Structure Definition
The student records are stored in a singly linked list, defined as:
```c
typedef struct list_s {
    char *last;           // Last name
    char *first;          // First name
    int n;                // Number of examinations passed
    struct list_s *right; // Pointer to the next element in the list
} list_t;
```

---

## Function Prototype
```c
void sort_list(list_t **head);
```

### Parameters:
- `list_t **head`: A pointer to the head of the linked list to be sorted.

---

## Helper Functions

### 1. **`compare_nodes`**
#### Purpose:
Compares two nodes based on the sorting criteria.

#### Prototype:
```c
int compare_nodes(list_t *a, list_t *b);
```
#### Parameters:
- `list_t *a`: First node to compare.
- `list_t *b`: Second node to compare.

#### Logic:
1. Compares the `last` fields of both nodes lexicographically.
2. If the `last` fields are equal, compares the `first` fields lexicographically.
3. If both `last` and `first` fields are equal, compares the `n` fields numerically.

#### Returns:
- A negative value if `a` comes before `b`.
- Zero if `a` and `b` are equal.
- A positive value if `a` comes after `b`.

---

### 2. **`sorted_insert`**
#### Purpose:
Inserts a node into its correct position in a sorted linked list.

#### Prototype:
```c
list_t* sorted_insert(list_t *sorted, list_t *new_node);
```
#### Parameters:
- `list_t *sorted`: Head of the already sorted linked list.
- `list_t *new_node`: Node to be inserted.

#### Logic:
1. If the list is empty or `new_node` comes before the current head, insert `new_node` at the beginning.
2. Traverse the list to find the appropriate position for `new_node`.
3. Insert `new_node` between two nodes or at the end of the list.

#### Returns:
- The updated head of the sorted list.

---

### 3. **`create_node`**
#### Purpose:
Creates and initializes a new linked list node.

#### Prototype:
```c
list_t* create_node(const char *last, const char *first, int n);
```
#### Parameters:
- `const char *last`: Last name of the student.
- `const char *first`: First name of the student.
- `int n`: Number of examinations passed.

#### Logic:
1. Allocates memory for a new node.
2. Duplicates the `last` and `first` strings to ensure memory safety.
3. Initializes the `n` field and sets the `right` pointer to `NULL`.

#### Returns:
- A pointer to the newly created node.

---

### 4. **`print_list`**
#### Purpose:
Prints the contents of the linked list.

#### Prototype:
```c
void print_list(list_t *head);
```
#### Parameters:
- `list_t *head`: Head of the linked list to be printed.

#### Logic:
1. Iterates through the list.
2. Prints the `last`, `first`, and `n` fields of each node.

---

### 5. **`free_list`**
#### Purpose:
Frees all dynamically allocated memory associated with the list.

#### Prototype:
```c
void free_list(list_t *head);
```
#### Parameters:
- `list_t *head`: Head of the linked list to be freed.

#### Logic:
1. Iterates through the list, freeing the `last` and `first` strings and each node.

---

## Main Function: `sort_list`

### Purpose:
Sorts the linked list using insertion sort.

### Logic:
1. Initialize an empty sorted list.
2. Iterate through the original list:
   - Extract each node.
   - Insert it into the correct position in the sorted list using `sorted_insert`.
3. Update the head of the original list to point to the new sorted list.

---

## Example Code
```c
int main() {
    // Create a sample linked list
    list_t *head = NULL;

    head = create_node("Smith", "John", 5);
    head->right = create_node("Doe", "Jane", 10);
    head->right->right = create_node("Smith", "Alice", 3);
    head->right->right->right = create_node("Brown", "Bob", 7);

    printf("Original List:\n");
    print_list(head);

    // Sort the list
    sort_list(&head);

    printf("\nSorted List:\n");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}
```

---

## Example Execution

### Input (Original List):
```
Last: Smith, First: John, Exams: 5
Last: Doe, First: Jane, Exams: 10
Last: Smith, First: Alice, Exams: 3
Last: Brown, First: Bob, Exams: 7
```

### Output (Sorted List):
```
Last: Brown, First: Bob, Exams: 7
Last: Doe, First: Jane, Exams: 10
Last: Smith, First: Alice, Exams: 3
Last: Smith, First: John, Exams: 5
```

---

## Key Concepts

1. **Insertion Sort**:
   - The algorithm builds a new sorted list by iteratively inserting nodes from the original list.
   - Suitable for linked lists as it avoids unnecessary data movement.

2. **Dynamic Memory Management**:
   - All nodes and strings are dynamically allocated and safely freed.

3. **Lexicographical Comparison**:
   - `strcmp` is used to compare strings for sorting.

---

## Complexity

1. **Time Complexity**:
   - Insertion sort for a linked list has a worst-case time complexity of \(O(n^2)\), where \(n\) is the number of nodes.

2. **Space Complexity**:
   - Space complexity is \(O(1)\) for pointers, excluding the dynamically allocated memory for the list.

---

## Limitations
1. The function assumes that all `last` and `first` fields are non-NULL and valid strings.
2. Performance may degrade for large lists due to the \(O(n^2)\) time complexity.

---

## Extensions
1. **Alternative Sorting Algorithms**:
   - Implement merge sort for better performance on large lists (\(O(n \, \log n)\)).

2. **Custom Comparators**:
   - Allow users to specify custom comparison functions for sorting.

---

## Conclusion
The `sort_list` function provides a robust solution for sorting a singly linked list of student records based on multiple criteria. Its modular design ensures maintainability and extensibility while demonstrating efficient use of insertion sort for linked lists.


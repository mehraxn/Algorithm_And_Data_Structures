# Readme for `double_tree` Function

## Overview
The `double_tree` function is a utility designed to modify a binary tree by duplicating each node in the tree and attaching the duplicate either to the left or right child position of the original node. This behavior is controlled by a user-defined flag.

The function works recursively and modifies the structure of the binary tree in-place. It leverages an auxiliary function, `create_node`, to create duplicate nodes.

---

## Function Signatures

### `struct node* create_node(const char *key)`
This helper function is used to create new nodes for the binary tree. It dynamically allocates memory for the node and duplicates the key.

#### Parameters:
- `const char *key`: A string representing the key of the node. The function dynamically allocates memory for this key using `strdup`.

#### Returns:
- A pointer to the newly created node with the specified key. The left and right child pointers of the node are initialized to `NULL`.

---

### `void double_tree(struct node *root, char flag)`
This is the main function that duplicates each node in the binary tree and attaches the duplicate based on the specified flag.

#### Parameters:
1. `struct node *root`:
   - A pointer to the root of the binary tree.
   - If the root is `NULL`, the function simply returns without performing any operations.

2. `char flag`:
   - A character that determines where the duplicate node will be attached relative to the original node.
   - `'L'`: Attach the duplicate as the left child of the original node.
   - `'R'`: Attach the duplicate as the right child of the original node.

#### Returns:
- This function does not return a value. It modifies the tree in-place.

---

## Code Breakdown

### `create_node`
```c
struct node* create_node(const char *key) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = strdup(key); // Dynamically allocate memory for the key
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
```
- **Purpose:** Creates a new binary tree node.
- **Steps:**
  1. Allocates memory for a new node using `malloc`.
  2. Duplicates the string `key` using `strdup` to ensure that the node owns its copy of the key.
  3. Initializes the left and right child pointers to `NULL`.
  4. Returns a pointer to the new node.

### `double_tree`
```c
void double_tree(struct node *root, char flag) {
    if (root == NULL) {
        return;
    }

    // Recursively process left and right subtrees
    double_tree(root->left, flag);
    double_tree(root->right, flag);

    // Create a duplicate node
    struct node *duplicate = create_node(root->key);

    if (flag == 'L') {
        duplicate->left = root->left;
        root->left = duplicate;
    } else if (flag == 'R') {
        duplicate->right = root->right;
        root->right = duplicate;
    }
}
```
- **Purpose:** Duplicates every node in the tree and attaches the duplicate as specified by the flag.
- **Steps:**
  1. **Base Case:** If the current node (`root`) is `NULL`, the function returns immediately.
  2. **Recursive Calls:**
     - Processes the left subtree by recursively calling `double_tree(root->left, flag)`.
     - Processes the right subtree by recursively calling `double_tree(root->right, flag)`.
  3. **Node Duplication:**
     - Calls `create_node(root->key)` to create a duplicate of the current node.
  4. **Attach Duplicate:**
     - If `flag == 'L'`, attaches the duplicate node as the left child of the current node and adjusts the original left child to become the left child of the duplicate.
     - If `flag == 'R'`, attaches the duplicate node as the right child of the current node and adjusts the original right child to become the right child of the duplicate.

---

## Example Execution

### Input Binary Tree:
```
     A
    / \
   B   C
```

### Function Call:
```c
double_tree(root, 'L');
```

### Output Binary Tree:
```
         A
        / \
       A   C
      /   / \
     B   C   NULL
    / \
   B   NULL
```
- The duplicate nodes are added as left children of their respective originals.

### Function Call:
```c
double_tree(root, 'R');
```

### Output Binary Tree:
```
     A
    / \
   B   A
      / \
     NULL C
          / \
         NULL C
```
- The duplicate nodes are added as right children of their respective originals.

---

## Memory Considerations

1. **Memory Allocation:**
   - Memory is dynamically allocated for each duplicate node using `malloc` in the `create_node` function.
   - The string keys are also dynamically allocated using `strdup`.

2. **Memory Deallocation:**
   - The user must ensure proper deallocation of the entire tree (including duplicates) to prevent memory leaks.
   - A post-order traversal can be used to free all nodes.

---

## Edge Cases
1. **Empty Tree:**
   - If the input tree is `NULL`, the function does nothing.

2. **Single Node Tree:**
   - If the tree contains only one node, a single duplicate node is created and attached according to the flag.

3. **Invalid Flag:**
   - If the `flag` is not `'L'` or `'R'`, the function does not perform any action on the tree.

---

## Complexity Analysis

1. **Time Complexity:**
   - The function processes each node exactly once and performs constant-time operations for duplication and attachment.
   - Total time complexity: **O(n)**, where `n` is the number of nodes in the tree.

2. **Space Complexity:**
   - The function uses a recursive approach, and the maximum depth of the recursion stack is proportional to the height of the tree.
   - Space complexity: **O(h)**, where `h` is the height of the tree.

---

## Summary
The `double_tree` function is a recursive utility for duplicating nodes in a binary tree. It provides flexibility to attach duplicates either as left or right children, depending on the user's preference. Proper memory management and flag validation are critical when using this function in larger applications.


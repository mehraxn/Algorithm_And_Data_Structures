# Binary Search Tree from Sorted Array

This README provides a detailed, line-by-line explanation of the `main.c` program, which demonstrates how to construct a Binary Search Tree (BST) from a sorted array and perform a preorder traversal.

---

```c
// main.c
#include <stdio.h>
#include <stdlib.h>
```

* `// main.c`
  A comment indicating the filename.

* `#include <stdio.h>`
  Includes the Standard I/O library, needed for `printf`.

* `#include <stdlib.h>`
  Includes the Standard Library, needed for `malloc` and `free` (if used).

---

```c
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
```

Defines a `TreeNode` structure for the BST:

1. `int val;` — stores the value of the node.
2. `struct TreeNode *left;` — pointer to the left child.
3. `struct TreeNode *right;` — pointer to the right child.

---

```c
static struct TreeNode* newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    if (!node) return NULL;
    node->val   = val;
    node->left  = node->right = NULL;
    return node;
}
```

`newNode` creates and initializes a new tree node:

1. `static struct TreeNode* newNode(int val)` — declares a static function returning a pointer to `TreeNode`.
2. `struct TreeNode *node = malloc(sizeof(*node));` — allocates memory for one node.
3. `if (!node) return NULL;` — checks for allocation failure.
4. `node->val = val;` — sets the node's value.
5. `node->left = node->right = NULL;` — initializes both child pointers to `NULL`.
6. `return node;` — returns the newly created node.

---

```c
static struct TreeNode* insert(struct TreeNode *root, int val) {
    if (!root)
        return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    // duplicates ignored
    return root;
}
```

`insert` adds a value to the BST, maintaining order:

1. `static struct TreeNode* insert(struct TreeNode *root, int val)` — static function taking the current root and the value to insert.
2. `if (!root) return newNode(val);` — if the subtree is empty, create a new node.
3. `if (val < root->val)` — if the value is less than current node's value:

   * `root->left = insert(root->left, val);` — insert recursively into the left subtree.
4. `else if (val > root->val)` — if greater:

   * `root->right = insert(root->right, val);` — insert recursively into the right subtree.
5. `// duplicates ignored` — if equal, do nothing (no insertion).
6. `return root;` — return the (possibly updated) root pointer.

---

```c
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    struct TreeNode *root = newNode(nums[0]);
    for (int i = 1; i < numsSize; i++)
        insert(root, nums[i]);
    return root;
}
```

`sortedArrayToBST` builds a BST by inserting elements in order:

1. `struct TreeNode* sortedArrayToBST(int* nums, int numsSize)` — takes a sorted array `nums` of length `numsSize`.
2. `if (numsSize == 0) return NULL;` — handle empty array.
3. `struct TreeNode *root = newNode(nums[0]);` — initialize the root with the first element.
4. `for (int i = 1; i < numsSize; i++)` — iterate over remaining elements:

   * `insert(root, nums[i]);` — insert each element into the BST.
5. `return root;` — return the constructed BST.

> **Note:** Inserting sequentially produces an unbalanced BST for sorted input.

---

```c
// Simple preorder print for demonstration:
void preorder(struct TreeNode *r) {
    if (!r) return;
    printf("%d ", r->val);
    preorder(r->left);
    preorder(r->right);
}
```

`preorder` prints node values in preorder traversal (root-left-right):

1. `void preorder(struct TreeNode *r)` — takes a pointer to a node.
2. `if (!r) return;` — base case: do nothing for `NULL`.
3. `printf("%d ", r->val);` — print the current node's value followed by a space.
4. `preorder(r->left);` — traverse the left subtree.
5. `preorder(r->right);` — traverse the right subtree.

---

```c
int main(void) {
    int nums[] = {-10, -3, 0, 5, 9};
    int n = sizeof(nums)/sizeof(*nums);
    struct TreeNode *bst = sortedArrayToBST(nums, n);
    printf("Preorder of (unbalanced) BST:\n");
    preorder(bst);
    printf("\n");
    return 0;
}
```

`main` function to demonstrate the BST:

1. `int nums[] = {-10, -3, 0, 5, 9};` — example sorted array.
2. `int n = sizeof(nums)/sizeof(*nums);` — calculates the number of elements.
3. `struct TreeNode *bst = sortedArrayToBST(nums, n);` — builds the BST.
4. `printf("Preorder of (unbalanced) BST:\n");` — prints a header.
5. `preorder(bst);` — prints the BST values in preorder.
6. `printf("\n");` — prints a newline.
7. `return 0;` — exits the program with success.

---

## Summary

* The program defines a simple BST implementation in C.
* It converts a sorted array into a BST by successive insertions (leading to an unbalanced tree).
* It demonstrates a preorder traversal to print the stored values.

You can compile and run this program using:

```bash
gcc -o bst main.c
./bst
```

---

*End of README.md*

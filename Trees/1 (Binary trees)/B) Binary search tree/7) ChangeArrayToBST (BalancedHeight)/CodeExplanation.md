## Balanced BST Construction and Preorder Traversal in C

This project demonstrates how to build a height-balanced Binary Search Tree (BST) from a sorted array and print its pre-order traversal. It includes a single source file, `main.c`, which implements all necessary functions and a `main` driver.

---

### File Structure

```
project/
└── main.c     # Source code implementing BST construction and traversal
```

---

### Overview

A height-balanced BST ensures that the depth difference between left and right subtrees of any node is at most one, leading to efficient operations (search, insert, delete) with average time complexity O(log n). Given a sorted array, we can construct such a tree by selecting the middle element as the root, then recursively building left and right subtrees from the two halves of the array.

---

### Code Walkthrough

```c
#include <stdio.h>
#include <stdlib.h>
```

* **Headers**: `stdio.h` for input/output functions and `stdlib.h` for dynamic memory allocation.

```c
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
```

* **`TreeNode` structure**: Represents a node in the BST, storing an integer `val` and pointers to left/right children.

```c
struct TreeNode* newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    if (!node) return NULL;
    node->val   = val;
    node->left  = node->right = NULL;
    return node;
}
```

* **`newNode` function**: Allocates memory for a new `TreeNode`, initializes the value and child pointers.
* **Error check**: Returns `NULL` if memory allocation fails.

```c
struct TreeNode* buildBST(int *nums, int l, int r) {
    if (l > r)
        return NULL;
    int mid = l + (r - l) / 2;
    struct TreeNode *root = newNode(nums[mid]);
    root->left  = buildBST(nums, l,     mid - 1);
    root->right = buildBST(nums, mid + 1, r);
    return root;
}
```

* **`buildBST` helper**:

  1. **Base case**: If the sub-array indices cross (`l > r`), return `NULL`.
  2. **Mid calculation**: `mid = l + (r - l) / 2` to prevent overflow and pick the middle element.
  3. **Recursive construction**: Left subtree from `nums[l..mid-1]`, right subtree from `nums[mid+1..r]`.

```c
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return NULL;
    } else {
        return buildBST(nums, 0, numsSize - 1);
    }
}
```

* **`sortedArrayToBST` wrapper**: Validates input size and calls `buildBST` on the full array.

```c
void preorder(struct TreeNode *r) {
    if (!r) return;
    printf("%d ", r->val);
    preorder(r->left);
    preorder(r->right);
}
```

* **`preorder` traversal**: Prints node values in pre-order (root, left, right) using recursion.

```c
int main(void) {
    int nums[] = {-10, -3, 0, 5, 9};
    int n = sizeof(nums)/sizeof(*nums);
    struct TreeNode *bst = sortedArrayToBST(nums, n);
    printf("Preorder of (balanced) BST:\n");
    preorder(bst);
    printf("\n");
    return 0;
}
```

* **`main` function**:

  1. Defines a sorted array `nums`.
  2. Determines its size `n`.
  3. Builds a balanced BST by calling `sortedArrayToBST`.
  4. Prints the pre-order traversal of the resulting tree.

---

### How It Works

1. **Balanced root selection**: By always choosing the middle element as the root, the tree is kept as balanced as possible.
2. **Divide and conquer**: Recursively apply the same logic to left and right halves.
3. **Traversal**: Pre-order prints the root before its subtrees, giving a visual of how the tree is constructed.

For the sample array `{-10, -3, 0, 5, 9}`:

```
       0
      / \
   -10   5
     \     \
     -3     9
```

Pre-order output: `0 -10 -3 5 9`

---

### Compilation and Execution

1. **Compile**:

   ```bash
   gcc -o bst main.c
   ```
2. **Run**:

   ```bash
   ./bst
   ```

Expected output:

```
Preorder of (balanced) BST:
0 -10 -3 5 9
```

---

### Memory Management & Notes

* This implementation does **not** free allocated nodes. In production code, traverse the tree post-order and `free()` each node to avoid memory leaks.
* For large arrays, recursion depth could be significant; ensure your environment allows sufficient stack depth or convert to an iterative approach if needed.

---

### Conclusion

This example provides a clear demonstration of building a height-balanced BST from a sorted array in C and performing a pre-order traversal. It highlights key concepts: dynamic memory allocation, recursion, and tree data structures.

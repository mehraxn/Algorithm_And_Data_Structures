# Binary Search Tree: Definition and Insertion

## 1. Main Property

A **Binary Search Tree (BST)** is a binary tree in which, for every node:

* All keys in its **left** subtree are **strictly less** than the node’s key.
* All keys in its **right** subtree are **greater than or equal** to the node’s key.

This ordering property allows efficient search, insertion, and deletion in $O(h)$ time (where $h$ is the tree height).

## 2. Node Structure

```c
// represents a node storing a string key
typedef struct node_s {
    char         *key;    // string key
    int           size;   // number of nodes in the subtree rooted here
    struct node_s *parent;
    struct node_s *left;
    struct node_s *right;
} node_t;
```

* **parent**: pointer to this node’s parent (or NULL for the root).
* **size**: number of nodes in the subtree rooted at this node (including itself).

## 3. Insertion Function

We insert a new key as a leaf, updating:

1. **size** of every node along the search path (increment by 1).
2. **parent** pointer of the newly created node.

Prototype:

```c
node_t *insert(node_t *root, char *key);
```

* **root**: pointer to the root of the BST (may be NULL).
* **key**: the string to insert.
* Returns a pointer to the newly inserted node (or the new root if the tree was empty).

```c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

node_t *insert(node_t *root, char *key) {
    node_t *parent = NULL;
    node_t *curr = root;

    // 1. Search where to insert, updating size along the path
    while (curr != NULL) {
        curr->size++;  // increment subtree size
        parent = curr;
        // compare strings
        if (strcmp(key, curr->key) < 0) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // 2. Allocate and initialize the new node
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node) {
        perror("malloc");
        return NULL;
    }
    new_node->key = strdup(key);
    new_node->size = 1;
    new_node->parent = parent;
    new_node->left = new_node->right = NULL;

    // 3. Link into the tree
    if (parent == NULL) {
        // Tree was empty: new node is the root
        root = new_node;
    } else if (strcmp(key, parent->key) < 0) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    // 4. Return the newly inserted node (or new root if needed)
    return new_node;
}
```

### Notes:

* We use `strcmp` for string comparisons.
* We increment `size` on each visited node before descending.
* The new node’s `parent` is set to the last non-NULL node on the path.
* If the original `root` was NULL, we return the new node as the root.

---

*End of README*

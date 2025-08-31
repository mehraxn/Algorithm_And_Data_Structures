#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_s tree_t;
struct tree_s {
    char *string;
    int sizeOfString;
    tree_t *left;
    tree_t *right;
};

typedef struct heap_s heap_t;
struct heap_s {
    tree_t **array;  // FIXED: Should be pointer to pointer for array of tree pointers
    int heapSize;
};  // FIXED: Added missing semicolon

// ADDED: Missing count function to count nodes in tree
int count(tree_t *root) {
    if (root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

// FIXED: Complete rewrite of tree_to_array using BFS as suggested
tree_t **tree_to_array(tree_t *root) {
    if (root == NULL) return NULL;

    int total_nodes = count(root);
    tree_t **array = (tree_t **)malloc(total_nodes * sizeof(tree_t *));  // FIXED: Proper dynamic allocation
    tree_t **queue = (tree_t **)malloc(total_nodes * sizeof(tree_t *));  // ADDED: Queue for BFS

    int front = 0, rear = 0, array_index = 0;

    queue[rear++] = root;  // Start BFS with root

    while (front < rear) {  // FIXED: Condition should be front < rear, not front < root
        int levelOrder = rear - front;  // KEPT: Calculate nodes at current level

        for (int i = 0; i < levelOrder; i++) {  // KEPT: Process each level completely
            tree_t *node = queue[front++];
            array[array_index++] = node;  // Add current node to result array

            // Add children to queue if they exist
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }

    free(queue);  // FIXED: Free the temporary queue
    return array;
}

// FIXED: Corrected heap insertion logic
void insert(heap_t *heap, tree_t *new_node) {
    int index = heap->heapSize;  // FIXED: Use more descriptive variable name
    heap->heapSize++;

    // FIXED: Proper parent index calculation and comparison logic
    while (index > 0 && strcmp(heap->array[(index - 1) / 2]->string, new_node->string) < 0) {
        heap->array[index] = heap->array[(index - 1) / 2];
        index = (index - 1) / 2;  // FIXED: Removed unnecessary int() cast and fixed formula
    }
    heap->array[index] = new_node;
}

// FIXED: Complete the function and fix all issues
tree_t *fill(tree_t *root, char *s) {
    tree_t **array1 = tree_to_array(root);  // FIXED: Proper pointer type

    heap_t heap_struct;  // FIXED: Renamed to avoid confusion with temp node
    heap_struct.array = array1;
    heap_struct.heapSize = count(root);

    tree_t *new_node = (tree_t *)malloc(sizeof(tree_t));  // FIXED: Renamed to avoid name conflict
    new_node->string = (char *)malloc(strlen(s) + 1);  // ADDED: Allocate memory for string
    strcpy(new_node->string, s);  // ADDED: Copy string content
    new_node->sizeOfString = strlen(s);
    new_node->left = NULL;
    new_node->right = NULL;

    insert(&heap_struct, new_node);  // FIXED: Pass heap struct, not array

    // ADDED: Find the position to insert the new node (leftmost incomplete level)
    // This implements the level-order completeness requirement
    int target_index = heap_struct.heapSize - 1;  // Position of newly inserted node

    // ADDED: Convert back from heap array to tree structure
    // Find parent position and attach new node
    if (target_index > 0) {
        int parent_index = (target_index - 1) / 2;
        tree_t *parent = heap_struct.array[parent_index];

        // Attach as left or right child based on position
        if (target_index % 2 == 1) {  // Left child
            parent->left = new_node;
        } else {  // Right child
            parent->right = new_node;
        }
    } else {
        // ADDED: If tree was empty, new node becomes root
        root = new_node;
    }

    return root;  // ADDED: Return the root of the modified tree
}
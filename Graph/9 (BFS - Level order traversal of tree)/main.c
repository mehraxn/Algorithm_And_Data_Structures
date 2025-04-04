#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    // Handle empty tree case
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // We'll use a queue for BFS
    struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    // We'll store the result temporarily before reversing
    int** result = (int**)malloc(2000 * sizeof(int*));
    int* colSizes = (int*)malloc(2000 * sizeof(int));
    int levelCount = 0;

    // Start BFS with root
    queue[rear++] = root;

    while (front < rear) {
        // Get the size of current level
        int levelSize = rear - front;

        // Allocate space for current level
        result[levelCount] = (int*)malloc(levelSize * sizeof(int));
        colSizes[levelCount] = levelSize;

        // Process all nodes at current level
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            // Add the node value to result
            result[levelCount][i] = node->val;

            // Enqueue left child if exists
            if (node->left) {
                queue[rear++] = node->left;
            }

            // Enqueue right child if exists
            if (node->right) {
                queue[rear++] = node->right;
            }
        }

        levelCount++;
    }

    // Free the queue as we no longer need it
    free(queue);

    // Now we need to reverse the order of levels (bottom-up)
    int** bottomUpResult = (int**)malloc(levelCount * sizeof(int*));
    *returnColumnSizes = (int*)malloc(levelCount * sizeof(int));

    for (int i = 0; i < levelCount; i++) {
        bottomUpResult[i] = result[levelCount - 1 - i];
        (*returnColumnSizes)[i] = colSizes[levelCount - 1 - i];
    }

    // Free the colSizes array as we've transferred its data
    free(colSizes);
    // Free the result array but not its contents as they're now referenced by bottomUpResult
    free(result);

    *returnSize = levelCount;
    return bottomUpResult;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s node_t;
struct node_s {
    int key;
    int degree;
    node_t **child;
};

int count_nodes(node_t *root) {
    if (!root) return 0;
    int total = 1;
    for (int i = 0; i < root->degree; ++i)
        total += count_nodes(root->child[i]);
    return total;
}

int display_crowded_depth(node_t *root) {
    if (!root) return -1;

    int total = count_nodes(root);

    node_t **queue = (node_t **)malloc(total * sizeof(node_t *));
    int front = 0, rear = 0;

    int *bestKeys = (int *)malloc(total * sizeof(int)); // bigger than needed
    int bestCount = 0;
    int bestDepth = 0;

    queue[rear++] = root;
    int depth = 0;

    while (front < rear) {
        int levelSize = rear - front;
        int tempCount = 0;

        for (int i = 0; i < levelSize; i++) {
            node_t *node = queue[front++];
            bestKeys[tempCount++] = node->key; // reuse array for this level

            for (int k = 0; k < node->degree; k++) {
                if (node->child[k]) {
                    queue[rear++] = node->child[k];
                }
            }
        }

        if (levelSize > bestCount) {
            bestCount = levelSize;
            bestDepth = depth;
            // bestKeys[0..bestCount-1] now contains the keys of this level
        }

        depth++;
    }

    printf("%d ", bestDepth);
    for (int i = 0; i < bestCount; i++) {
        printf("%d ", bestKeys[i]);
    }
    printf("\n");

    free(queue);
    free(bestKeys);
    return bestDepth;
}

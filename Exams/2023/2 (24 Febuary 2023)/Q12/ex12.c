#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node** children;
    int numChildren;
} node_t;

void displayTree(node_t* root, int depth, int* depthCounts, node_t*** depthNodes) {
    depthNodes[depth] = realloc(depthNodes[depth], (depthCounts[depth] + 1) * sizeof(node_t*));
    depthNodes[depth][depthCounts[depth]] = root;
    depthCounts[depth]++;
    for (int i = 0; i < root->numChildren; i++) {
        displayTree(root->children[i], depth + 1, depthCounts, depthNodes);
    }
}

int compareNodes(const void* a, const void* b) {
    node_t* nodeA = *(node_t**)a;
    node_t* nodeB = *(node_t**)b;
    return nodeA->key - nodeB->key;
}

void printNodesInOrder(node_t** nodes, int count) {
    qsort(nodes, count, sizeof(node_t*), compareNodes);

    for (int i = 0; i < count; i++) {
        printf("%d ", nodes[i]->key);
    }
}

void calculateMaxDepth(node_t* node, int depth, int* maxDepth) {
    if (node == NULL) {
        return;
    }
    if (depth > *maxDepth) {
        *maxDepth = depth;
    }
    for (int i = 0; i < node->numChildren; i++) {
        calculateMaxDepth(node->children[i], depth + 1, maxDepth);
    }
}

void display(node_t* root) {
    int maxDepth = 0;
    calculateMaxDepth(root, 0, &maxDepth);
    int* depthCounts = calloc(maxDepth + 1, sizeof(int));
    node_t*** depthNodes = calloc(maxDepth + 1, sizeof(node_t**));

    displayTree(root, 0, depthCounts, depthNodes);

    for (int i = 0; i <= maxDepth; i++) {
        printf("Depth %d: ", i);
        printNodesInOrder(depthNodes[i], depthCounts[i]);
        printf("\n");
    }

    for (int i = 0; i <= maxDepth; i++) {
        free(depthNodes[i]);
    }
    free(depthNodes);
    free(depthCounts);
}
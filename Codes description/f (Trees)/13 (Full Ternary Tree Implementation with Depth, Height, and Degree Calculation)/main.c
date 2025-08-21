#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a tree node
typedef struct Node {
    char name[100];
    struct Node* child1;
    struct Node* child2;
    struct Node* child3;
} Node;

// Function to create a new node
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->child1 = newNode->child2 = newNode->child3 = NULL;
    return newNode;
}

// Function to calculate the depth of a node
int getDepth(Node* root, Node* node, int depth) {
    if (root == NULL) {
        return -1;
    }

    if (root == node) {
        return depth;
    }

    int d = getDepth(root->child1, node, depth + 1);
    if (d != -1) return d;

    d = getDepth(root->child2, node, depth + 1);
    if (d != -1) return d;

    return getDepth(root->child3, node, depth + 1);
}

// Function to calculate the height of a node
int getHeight(Node* node) {
    if (node == NULL) {
        return -1; // Height of null is -1
    }

    int h1 = getHeight(node->child1);
    int h2 = getHeight(node->child2);
    int h3 = getHeight(node->child3);

    // Return the maximum height among the children + 1 (for the current node)
    int maxHeight = (h1 > h2) ? h1 : h2;
    maxHeight = (maxHeight > h3) ? maxHeight : h3;
    return maxHeight + 1;
}

// Function to calculate the degree of a node
int getDegree(Node* node) {
    int degree = 0;
    if (node->child1 != NULL) degree++;
    if (node->child2 != NULL) degree++;
    if (node->child3 != NULL) degree++;
    return degree;
}

// Function to create the full ternary tree with 19 nodes and different names
Node* createFullTernaryTree() {
    Node* root = createNode("Alice");
    root->child1 = createNode("Bob");
    root->child2 = createNode("Charlie");
    root->child3 = createNode("David");

    root->child1->child1 = createNode("Eve");
    root->child1->child2 = createNode("Frank");
    root->child1->child3 = createNode("Grace");

    root->child2->child1 = createNode("Hannah");
    root->child2->child2 = createNode("Ivy");
    root->child2->child3 = createNode("Jack");

    root->child3->child1 = createNode("Katherine");
    root->child3->child2 = createNode("Liam");
    root->child3->child3 = createNode("Mia");

    root->child1->child1->child1 = createNode("Noah");
    root->child1->child1->child2 = createNode("Olivia");
    root->child1->child1->child3 = createNode("Paul");

    root->child2->child1->child1 = createNode("Quinn");
    root->child2->child1->child2 = createNode("Rita");
    root->child2->child1->child3 = createNode("Sam");

    root->child3->child1->child1 = createNode("Tom");
    root->child3->child1->child2 = createNode("Ursula");
    root->child3->child1->child3 = createNode("Vera");

    return root;
}

// Function to traverse the tree and print the depth, height, and degree of each node
void printNodeDetails(Node* root, Node* current) {
    if (current == NULL) return;

    int depth = getDepth(root, current, 0);
    int height = getHeight(current);
    int degree = getDegree(current);

    printf("Node: %s, Depth: %d, Height: %d, Degree: %d\n", current->name, depth, height, degree);

    printNodeDetails(root, current->child1);
    printNodeDetails(root, current->child2);
    printNodeDetails(root, current->child3);
}

int main() {
    // Create a full ternary tree with 19 nodes
    Node* root = createFullTernaryTree();

    // Print details for each node
    printNodeDetails(root, root);

    // Free allocated memory (in a real program, you should free memory)
    // For simplicity, memory is not freed here, but you should implement a cleanup function.

    return 0;
}

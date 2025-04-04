#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure of a tree node
typedef struct Node {
    char name[100];
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST in lexicographical order
Node* insert_tree(Node* root, const char* name) {
    if (root == NULL) {
        return createNode(name);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert_tree(root->left, name);
    } else {
        root->right = insert_tree(root->right, name);
    }

    return root;
}

// Function to perform pre-order traversal
void preOrder(Node* root) {
    if (root == NULL) return;

    printf("%s ", root->name); // Visit node
    preOrder(root->left);      // Traverse left subtree
    preOrder(root->right);     // Traverse right subtree
}

// Function to perform in-order traversal
void inOrder(Node* root) {
    if (root == NULL) return;

    inOrder(root->left);       // Traverse left subtree
    printf("%s ", root->name); // Visit node
    inOrder(root->right);      // Traverse right subtree
}

// Function to perform post-order traversal
void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);     // Traverse left subtree
    postOrder(root->right);    // Traverse right subtree
    printf("%s ", root->name); // Visit node
}

// Function to get a random name from a predefined list
const char* getRandomName() {
    static const char* names[] = {
            "John", "Alice", "Charlie", "Eve", "Bob", "Dave",
            "Grace", "Jack", "Frank", "Helen", "Ingrid", "Nora",
            "Mark", "Liam", "Zoe", "Oliver", "Mia", "Sophia",
            "Lily", "Lucas"
    };

    int numNames = sizeof(names) / sizeof(names[0]);
    return names[rand() % numNames];  // Return a random name
}

// Function to create the tree with random names inserted
Node* createTree(int n) {
    Node* root = NULL;

    // Insert n random names into the Binary Search Tree
    for (int i = 0; i < n; i++) {
        const char* name = getRandomName();
        printf("Inserting: %s\n", name);
        root = insert_tree(root, name);
    }

    return root;
}

// Main function
int main() {
    srand(time(NULL));  // Seed the random number generator

    int numNodes = 15;  // Number of names to insert into the tree
    Node* root = createTree(numNodes);

    // Print tree traversals
    printf("\nPre-order Traversal:\n");
    preOrder(root);

    printf("\nIn-order Traversal:\n");
    inOrder(root);

    printf("\nPost-order Traversal:\n");
    postOrder(root);

    return 0;
}

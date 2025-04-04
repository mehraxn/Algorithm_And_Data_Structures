#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
typedef struct Node {
    int key;         // The key (used to locate the item)
    int value;       // The value associated with the key
    struct Node* left;  // Pointer to left child
    struct Node* right; // Pointer to right child
} Node;

// Function to create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key-value pair into the BST
Node* insert(Node* root, int key, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(key, value);
    }

    // Otherwise, recur down the tree
    if (key < root->key) {
        root->left = insert(root->left, key, value);  // Insert in left subtree
    } else if (key > root->key) {
        root->right = insert(root->right, key, value);  // Insert in right subtree
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to retrieve a value by key from the BST
int retrieve(Node* root, int key) {
    if (root == NULL) {
        return -1;  // Key not found
    }

    // Search for the key
    if (key == root->key) {
        return root->value;  // Key found, return its value
    } else if (key < root->key) {
        return retrieve(root->left, key);  // Search in the left subtree
    } else {
        return retrieve(root->right, key);  // Search in the right subtree
    }
}

// In-order traversal of the BST (sorted order)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);  // Traverse left subtree
        printf("Key %d: Value %d\n", root->key, root->value);  // Visit the root
        inorder(root->right);  // Traverse right subtree
    }
}

// Pre-order traversal of the BST
void preorder(Node* root) {
    if (root != NULL) {
        printf("Key %d: Value %d\n", root->key, root->value);  // Visit the root
        preorder(root->left);  // Traverse left subtree
        preorder(root->right);  // Traverse right subtree
    }
}

// Post-order traversal of the BST
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);  // Traverse left subtree
        postorder(root->right);  // Traverse right subtree
        printf("Key %d: Value %d\n", root->key, root->value);  // Visit the root
    }
}

// Function to free the BST memory
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);  // Free left subtree
        freeTree(root->right);  // Free right subtree
        free(root);  // Free the current node
    }
}

int main() {
    Node* root = NULL;

    // Insert some key-value pairs into the BST
    root = insert(root, 50, 100);  // Key 50 -> Value 100
    root = insert(root, 30, 200);  // Key 30 -> Value 200
    root = insert(root, 70, 300);  // Key 70 -> Value 300
    root = insert(root, 20, 400);  // Key 20 -> Value 400
    root = insert(root, 40, 500);  // Key 40 -> Value 500
    root = insert(root, 60, 600);  // Key 60 -> Value 600
    root = insert(root, 80, 700);  // Key 80 -> Value 700

    // Retrieve and print values by key
    printf("Value at key 50: %d\n", retrieve(root, 50));  // Should print 100
    printf("Value at key 30: %d\n", retrieve(root, 30));  // Should print 200
    printf("Value at key 70: %d\n", retrieve(root, 70));  // Should print 300
    printf("Value at key 100: %d\n", retrieve(root, 100));  // Should print -1 (not found)

    // Print the entire tree in different traversal orders
    printf("\nIn-order traversal (sorted order):\n");
    inorder(root);

    printf("\nPre-order traversal:\n");
    preorder(root);

    printf("\nPost-order traversal:\n");
    postorder(root);

    // Free allocated memory
    freeTree(root);

    return 0;
}

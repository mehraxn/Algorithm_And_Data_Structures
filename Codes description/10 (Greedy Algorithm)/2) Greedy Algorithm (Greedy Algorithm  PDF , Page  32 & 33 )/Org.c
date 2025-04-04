#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size for priority queue
#define maxN 100

// Define a structure for the item (typically used in Huffman Tree nodes)
typedef struct item {
    char letter;
    int freq;
    struct item *left, *right;
} Item;

// Define the structure for the priority queue (PQ)
typedef struct pq {
    Item **array;
    int size;
    int capacity;
    int (*compare)(Item*, Item*);
} PQ;

// Function prototypes
PQ* pq_init(int capacity, int (*compare)(Item*, Item*));
void pq_insert(PQ *pq, Item *item);
Item* pq_extract_max(PQ *pq);
int pq_size(PQ *pq);
void pq_display(Item *root, char *code, int index);
Item* item_new(char letter, int freq);

// Comparison function for max-priority queue (max-heap based on frequency)
int item_compare(Item *a, Item *b) {
    return b->freq - a->freq;  // Returns negative if b has higher frequency
}

// Initialize priority queue
PQ* pq_init(int capacity, int (*compare)(Item*, Item*)) {
    PQ *pq = (PQ*)malloc(sizeof(PQ));
    pq->capacity = capacity;
    pq->size = 0;
    pq->array = (Item**)malloc(sizeof(Item*) * capacity);
    pq->compare = compare;
    return pq;
}

// Insert an item into the priority queue
void pq_insert(PQ *pq, Item *item) {
    if (pq->size >= pq->capacity) {
        printf("Priority Queue is full!\n");
        return;
    }
    pq->array[pq->size] = item;
    pq->size++;

    // Fix the max-heap property if violated (bubble-up operation)
    int i = pq->size - 1;
    while (i > 0 && pq->compare(pq->array[i], pq->array[(i - 1) / 2]) > 0) {
        Item *temp = pq->array[i];
        pq->array[i] = pq->array[(i - 1) / 2];
        pq->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Extract the maximum item from the priority queue
Item* pq_extract_max(PQ *pq) {
    if (pq->size == 0) {
        return NULL;
    }
    Item *max_item = pq->array[0];
    pq->size--;
    pq->array[0] = pq->array[pq->size];

    // Fix the max-heap property (heapify down operation)
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < pq->size && pq->compare(pq->array[left], pq->array[largest]) > 0) {
            largest = left;
        }
        if (right < pq->size && pq->compare(pq->array[right], pq->array[largest]) > 0) {
            largest = right;
        }
        if (largest != i) {
            Item *temp = pq->array[i];
            pq->array[i] = pq->array[largest];
            pq->array[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
    return max_item;
}

// Return the size of the priority queue
int pq_size(PQ *pq) {
    return pq->size;
}

// Create a new item
Item* item_new(char letter, int freq) {
    Item *item = (Item*)malloc(sizeof(Item));
    item->letter = letter;
    item->freq = freq;
    item->left = item->right = NULL;
    return item;
}

// Display the Huffman tree using pre-order traversal (for code generation)
void pq_display(Item *root, char *code, int index) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        code[index] = '\0';  // Null-terminate the string
        printf("%c: %s\n", root->letter, code);
    } else {
        code[index] = '0';
        pq_display(root->left, code, index + 1);
        code[index] = '1';
        pq_display(root->right, code, index + 1);
    }
}

// Main function with user input and Huffman tree construction
int main() {
    PQ *pq;
    Item *tmp, *l, *r, *root;
    char letter;
    int freq;

    pq = pq_init(maxN, item_compare);  // Initialize priority queue

    for (int i = 0; i < maxN; i++) {
        printf("Enter letter & frequency: ");
        scanf(" %c %d", &letter, &freq);  // Take input for each letter and frequency
        tmp = item_new(letter, freq);  // Create a new item (Huffman node)
        pq_insert(pq, tmp);  // Insert the item into the priority queue
    }

    // Build the Huffman tree by combining the two lowest frequency nodes
    while (pq_size(pq) > 1) {
        l = pq_extract_max(pq);  // Extract the two nodes with the highest frequency
        r = pq_extract_max(pq);
        tmp = item_new('!', l->freq + r->freq);  // Create a new internal node
        tmp->left = l;  // Left child is the first extracted node
        tmp->right = r;  // Right child is the second extracted node
        pq_insert(pq, tmp);  // Insert the new internal node back into the priority queue
    }

    // The last node in the priority queue is the root of the Huffman tree
    root = pq_extract_max(pq);

    // Generate and display the Huffman codes from the Huffman tree
    char code[maxN];
    pq_display(root, code, 0);

    // Free memory (optional cleanup)
    free(pq->array);
    free(pq);

    return 0;
}

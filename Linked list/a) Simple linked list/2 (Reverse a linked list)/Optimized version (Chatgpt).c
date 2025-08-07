#include <stdio.h>
#include <stdlib.h>

// Define the ListNode structure
typedef struct ListNode list;
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse a linked list (in-place)
list* reverse_linked_list(list *head) {
    list *prev = NULL;  // Initialize previous node to NULL
    list *current = head;  // Start with the head of the list
    list *next_node = NULL;  // To store the next node during traversal

    while (current != NULL) {
        next_node = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;  // Move 'prev' to the current node
        current = next_node;  // Move 'current' to the next node
    }

    return prev;  // 'prev' is the new head of the reversed list
}

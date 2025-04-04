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

// Utility function to print the linked list
void print_list(list *head) {
    list *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Utility function to create a new node
list* create_node(int val) {
    list *new_node = (list*)malloc(sizeof(list));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

// Test the function
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    list *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    printf("Original Linked List:\n");
    print_list(head);

    // Reverse the linked list
    head = reverse_linked_list(head);

    printf("\nReversed Linked List:\n");
    print_list(head);

    return 0;
}

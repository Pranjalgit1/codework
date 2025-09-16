#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Structure for stack node
struct StackNode {
    struct Node* data;  // Stack stores pointers to linked list nodes
    struct StackNode* next;
};

// Stack operations
void push(struct StackNode** top, struct Node* node) {
    struct StackNode* newStackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newStackNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newStackNode->data = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

struct Node* pop(struct StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    struct StackNode* temp = *top;
    struct Node* node = temp->data;
    *top = (*top)->next;
    free(temp);
    return node;
}

int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Linked list operations
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to reverse linked list iteratively using stack
void reverseLinkedList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Empty list or single node, nothing to reverse
    }
    
    struct StackNode* stack = NULL;
    struct Node* current = *head;
    
    // Push all nodes onto the stack
    while (current != NULL) {
        push(&stack, current);
        current = current->next;
    }
    
    // Pop nodes from stack and rebuild the list
    *head = pop(&stack);
    current = *head;
    
    while (!isEmpty(stack)) {
        current->next = pop(&stack);
        current = current->next;
    }
    current->next = NULL; // Set the last node's next to NULL
}

// Function to free the entire linked list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    
    printf("=== Linked List Reversal using Stack ===\n");
    
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    printf("Creating linked list: 1 -> 2 -> 3 -> 4 -> 5\n");
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    
    printf("Original list: ");
    displayList(head);
    
    // Reverse the list using stack
    printf("Reversing list using stack...\n");
    reverseLinkedList(&head);
    
    printf("Reversed list: ");
    displayList(head);
    
    // Free memory
    freeList(&head);
    
    return 0;
}

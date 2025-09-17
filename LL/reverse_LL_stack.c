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
    int choice, data, n;
    
    printf("=== Linked List Reversal using Stack ===\n");
    
    do {
        printf("\n1. Create linked list\n");
        printf("2. Add element to list\n");
        printf("3. Display list\n");
        printf("4. Reverse list using stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (head != NULL) {
                    freeList(&head);
                }
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Invalid number of elements!\n");
                    break;
                }
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insertAtEnd(&head, data);
                }
                printf("Linked list created successfully!\n");
                break;
                
            case 2:
                printf("Enter data to add: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Element %d added successfully!\n", data);
                break;
                
            case 3:
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    printf("Linked List: ");
                    displayList(head);
                }
                break;
                
            case 4:
                if (head == NULL) {
                    printf("List is empty! Nothing to reverse.\n");
                } else {
                    printf("Original list: ");
                    displayList(head);
                    reverseLinkedList(&head);
                    printf("Reversed list: ");
                    displayList(head);
                }
                break;
                
            case 5:
                printf("Exiting program...\n");
                freeList(&head);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 5);
    
    return 0;
}

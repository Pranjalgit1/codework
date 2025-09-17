#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAfterK(struct Node** head, int k, int data);
void insertBeforeK(struct Node** head, int k, int data);
void deleteK(struct Node** head, int k);
void displayList(struct Node* head);
void freeList(struct Node** head);
int countNodes(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, k;
    
    printf("=== Linked List Operations Menu ===\n");
    
    do {
        printf("\n1. Create linked list\n");
        printf("2. Insert after position K (if K doesn't exist, insert at end)\n");
        printf("3. Insert before position K (if K doesn't exist, insert at beginning)\n");
        printf("4. Delete element at position K\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the number of elements to create: ");
                int n;
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Invalid number of elements!\n");
                    break;
                }
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insertAfterK(&head, -1, data); // Using -1 as dummy value to insert at end
                }
                printf("Linked list created successfully!\n");
                break;
                
            case 2:
                printf("Enter the position K (after which to insert): ");
                scanf("%d", &k);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfterK(&head, k, data);
                break;
                
            case 3:
                printf("Enter the position K (before which to insert): ");
                scanf("%d", &k);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBeforeK(&head, k, data);
                break;
                
            case 4:
                if (head == NULL) {
                    printf("List is empty! Nothing to delete.\n");
                    break;
                }
                printf("Enter the position K to delete: ");
                scanf("%d", &k);
                deleteK(&head, k);
                break;
                
            case 5:
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    printf("Linked List: ");
                    displayList(head);
                    printf("\n");
                }
                break;
                
            case 6:
                printf("Exiting program...\n");
                freeList(&head);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 6);
    
    return 0;
}

// Function to create a new node
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

// Function to count nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Function to insert after position K (if K doesn't exist, insert at end)
void insertAfterK(struct Node** head, int k, int data) {
    // If list is empty, create first node
    if (*head == NULL) {
        *head = createNode(data);
        printf("List was empty. Element %d inserted as first node.\n", data);
        return;
    }
    
    // If k is -1 (special case for creating list), insert at end
    if (k == -1) {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(data);
        return;
    }
    
    // Validate index
    if (k < 0) {
        printf("Invalid position! Position must be >= 0.\n");
        return;
    }
    
    struct Node* current = *head;
    int index = 0;
    
    // Find the node at position K
    while (current != NULL && index < k) {
        current = current->next;
        index++;
    }
    
    // If K position not found (beyond list length), insert at end
    if (current == NULL) {
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(data);
        printf("Position %d not found. Element %d inserted at end.\n", k, data);
    } else {
        // Insert after the found position
        struct Node* newNode = createNode(data);
        newNode->next = current->next;
        current->next = newNode;
        printf("Element %d inserted after position %d successfully!\n", data, k);
    }
}

// Function to insert before position K (if K doesn't exist, insert at beginning)
void insertBeforeK(struct Node** head, int k, int data) {
    // If list is empty, create first node
    if (*head == NULL) {
        *head = createNode(data);
        printf("List was empty. Element %d inserted as first node.\n", data);
        return;
    }
    
    // Validate index
    if (k < 0) {
        printf("Invalid position! Position must be >= 0.\n");
        return;
    }
    
    // If K is 0, insert at beginning
    if (k == 0) {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
        printf("Element %d inserted at beginning (before position %d).\n", data, k);
        return;
    }
    
    struct Node* current = *head;
    int index = 0;
    
    // Find the node before position K
    while (current->next != NULL && index < k - 1) {
        current = current->next;
        index++;
    }
    
    // If K position not found, insert at beginning
    if (current->next == NULL && index < k - 1) {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
        printf("Position %d not found. Element %d inserted at beginning.\n", k, data);
    } else {
        // Insert before the found position
        struct Node* newNode = createNode(data);
        newNode->next = current->next;
        current->next = newNode;
        printf("Element %d inserted before position %d successfully!\n", data, k);
    }
}

// Function to delete element at position K
void deleteK(struct Node** head, int k) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    // Validate index
    if (k < 0) {
        printf("Invalid position! Position must be >= 0.\n");
        return;
    }
    
    // If K is 0, delete first node
    if (k == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Element at position %d deleted successfully!\n", k);
        return;
    }
    
    struct Node* current = *head;
    int index = 0;
    
    // Find the node before position K
    while (current->next != NULL && index < k - 1) {
        current = current->next;
        index++;
    }
    
    // If K position not found
    if (current->next == NULL) {
        printf("Position %d not found! Cannot delete.\n", k);
        return;
    }
    
    // Delete the node at position K
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    printf("Element at position %d deleted successfully!\n", k);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    int index = 0;
    while (current != NULL) {
        printf("%d[%d]", current->data, index);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
        index++;
    }
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

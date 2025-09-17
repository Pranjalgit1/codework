#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int value){
    struct Node *newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void display(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to detect cycle using slow/fast pointers
int hasCycle(struct Node *head){
    if(head == NULL || head->next == NULL) return 0;
    
    struct Node *slow = head;
    struct Node *fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;           // Move 1 step
        fast = fast->next->next;     // Move 2 steps
        
        if(slow == fast) return 1;   // Cycle detected
    }
    return 0;  // No cycle
}

// Function to find the starting point of cycle
struct Node* findCycleStart(struct Node *head){
    if(head == NULL || head->next == NULL) return NULL;
    
    // First phase: detect cycle
    struct Node *slow = head;
    struct Node *fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;  // Cycle detected
    }
    
    if(slow != fast) return NULL;  // No cycle
    
    // Second phase: find starting point
    slow = head;  // Reset slow to head
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;  // Starting point of cycle
}

// Function to find cycle length
int getCycleLength(struct Node *head){
    if(head == NULL || head->next == NULL) return 0;
    
    // Detect cycle
    struct Node *slow = head;
    struct Node *fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    
    if(slow != fast) return 0;  // No cycle
    
    // Count cycle length
    int length = 1;
    fast = fast->next;
    while(fast != slow){
        length++;
        fast = fast->next;
    }
    return length;
}

int main(){
    // Test case 1: No cycle
    struct Node *head1 = NULL;
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 4);
    insertAtEnd(&head1, 5);
    
    printf("List 1 (no cycle): ");
    display(head1);
    printf("Has cycle: %s\n", hasCycle(head1) ? "Yes" : "No");
    
    // Test case 2: With cycle
    struct Node *head2 = NULL;
    insertAtEnd(&head2, 1);
    insertAtEnd(&head2, 2);
    insertAtEnd(&head2, 3);
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 5);
    
    // Create cycle: 5 -> 3
    struct Node *temp = head2;
    while(temp->next != NULL) temp = temp->next;  // Go to last node
      // Point to node 3
    temp->next = head2->next->next;  // Create cycle
    
    printf("\nList 2 (with cycle): 1->2->3->4->5->3->...\n");
    printf("Has cycle: %s\n", hasCycle(head2) ? "Yes" : "No");
    
    struct Node *start = findCycleStart(head2);
    if(start != NULL){
        printf("Cycle starts at node with value: %d\n", start->data);
    }
    
    int cycleLength = getCycleLength(head2);
    printf("Cycle length: %d\n", cycleLength);
    
    return 0;
}

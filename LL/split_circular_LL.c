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
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node *tail = *head;
    while(tail->next != *head) tail = tail->next;
    tail->next = newNode;
    newNode->next = *head;
}

void display(struct Node *head){
    if(head == NULL) return;
    struct Node *temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

void splitCircularList(struct Node *head, struct Node **first, struct Node **second){
    if(head == NULL){
        *first = NULL;
        *second = NULL;
        return;
    }
    
    // Find the middle using slow and fast pointers
    struct Node *slow = head;
    struct Node *fast = head;
    
    // Move fast pointer 2 steps and slow pointer 1 step
    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // For even number of nodes, we want slow to point to the last node of first half
    // For odd number of nodes, slow is already at the correct position
    if(fast->next->next == head){
        // Even case: fast reached second-to-last node
        // slow is at the correct position (last node of first half)
    } else {
        // Odd case: fast reached last node
        // slow is at the correct position (last node of first half)
    }
    
    // Set first half
    *first = head;
    
    // Set second half
    *second = slow->next;
    
    // Make first half circular
    slow->next = *first;
    
    // Make second half circular
    struct Node *temp = *second;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = *second;
}

int main(){
    struct Node *head = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;
    
    // Create circular list: 1->2->3->4->5->1
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head,6);
    
    printf("Original circular list: ");
    display(head);
    
    splitCircularList(head, &first, &second);
    
    printf("First half: ");
    display(first);
    
    printf("Second half: ");
    display(second);
    
    return 0;
}

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

void reverseCircularList(struct Node **head){
    if(*head == NULL || (*head)->next == *head) return;
    
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next = NULL;
    
    // Store the original head to update the circular link
    struct Node *originalHead = *head;
    
    do{
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }while(curr != originalHead);
    
    // Update the circular link - the last node (now first) points to the new head
    originalHead->next = prev;
    
    // Update head to point to the new first node
    *head = prev;
}

int main(){
    struct Node *head = NULL;
    
    // Create circular list: 1->2->3->4->5->1
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    
    printf("Original circular list: ");
    display(head);
    
    reverseCircularList(&head);
    
    printf("Reversed circular list: ");
    display(head);
    
    return 0;
}

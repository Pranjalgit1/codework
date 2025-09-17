#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertatLast(int data, struct Node** head) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}

void reverseDLL(struct Node **head){
    struct Node* current,*nextnode;
    if(*head == NULL){
        return; //empty list
    }else{
        
        current = *head;
        while(current != NULL){
        nextnode = current->next;
        current->next = current->prev; 
        current->prev = nextnode;
        current = nextnode; }

    }

}

int main(){

    struct Node* head = NULL;
    insertatLast(1, &head);
    insertatLast(2, &head);
    insertatLast(3, &head);
    insertatLast(4, &head);
    insertatLast(5, &head);

    printf("Original Doubly Linked List:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    reverseDLL(&head);

    printf("Reversed Doubly Linked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
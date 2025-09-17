#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void append(int data, struct node **headRef){
    struct node* newnode = createNode(data);
    if (*headRef == NULL){
        *headRef = newnode;
        return;
    }
    struct node* temp = *headRef;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

struct node* recursiveReverse(struct node* head){
    if (head == NULL || head->next == NULL) return head;
    struct node* newHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead; //return modified head
}

void printlist(struct node* head){
    struct node* temp = head;
    while (temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next; 
    }
    printf("NULL\n");
}

int main(){
    struct node* head = NULL;
    append(1, &head);
    append(2, &head);
    append(3, &head);
    append(4, &head);

    printf("Original: ");
    printlist(head);

    head = recursiveReverse(head);

    printf("Reversed: ");
    printlist(head);
    return 0;
}
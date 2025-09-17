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

void insertAtStart(struct Node **head, int value){
    struct Node *newNode = createNode(value);
    if(*head == NULL){
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node *tail = *head;
    while(tail->next != *head) tail = tail->next;
    newNode->next = *head;
    tail->next = newNode;
    *head = newNode;
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

void insertBeforeK(struct Node **head, int key, int value){
    if(*head == NULL) return;
    if((*head)->data == key){
        insertAtStart(head, value);
        return;
    }
    struct Node *prev = *head;
    struct Node *curr = (*head)->next;
    while(curr != *head){
        if(curr->data == key){
            struct Node *newNode = createNode(value);
            prev->next = newNode;
            newNode->next = curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void insertAtK(struct Node **head, int k, int value){
    if(k <= 1 || *head == NULL){
        insertAtStart(head, value);
        return;
    }
    int pos = 2;
    struct Node *prev = *head;
    struct Node *curr = (*head)->next;
    while(curr != *head && pos < k){
        prev = curr;
        curr = curr->next;
        pos++;
    }
    struct Node *newNode = createNode(value);
    prev->next = newNode;
    newNode->next = curr;
}

void deleteFromStart(struct Node **head){
    if(*head == NULL) return;
    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *tail = *head;
    while(tail->next != *head) tail = tail->next;
    struct Node *oldHead = *head;
    *head = (*head)->next;
    tail->next = *head;
    free(oldHead);
}

void deleteFromEnd(struct Node **head){
    if(*head == NULL) return;
    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *prev = NULL;
    struct Node *curr = *head;
    while(curr->next != *head){
        prev = curr;
        curr = curr->next;
    }
    prev->next = *head;
    free(curr);
}

void deleteAtK(struct Node **head, int k){
    if(*head == NULL || k <= 0) return;
    if(k == 1){
        deleteFromStart(head);
        return;
    }
    int idx = 1;
    struct Node *prev = *head;
    struct Node *curr = (*head)->next;
    while(curr != *head && idx + 1 < k){
        prev = curr;
        curr = curr->next;
        idx++;
    }
    if(curr != *head){
        prev->next = curr->next;
        free(curr);
    }
}
void display(struct Node *head){
    struct Node *temp = head;
    if(head == NULL){
        return; //empty
    }else{
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }

}

int main(){
    struct Node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 40);
    insertAtK(&head, 3, 30);
    insertAtStart(&head, 5);
    display(head); printf("\n");
    deleteFromStart(&head);
    deleteFromEnd(&head);
    deleteAtK(&head, 2);
    display(head); printf("\n");
    return 0;
}
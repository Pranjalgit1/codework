#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int value){
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct ListNode **head, int value){
    struct ListNode *newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct ListNode *temp = *head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void display(struct ListNode *head){
    struct ListNode *temp = head;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct ListNode* mergeUnsortedLists(struct ListNode *list1, struct ListNode *list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    struct ListNode *dummy = createNode(0); // dummy node
    struct ListNode *temp = dummy;          // temp points to dummy node
    
    // First while loop: add all elements from list1
    struct ListNode *t1 = list1;
    while(t1 != NULL){
        temp->next = t1;    // link current node from list1
        temp = t1;          // move temp to current node
        t1 = t1->next;      // move t1 to next node in list1
    }
    
    // Second while loop: add all elements from list2
    struct ListNode *t2 = list2;
    while(t2 != NULL){
        temp->next = t2;    // link current node from list2
        temp = t2;          // move temp to current node
        t2 = t2->next;      // move t2 to next node in list2
    }
    
    return dummy->next; // return the head pointer
}

int main(){
    // Create first unsorted list: 3->1->4
    struct ListNode *list1 = NULL;
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 4);
    
    // Create second unsorted list: 2->5->6
    struct ListNode *list2 = NULL;
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 5);
    insertAtEnd(&list2, 6);
    
    printf("List 1: ");
    display(list1);
    
    printf("List 2: ");
    display(list2);
    
    // Merge the two lists
    struct ListNode *merged = mergeUnsortedLists(list1, list2);
    
    printf("Merged list: ");
    display(merged);
    
    return 0;
}

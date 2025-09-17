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

struct ListNode* mergeTwoLists(struct ListNode *list1, struct ListNode *list2){
    if(list1 == NULL) return list2;
    else if(list2 == NULL) return list1;
    
    struct ListNode *t1 = list1;
    struct ListNode *t2 = list2;
    struct ListNode *dummy = createNode(0); // dummy node
    struct ListNode *temp = dummy;          // temp points to dummy node
    
    while(t1 != NULL && t2 != NULL){
        if(t1->val <= t2->val){
            temp->next = t1; // temp points to t1
            temp = t1;
            t1 = t1->next;   // t1 moves to next
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    temp->next = (t1 == NULL) ? t2 : t1;
    return dummy->next; // return the head pointer
}

int main(){
    // Create first sorted list: 1->2->4
    struct ListNode *list1 = NULL;
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 4);
    
    // Create second sorted list: 1->3->4
    struct ListNode *list2 = NULL;
    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 4);
    
    printf("List 1: ");
    display(list1);
    
    printf("List 2: ");
    display(list2);
    
    // Merge the two lists
    struct ListNode *merged = mergeTwoLists(list1, list2);
    
    printf("Merged list: ");
    display(merged);
    
    return 0;
}

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

struct ListNode* deleteDuplicates(struct ListNode *head){
    struct ListNode *dummyNode = createNode(-1);
    dummyNode->next = head;
    struct ListNode *prev = dummyNode;
    struct ListNode *curr = head;
    
    while(curr != NULL){
        // if current node is a duplicate
        if(curr->next != NULL && curr->val == curr->next->val){
            // traverse till end of duplicates
            while(curr->next != NULL && curr->val == curr->next->val){
                curr = curr->next;
            }
            // skip duplicated nodes
            prev->next = curr->next;
        } else {
            // we have found a unique node
            prev = prev->next;
        }
        curr = curr->next;
    }
    return dummyNode->next;
}

int main(){
    // Test case 1: [1,1,2,3,3]
    struct ListNode *head1 = NULL;
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 3);
    
    printf("Test 1 - Original: ");
    display(head1);
    
    head1 = deleteDuplicates(head1);
    printf("After removing duplicates: ");
    display(head1);
    
    // Test case 2: [1,1,2]
    struct ListNode *head2 = NULL;
    insertAtEnd(&head2, 1);
    insertAtEnd(&head2, 1);
    insertAtEnd(&head2, 2);
    
    printf("\nTest 2 - Original: ");
    display(head2);
    
    head2 = deleteDuplicates(head2);
    printf("After removing duplicates: ");
    display(head2);
    
    // Test case 3: [1,1,1]
    struct ListNode *head3 = NULL;
    insertAtEnd(&head3, 1);
    insertAtEnd(&head3, 1);
    insertAtEnd(&head3, 1);
    
    printf("\nTest 3 - Original: ");
    display(head3);
    
    head3 = deleteDuplicates(head3);
    printf("After removing duplicates: ");
    display(head3);
    
    return 0;
}

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

struct ListNode* removeElements(struct ListNode *head, int val){
    // Handle case where head needs to be removed
    while(head != NULL && head->val == val){
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }
    
    // If list becomes empty after removing head nodes
    if(head == NULL) return NULL;
    
    // Remove nodes from the middle and end
    struct ListNode *curr = head;
    while(curr->next != NULL){
        if(curr->next->val == val){
            struct ListNode *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    
    return head;
}

int main(){
    // Test case 1: [1,2,6,3,4,5,6], val = 6
    struct ListNode *head1 = NULL;
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 6);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 4);
    insertAtEnd(&head1, 5);
    insertAtEnd(&head1, 6);
    
    printf("Test 1 - Original: ");
    display(head1);
    
    head1 = removeElements(head1, 6);
    printf("After removing 6: ");
    display(head1);
    
    // Test case 2: [], val = 1
    struct ListNode *head2 = NULL;
    printf("\nTest 2 - Original: ");
    display(head2);
    
    head2 = removeElements(head2, 1);
    printf("After removing 1: ");
    display(head2);
    
    // Test case 3: [7,7,7,7], val = 7
    struct ListNode *head3 = NULL;
    insertAtEnd(&head3, 7);
    insertAtEnd(&head3, 7);
    insertAtEnd(&head3, 7);
    insertAtEnd(&head3, 7);
    
    printf("\nTest 3 - Original: ");
    display(head3);
    
    head3 = removeElements(head3, 7);
    printf("After removing 7: ");
    display(head3);
    
    return 0;
}

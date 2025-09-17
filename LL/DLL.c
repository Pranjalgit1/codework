#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};
/* removed global head */
struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void insertatstart(int data, struct node** head){
   struct node* newnode = createnode(data);
   if(*head==NULL){
    *head = newnode;
    return;
   }
   (*head)->prev = newnode;
   newnode->next = *head;
   *head = newnode;
}
void insertatlast(int data,struct node* head){
    struct node* newnode = createnode(data);
    if(head==NULL){
        head = newnode;
        return;
    }
    struct node* tail = head;
    while(tail->next!= NULL){
        tail = tail->next;
    }
    tail->next = newnode;
    newnode->next = NULL;
    newnode->prev = tail;
    tail = newnode; // maintaing tail pointer at end
}

void insertbeforeK(int val,int k,struct node* head){
    int i = 1;
    struct node* temp = head;
    if(k < 0){
        printf("Invalid position\n");
    }else if(k ==1){
        insertatstart(val,&head);
    }else{
        struct node* newnode = createnode(val);
        while(i<k-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}
void insertafterK(int val,int k,struct node* head){
    int i = 1;
    struct node* temp = head;
    if(k < 0){
        printf("Invalid position\n");
    }else if(k ==1){
        insertatstart(val,&head);
    }else{
        struct node* newnode = createnode(val);
        while(i<k){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}
void deletefromstart(struct node**head){
    if(*head==NULL){
        printf("DLL is empty\n");
    }
    struct node* temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}
void deletefromlast(struct node* head){
    struct node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}
void deletethek(int k,struct node* head){
    int i =1;
    if(k==1){
        deletefromstart(&head);
    }else{
        struct node* temp = head;
        while(i<k){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}
void Print(struct node* head){
    struct node *temp = head;

    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
    struct node* head = NULL;
    insertatstart(2, &head); 
    insertatstart(4, &head); Print(head);
    insertatlast(6,head);
    insertatlast(8,head); Print(head);
   // insertbeforeK(5,3,head); Print(head);
   // insertafterK(7,4,head); Print(head);
    Print(head);
    deletethek(3,head);
    Print(head);
}
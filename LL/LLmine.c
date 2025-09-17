#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createnode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
    
}
int length(struct node *head){
    struct node *temp = head;
    int count = 0;
    while(temp!=0){
        temp = temp->next;
        count ++;
    }
    return count;
}
void insertatstart(struct node **head,int data){
    struct node *newnode = createnode(data);
    newnode->next = *head;
    *head = newnode;
}
void insertatend(int data,struct node *head){
    struct node *newnode = createnode(data);
    struct node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newnode;
}
void insertafterposition(int k,struct node *head,int data){
    int i=1;
    struct node *temp = head;
    if(k>length(head) && k<0){
        printf("invalid position");
        return;
    }else{
        struct node *newnode = createnode(data);
        while(i<k){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void deleteatstart(struct node *head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }else{
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
void deleteatend(struct node **head){
    struct node *temp = *head;
    struct node *prevnode;
    while(temp->next!=NULL){
        temp = temp->next;
        prevnode = temp;
    }
    if(temp == *head){
        head = 0;
        free(temp);
    }else{
        prevnode->next = NULL;
        free(temp);
    }
}
void deleteatposition(int k,struct node *head){
    struct node *nextnode;
    struct node *temp = head;
    int i = 1;
    if(k>length(head) && k<0){
        printf("invalid position\n");
        return;
    }else{
        while(i<k-1){
            temp = temp->next; //temp just before the node to be deleted
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next; //temp->next = temp->next->next;
        free(nextnode);
    }
}

int display(struct node *head){
    struct node *temp = head;
    int count=0;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    return count;
}
int main(){
    struct node *head = NULL;
    int data,k;
    int choice;
    do
    {
        printf("\n7.insert at start\n2.insert at end\n3.insert at position\n4.delete at start\n5.delete at end\n6.delete at position\n1.display\n8.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 7:
                printf("Enter data :");
                scanf("%d",&data);
                insertatstart(&head,data);
                break;
            case 2:
                printf("Enter data :");
                scanf("%d",&data);
                insertatend(data,head);
                break;
            case 3:
                printf("Enter position to insert after k(1-based) : ");
                scanf("%d",&k);
                printf("Enter data to insert after k : ");
                scanf("%d",&data);
                insertafterposition(k,head,data);
                break;
            case 4:
                deleteatstart(head);
                break;
            case 5:
                deleteatend(&head);
                break;
            case 6:
                printf("Enter position to delete(1 based)");
                scanf("%d",&k); 
                deleteatposition(k,head);
                break;
            case 1:
                int count = display(head);
                printf("total nodes : %d",count);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!=8);
    
    display(head);
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void enqueue(int value,struct node **front,struct node**rear);
void dequeue(struct node **front);
void peek(struct node *front,struct node *rear);
void display(struct node *front,struct node *rear);


void main(){
struct node* front=0;
struct node* rear=0;
int choice,running = 1,value;
while(running){
    printf("1. Enqueue\n2.Dequeue\n3.Peek\n4.Display\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter value to enqueue :");
                scanf("%d",&value);
                enqueue(value,&front,&rear);
                break;
        case 2: dequeue(&front);
                break;
        case 3: peek(front,rear);
                break;
        case 4: display(front,rear);
                break;  
        default:printf("invalid choice");
                break;      
    }
    printf("do you want to continue(0/1)? ");
    scanf("%d",&running);
}

}

void enqueue(int value,struct node **front,struct node**rear){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data = value;
    newnode->next = 0;
    if(*front == 0 && *rear == 0){
        *front = newnode; //insert at start
        *rear = newnode;
    }else{
        (*rear)->next = newnode;
        *rear = newnode;
    }
}
void dequeue(struct node **front){
    struct node*temp;
    temp = *front;
    if(*front == 0)return;//empty queue
    else{
        printf("dequeued element : %d\n",(*front)->data);
        *front = (*front)->next;
        free(temp);
    }
}
void peek(struct node *front,struct node *rear){
    if(front == 0 && rear == 0){
        printf("\nEmpty queue\n");
    }else{
        printf("%d\n",front->data);
    }
}
void display(struct node *front,struct node *rear){
    struct node *temp;
    if(front == 0 && rear == 0){
        printf("\nEmpty queue\n");
    }else{
        temp = front;
        while(temp!=0){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
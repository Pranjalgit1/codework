#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** front,struct Node** rear,int data){
    struct Node* newNode = createNode(data);
    //1st time insertion at front
    if(*front == 0 && *rear ==0){
        *front = *rear = newNode;
        (*rear)->next = *front;
    }else{
        //rest insertions
        (*rear)->next = newNode;
        *rear = newNode;
        (*rear)->next = *front;
    }
}

int dequeue(struct Node **front,struct Node **rear){
    struct Node *temp = *front;
    if(*front == 0){
        return -1; //empty queue
    }else if(*front == *rear){
        //1 element only
        *front = 0;
        *rear = 0;
        printf("dequeued : %d\n",temp->data);
    }else{
        *front = (*front)->next;
        (*rear)->next = *front;
        printf("dequeued : %d\n",temp->data);
        free(temp);
    }
}

int peek(struct Node *front){
    if(front == 0){
        return -1; //empty queue
    }else{
        return front->data;
    }
}

void display(struct Node *front){
    struct Node* temp = front;
    if(front == 0){
        return; //empty queue
    }else{
        while(temp->next!=front){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d ",temp->data);
    }
}

int main(){
    struct Node* front = 0;
    struct Node* rear = 0;
    int choice,running=1,data;
    while(running){
        printf("1. enqueue\n2.dequeue\n3.peek\n4.display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Element to enqueue : ");
                    scanf("%d",&data);
                    enqueue(&front,&rear,data);
                    break;
            case 2: dequeue(&front,&rear);
                    break;
            case 3: printf("front element : %d\n",peek(front));
                    break;
            case 4: display(front);
                    break;
            default: printf("Invalid choice!\n");                             
        }
        printf("do you want to continue(0/1)? ");
        scanf("%d",&running);
    }
    return 0;
}
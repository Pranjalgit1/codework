#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int *data;  // Array to store elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int size;       // Current size of the queue
} Queue;

// Function prototypes
Queue* initQueue(int capacity){
    Queue *q = malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int)*capacity);
    q->front = -1;
    q->rear = -1;
    q->size = capacity; //N
    return q;
}
int isFull(Queue* q){
    return ((q->rear+1)%q->size == q->front);
}
int isEmpty(Queue* q){
    return (q->front == -1 && q->rear ==-1);
}
void enqueue(Queue* q, int value){
    if(isFull(q)){
        printf("Overflow\n");
        return;
    }
    else if(isEmpty(q)){
        q->front = q->rear = 0;
    }else{
        q->rear = (q->rear+1) % q->size;
    }
    q->data[q->rear] = value;
    printf("Enqueued: %d\n",value);
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Underflow"); //empty queue
        return -1;
    }
    int value = q->data[q->front];
    if(q->front == q->rear){
        //last element
        q->front = q->rear = -1;
    }else{
        q->front = (q->front+1) % q->size;
    }
    printf("Dequeued : %d\n",value);
    return value;
}
int peek(Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }else{
        printf("Front element : %d\n",q->data[q->front]);
        return q->data[q->front];
    }
}
int displayQueue(Queue* q){
    int i = q->front;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }else{
    printf("Queue Elements :");
    while(i!=q->rear){
        printf("%d ",q->data[i]);
        i = (i+1) % q->size;
    }
    printf("%d ",q->data[q->rear]);  // Fixed: print data[rear], not rear itself
    printf("\n");
}   
}

void freequeue(Queue *q){
    if(q){
        free(q->data);
        free(q);
    }
}

void main(){
int choice,running = 1,capacity,value;
Queue *q = NULL;
while(running){
    printf("1. Make queue\n2. isfull?\n3. isempty?\n4. enqueue\n5. dequeue\n6. peek\n7. display queue\n8.exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter the capacity :");
        scanf("%d",&capacity);
        q = initQueue(capacity);
        break;
    case 2:
        if (!q) { printf("Create queue first!\n"); break; }
        isFull(q)?printf("queue is full"):printf("Not full yet");
        break;
    case 3:
        if (!q) { printf("Create queue first!\n"); break; }
        isEmpty(q)?printf("queue is empty"):printf("queue is not empty");
        break;
    case 4:
        if (!q) { printf("Create queue first!\n"); break; }
        printf("Enter value to enqueue :");
        scanf("%d",&value);
        enqueue(q,value);
        break;
    case 5:
        if (!q) { printf("Create queue first!\n"); break; }
        dequeue(q);
        break;
    case 6:
         if (!q) { printf("Create queue first!\n"); break; }
        peek(q);
        break;
    case 7:
        if (!q) { printf("Create queue first!\n"); break; }
        displayQueue(q);
        break;
    case 8:
        printf("\nexiting\n");
        freequeue(q);
        running = 0;    
        break;        
    default:
        printf("invalid input");
    }
}
printf("\nexit success!\n");

}




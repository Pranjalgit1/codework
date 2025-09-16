#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int *S1;
	int *S2;
	int top1;
	int top2;
	int count;
	int capacity;
} Queue;

static Queue* createQueue(int capacity) {
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL) return NULL;
	q->S1 = (int*)malloc(sizeof(int) * capacity);
	q->S2 = (int*)malloc(sizeof(int) * capacity);
	if (q->S1 == NULL || q->S2 == NULL) {
		free(q->S1);
		free(q->S2);
		free(q);
		return NULL;
	}
	q->top1 = -1;
	q->top2 = -1;
	q->count = 0;
	q->capacity = capacity;
	return q;
}

static void destroyQueue(Queue *q) {
	if (q == NULL) return;
	free(q->S1);
	free(q->S2);
	free(q);
}

static void Push1(Queue *q, int data){
	if(q->top1 == q->capacity - 1){
		return; // stack1 full
	}else{
		q->top1++;
		q->S1[q->top1] = data;
	}
}

static int Pop1(Queue *q){
	return q->S1[q->top1--];
}

static int Pop2(Queue *q){
	return q->S2[q->top2--];
}

static void Push2(Queue *q, int data){
	if(q->top2 == q->capacity - 1){
		return; // stack2 full
	}else{
		q->top2++;
		q->S2[q->top2] = data;
	}
}

static void enqueue(Queue *q, int x){
	Push1(q, x); // taking input in stack1
	q->count++; // total elements in stack1
}

static void dequeue(Queue *q){
	int i,a,b;
	if(q->top1 == -1 && q->top2 == -1){
		return; // queue is empty
	}else{
		for(i = 0; i < q->count; i++){
			a = Pop1(q); // pop all elements from stack 1
			Push2(q, a);   // push a to stack 2
		}
		b = Pop2(q);
		q->count--;
		printf(" dequeued elemet is : %d\n", b);
		for(i = 0; i < q->count; i++){
			a = Pop2(q); // pop from stack2
			Push1(q, a); // push that popped element back to stack 1
		}
	}
}

static void display(Queue *q){
	int i;
	for(i = 0; i <= q->top1; i++){
		printf("%d ", q->S1[i]);
	}
}

int main(){
	Queue *q = createQueue(5);
	if (q == NULL) return 1;
	enqueue(q, 5);
	enqueue(q, 2);
	enqueue(q, -1);
	dequeue(q);
	enqueue(q, 7);
	display(q);
	destroyQueue(q);
	return 0;
}
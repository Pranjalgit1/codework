#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *arr;
	int front;
	int rear;
	int capacity;
} Queue;

typedef struct {
	Queue q1;
	Queue q2;
} Stack;

static int queue_is_empty(Queue *q){
	return (q->front == -1 && q->rear == -1);
}

static void queue_enqueue(Queue *q, int x){
	if(q->rear == q->capacity - 1){
		return; // queue full
	}else{
		if(q->front == -1) q->front = 0;
		q->rear++;
		q->arr[q->rear] = x;
	}
}

static int queue_dequeue(Queue *q){
	int val = q->arr[q->front++];
	if(q->front > q->rear){
		q->front = -1; q->rear = -1;
	}
	return val;
}

static Stack* createStack(int capacity){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s == NULL) return NULL;
	s->q1.arr = (int*)malloc(sizeof(int) * capacity);
	s->q2.arr = (int*)malloc(sizeof(int) * capacity);
	if(s->q1.arr == NULL || s->q2.arr == NULL){
		free(s->q1.arr);
		free(s->q2.arr);
		free(s);
		return NULL;
	}
	s->q1.front = -1; s->q1.rear = -1; s->q1.capacity = capacity;
	s->q2.front = -1; s->q2.rear = -1; s->q2.capacity = capacity;
	return s;
}

static void destroyStack(Stack *s){
	if(s == NULL) return;
	free(s->q1.arr);
	free(s->q2.arr);
	free(s);
}

static void push(Stack *s, int x){
	int a;
	while(!queue_is_empty(&s->q1)){
		a = queue_dequeue(&s->q1);
		queue_enqueue(&s->q2, a);
	}
	queue_enqueue(&s->q1, x);
	while(!queue_is_empty(&s->q2)){
		a = queue_dequeue(&s->q2);
		queue_enqueue(&s->q1, a);
	}
}

static void pop(Stack *s){
	if(queue_is_empty(&s->q1)){
		return; // stack empty
	}else{
		int b = queue_dequeue(&s->q1);
		printf(" popped element is : %d\n", b);
	}
}

static void top(Stack *s){
	if(queue_is_empty(&s->q1)){
		return; // stack empty
	}else{
		printf(" top element is : %d\n", s->q1.arr[s->q1.front]);
	}
}

static void display(Stack *s){
	int i;
	for(i = s->q1.front; i != -1 && i <= s->q1.rear; i++){
		printf("%d ", s->q1.arr[i]);
	}
}

int main(){
	Stack *s = createStack(5);
	if(s == NULL) return 1;
	push(s, 10);
	push(s, 20);
	push(s, 30);
	top(s);
	pop(s);
	push(s, 40);
	display(s);
	destroyStack(s);
	return 0;
}


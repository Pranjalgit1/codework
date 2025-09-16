#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *data;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capacity){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int) * capacity);
    s->top = -1;
    s->capacity = capacity;
    return s;
}

int isEmpty(Stack *s){ return s->top == -1; }
int isFull(Stack *s){ return s->top == s->capacity - 1; }
void push(Stack *s, int x){ if(isFull(s)) return; s->top++; s->data[s->top] = x; }
int pop(Stack *s){ int v = s->data[s->top]; s->top--; return v; }
int peek(Stack *s){ return s->data[s->top]; }

void reverseStack(Stack *s){
    int n = s->top + 1;
    Stack *t = createStack(s->capacity);
    int i, k, x;
    for(i = 0; i < n; i++){
        x = pop(s);
        for(k = 0; k < n - i - 1; k++) push(t, pop(s));
        push(s, x);
        while(!isEmpty(t)) push(s, pop(t));
    }
    free(t->data); free(t);
}

void display(Stack *s){
    int i;
    for(i = s->top; i >= 0; i--) printf("%d ", s->data[i]);
}


void sortStack(Stack *s){
	Stack *t = createStack(s->capacity);
	int x;
	while(!isEmpty(s)){
		x = pop(s);
		while(!isEmpty(t) && peek(t) > x){
			push(s, pop(t));
		}
		push(t, x);
	}
	while(!isEmpty(t)) push(s, pop(t));
	free(t->data); free(t);
}

int middleElement(Stack *s){
	int n = s->top + 1;
	if(n == 0) return -1; // undefined; return sentinel
	int mid = n / 2;
	Stack *t = createStack(s->capacity);
	int i, x, middle = -1;
	for(i = 0; i < n; i++){
		x = pop(s);
		if(i == mid) middle = x;
		push(t, x);
	}
	while(!isEmpty(t)) push(s, pop(t));
	free(t->data); free(t);
	return middle;
}


int main(){
    Stack *s = createStack(10);
    push(s, 3);
    push(s, 1);
    push(s, 4);
    push(s, 2);
    push(s, 5);
    printf("Original: "); display(s); printf("\n");
    sortStack(s);
    printf("Sorted:   "); display(s); printf("\n");
    int mid = middleElement(s);
    printf("Middle element: %d\n", mid);
    free(s->data); free(s);
    return 0;
}
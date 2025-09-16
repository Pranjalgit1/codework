#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
    int *arr;
    int top;
    int capacity;
}Stack;

/* Create a stack with given capacity. Returns NULL on failure. */
Stack* createStack(int capacity){
    if(capacity<=0){
        return NULL;
    }
    Stack *s = malloc(sizeof(Stack));
    if(!s)return NULL;
    s->arr = (int*)malloc(sizeof(int)*capacity);
    if(!s->arr){
        free(s);
        return NULL;
    }
    s->top = -1;
    s->capacity = capacity;
    return s;
}

/* Free memory used by stack */
void destroyStack(Stack *s){
    if(!s) return;
    free(s->arr);
    free(s);
}

/* Check if stack is empty */
bool isEmpty(Stack *s){
    return s->top == -1; 
}

/* Check if stack is full */
bool isFull(Stack *s){
    return (s->top == s->capacity-1);
}

void push(Stack *s,int value){
    if(!s) return;
    if(isFull(s)){
        int newcap = 2*s->capacity;
        int *newarr = realloc(s->arr,sizeof(int)*newcap);
        if(!newarr) return;
        s->arr = newarr;
        s->capacity = newcap;
    }
    s->arr[++(s->top)] = value;
}

void pop(Stack *s){
    if(!s) return;
    if(isEmpty(s))return;
    printf("popped stuff : %d",s->arr[s->top]);
    s->arr[(s->top)--];
}

void peek(Stack *s){
    if(isEmpty(s)) return;
    printf("%d",s->arr[s->top]);
}

int size(Stack *s){
    if(!s) return 0;
    return s->top = s->top--;
}

void printStack(Stack *s) {
    if (!s) return;
    printf("Stack (size=%d, capacity=%d): ", size(s), s->capacity);
    if (isEmpty(s)) {
        printf("<empty>\n");
        return;
    }
    for (int i = 0; i <= s->top; ++i) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack *s = createStack(4);
    if (!s) {
        fprintf(stderr, "Failed to create stack\n");
        return 1;
    }

    printf("Pushing 10,20,30,40,50 (will auto-resize)\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50); // triggers resize

    printStack(s);

    int topVal;
   peek(s);
     

    printf("Popping elements:\n");
    while (!isEmpty(s)) {
        pop(s);
    }
       

    printStack(s);

    destroyStack(s);
    return 0;
}
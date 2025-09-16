#include<stdio.h>

struct Node{
    int data;
    struct Node* link; //link is same as next
};
void Push(int x,struct Node **top){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = *top; //top was NULL initially
    *top = temp; 
}
void Pop(struct Node** top){
    struct Node* temp = *top;
    if(*top==NULL){
        return;
    }
    *top=(*top)->link;
    free(temp);
}
void Peek(struct Node *top){
    if(top == NULL) return 0; //stack is empty
    printf("%d",top->data);
}
int isempty(struct Node *top){
    return top == NULL;
}
int isfull(struct Node *top){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        return 1; // stack full cannot allocate anymore
    }
    free(temp);
    return 0; //not full
}
int main(){
struct Node* top = NULL; //same as head
Push(1,&top);
Pop(&top);
Peek(top);
if (isEmpty(top)) {
    printf("Stack is empty\n");
}

if (isFull()) {
    printf("Stack is full\n");
} else {
    printf("Stack is not full\n");
}
}
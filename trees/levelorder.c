#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue{
    struct Node* arr[1000];
    int front;
    int rear;
};

bool isEmpty(struct Queue *q){
    return q->front == -1;
}

void push(struct Queue* q, struct Node* node){
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    }else{
        q->rear++;
    }
    q->arr[q->rear] = node;
}

struct Node* pop(struct Queue* q){
    if(isEmpty(q)) return NULL;
    struct Node* node = q->arr[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }else{
        q->front++;
    }
    return node;
}

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildBT(){
    int val;
    printf(">> ");
    scanf("%d", &val);
    
    if(val == -1){
        return NULL;
    }
    
    struct Node* newNode = createNode(val);
    
    printf("   Left child of %d: ", val);
    newNode->left = buildBT();
    
    printf("   Right child of %d: ", val);
    newNode->right = buildBT();
    
    return newNode;
}

void levelOrder(struct Node* root, struct Queue* q){
    if(root == NULL){
        printf("Tree is empty!\n");
        return;
    }
    
    push(q, root);
    
    printf("Level Order: ");
    while(!isEmpty(q)){
        struct Node* curr = pop(q);
        printf("%d ", curr->data);
        
        if(curr->left != NULL){
            push(q, curr->left);
        }
        if(curr->right != NULL){
            push(q, curr->right);
        }
    }
    printf("\n");
}

void preorder(struct Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    
    printf("========================================\n");
    printf("    BINARY TREE - LEVEL ORDER TRAVERSAL\n");
    printf("========================================\n\n");
    
    printf("Enter tree nodes (-1 for NULL):\n");
    printf("Root: ");
    struct Node* root = buildBT();
    
    printf("\n========================================\n");
    printf("           TREE TRAVERSALS\n");
    printf("========================================\n");
    
    printf("Preorder:    ");
    preorder(root);
    printf("\n");
    
    levelOrder(root, &q);
    
    printf("========================================\n");
    
    return 0;
}
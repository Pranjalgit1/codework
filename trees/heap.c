#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* createNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    return newnode;
}






int main(){
    struct Node* root = NULL;





    return 0;
}
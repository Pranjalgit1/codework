#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
        struct Node* Newnode =  (struct Node*)malloc(sizeof(struct Node));
        Newnode->data = val;
        Newnode-> left = NULL;
        Newnode->right = NULL;
        return Newnode;
}

struct Node* buildTree(){
    int val;
    scanf("%d",&val);
    if(val == -1){
        return NULL;
    }
    struct Node* newNode = createNode(val);
    newNode-> left = buildTree();
    newNode-> right = buildTree();

    return newNode;
}

void preorder(struct Node* root){
    if(root == NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct Node* root = buildTree();
    printf("Tree : ");
    preorder(root);
    printf("✓ Tree built successfully!\n");

    return 0;
}

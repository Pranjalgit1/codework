#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createBST(struct Node **root,int val){
    if(*root == NULL){
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
        *root = newnode;
        return newnode;
    }
    if(val < (*root)->data){
        createBST(&((*root)->left),val);
    }
    else if(val > (*root)->data) {
        createBST(&((*root)->right),val);
    }
    else{
        printf("Negative values cant be added\n");
    }
    return *root;
}

void printrange(struct Node* root,int k1,int k2){
    if(root == NULL)return;

    if(k1 <= root->data && root->data <= k2){

        printrange(root->left,k1,k2);
        printf("%d " ,root->data);
        printrange(root->right,k1,k2);

    }else if(root->data < k1){
        printrange(root->right,k1,k2);
    }else if(root->data > k2){
        printrange(root->left,k1,k2);
    }

    }


void inorder(struct Node* root){
    if(root == NULL) return;
    printf("%d ",root->data);
    inorder(root->left);
    inorder(root->right);
}


int main(){
    struct Node* root = NULL;
    int flag = 1;
    int data;
    int choice;
    int key;
    do{
        printf("BST construction initialized\n");
        printf("Enter data of Node : ");
        scanf("%d",&data);
        createBST(&root,data);
        printf("do you want to continue?(0/1) ");
        scanf("%d",&flag);
    }while(flag);

    // if(searchinBST(root,2)){
    //     printf("Found\n");
    // }else{
    //     printf("not found\n");
    // }
    inorder(root);
    printf("\n");
    printrange(root,3,7);

    return 0;

}
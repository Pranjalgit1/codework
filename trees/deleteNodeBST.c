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

bool searchinBST(struct Node* root,int key){
    if(root == NULL) return false;
    if(root->data == key) return true;

    if(key < root->data){
        searchinBST(root->left,key);     
    }else{
       searchinBST(root->right,key);
    }
}

struct Node* FindinorderS(struct Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}


struct Node* delete(struct Node* root,int val){
    //searching and recursion call 
    if(root->data < val){
        root->right = delete(root->right,val);
    }else if(root->data > val){
        root->left = delete(root->left,val);
    }else{ //root pointing to val now
        //case 1 : no child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        //case 2 : one child
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }
        //case 3 : both child find inorder successor
        struct Node* IS = FindinorderS(root->right);
        root->data = IS->data;
        delete(root->right,IS->data);   
    }
    return root;    
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
    root = delete(root,3);
    inorder(root);


    return 0;

}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
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

// void printarray(int path[],int pathlen){
//     for(int i=0;i<pathlen;i++){
//         printf("%d->",path[i]);

//     }
//     printf("NULL");
//     printf("\n");

// }

// void root2leaf(struct Node* root,int path[],int pathlen){
//     if(root == NULL)return;
//     path[pathlen++] = root->data;

//     if(root->left == NULL && root->right == NULL){
//         printarray(path,pathlen);
//     }
//     root2leaf(root->left,path,pathlen);
//     root2leaf(root->right,path,pathlen);


// }

bool isvalidBST(struct Node* root,int min,int max){
    if(root == NULL)return true;

    //node with [min,max]
    if(root->data <= min || root->data >= max)  return false;
      
    return (isvalidBST(root->left,min,root->data) &&
            isvalidBST(root->right,root->data,max));
   
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
    // inorder(root);
    // printf("\n");
    // root = delete(root,3);
    // inorder(root);
    // int path[100];  // assume
    // root2leaf(root, path, 0);

    if(isvalidBST(root,INT_MIN,INT_MAX)){
        
         printf("✓ Valid BST!\n");
    }else{
        printf("✗ Not a Valid BST!\n");
    }

    return 0;

}
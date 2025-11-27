#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(struct Node** root,int data){
   if(*root == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        *root = newNode;
        return newNode;    
   }
   else if(data < (*root)->data){
    create(&((*root)->left),data);
   }
   else if (data > (*root)->data){
    create(&((*root)->right),data);
   }
   else{
        printf("Duplicate value %d not allowed\n", data);
    }
}

void inorderTraversal(struct Node* root){
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
void preorderTraversal(struct Node* root){
    if(root==NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct Node* root){
    if(root==NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int totalnodes(struct Node* root){
    if(root==NULL) return 0;
    return 1 + totalnodes(root->left) + totalnodes(root->right);
}

int Leafnodes(struct Node* root){
    if(root == NULL) return 0;
    if(root->left ==NULL && root->right==NULL)return 1;
    else{
        Leafnodes(root->left);
        Leafnodes(root->right);
    }
}

int  childnodes(struct Node* root){
    if(root==NULL)return 0;
    if(root->left!=NULL && root->right!=NULL )return 1;
    else{
        childnodes(root->left);
        childnodes(root->right);
    }
}
void maxval(struct Node* root){

}
void minval(struct Node* root){

}

int main(){
    struct Node* root = NULL;
    int num,opt = 1;
    int choice;
       do{
                printf("Enter data to insert:\n");
                scanf("%d",&num);
                create(&root,num);
                printf("Press 0 to stop or 1 to continue\n");
                scanf("%d",&opt);
               }while(opt);
    
    printf("1. Inorder Traversal\n");
    printf("2. Preorder Traversal\n");
    printf("3. Postorder Traversal\n");
    printf("4. Total Nodes");
    printf("5.  Find Leaf nodes");
    printf("6. Find child nodes");
    printf("7. Find max in BST");
    printf("8.Find min in BSt");
    scanf("%d",&choice);           
    switch(choice){
        case 1:
               inorderTraversal(root);
               break;
        case 2: preorderTraversal(root);
                break;
        case 3: postorderTraversal(root);
                break;
        case 4: printf("%d",totalnodes(root));
                break;
        case 5: printf("%d",Leafnodes(root));
                break;
        case 6: printf("%d",childnodes(root));
                break;
        case 7: maxval(root);
                break;
        case 8: minval(root);
                break;                                
        default:
            printf("Invalid choice\n");
            break;
    }
   
    return 0;
}
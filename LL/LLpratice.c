#include <stdio.h>
//implementng a LL 
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;  
struct node* newnode;
struct node* temp;
void createnode(){
    newnode = (struct node*)malloc(sizeof(struct node)); //contains address of new node
    printf("Enter data :");
    scanf("%d",&newnode->data); 
    newnode->next=0;
    if(head == 0){
        head = temp = newnode;
    }else{
        temp->next = newnode;
        temp = newnode;
    }
}

int main(){
    int count=0;
    int choice=1;
    while(choice){
        createnode();    
        printf("do you want to continue ?(0/1)");
        scanf("%d",&choice);
}
    temp = head;
    while(temp!=0){
        printf("%d->",temp->data);
        temp = temp->next;
        count++;
    }
    printf("->NULL\n");
    printf("total nodes = %d\n",count);
    getch();  
}


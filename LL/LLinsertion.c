#include<stdio.h>
struct node{
    int data;
    struct node* next;
};
struct node *head=0,*newnode,*temp;

void insertatstart(){

}
void createnode(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(head == 0){
        head = newnode;
        temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
}
void display(){
    temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main(){
 
    int input=1;
    while(input){
    createnode();
    printf("do you want to continue(0/1)");
    scanf("%d",&input);
    }
    int choice;
    do
    {
        printf("1.insert at start\n2.insert at end\n3.insert at position\n4.delete at start\n5.delete at end\n6.delete at position\n7.display\n8.exit");
        scanf("%d",&choice);
    } while (choice);
    
    display();
    return 0;
}


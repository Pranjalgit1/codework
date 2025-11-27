#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//------------------MIN Heap-----------------

struct Node{
    int value;
    int priority;
};

struct MinHeap{
    struct Node* arr[1000];
    int size;
};

struct Node* newnode(int value,int priority){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->value = value;
    n->priority = priority;
    return n;
};

void swap(struct Node** a, struct Node** b){
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap *h,int i){
    int small = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < h->size &&  h->arr[left]->priority < h->arr[small]->priority){
        small = left;
    }
    if(right < h->size && h->arr[right]->priority < h->arr[small]->priority){
        small = right;
    }
    if(small!=i){
        swap(&h->arr[small],&h->arr[i]);
        heapify(h,small);
    }
}

void push(struct MinHeap* h,int value,int priority){
    h->arr[h->size] = newnode(value,priority);
    int i = h->size++;

    while(i>0 && h->arr[i]->priority < h->arr[(i-1)/2]->priority){
        swap( &h->arr[i] , &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
     printf("✓ Inserted: value=%d, priority=%d\n", value, priority);
}

struct Node* pop(struct MinHeap *h){
    if(h->size ==0){
         printf("❌ Priority Queue is empty!\n");
        return NULL;
    }
    struct Node* root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapify(h,0); //heap obj and root node
    return root;
    
}

struct Node* peek(struct MinHeap *h){
    return h->arr[0];
}

bool* isEmpty(struct MinHeap*h){
    return h->size == 0;
}

void display(struct MinHeap *h){
     if(h->size == 0){
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("\nPriority Queue : \n");
    printf("index | value | Priority\n");
    for(int i=0;i<h->size;i++){
        printf("%d  | %d  | %d  \n",i,h->arr[i]->value,h->arr[i]->priority);
    }
    printf("\n");

}


int main(){
   struct MinHeap h;
   h.size = 0;

   int choice, value, priority;
     while(1){
        printf("\n--- MENU ---\n");
        printf("1. Insert (Push)\n");
        printf("2. Extract Min (Pop)\n");
        printf("3. Peek Min\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
               case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority (lower = higher priority): ");
                scanf("%d", &priority);
                push(&h, value, priority);
                break;
                
            case 2:
                    {
                    struct Node* min = pop(&h);
                    if(min != NULL){
                        printf("✓ Extracted: value=%d, priority=%d\n", min->value, min->priority);
                        free(min);
                    }
                    }
                break;
                
            case 3:
                {
                    struct Node* min = peek(&h);
                    if(min != NULL){
                        printf("Min element: value=%d, priority=%d\n", min->value, min->priority);
                        free(min);
                    }
                }
                break;
            case 4:
                display(&h);
                break;
                
            case 5:
                if(isEmpty(&h)){
                    printf("Priority Queue is empty ✓\n");
                }else{
                    printf("Priority Queue has %d elements\n", h.size);
                }
                break;
                
            case 6:
                printf("\nExiting...\n");
                
                // Free remaining nodes
                while(h.size > 0){
                    struct Node* n = pop(&h);
                    free(n);
                }
                
                return 0;
                
            default:
                printf("Invalid choice!\n");    
                
        }
}
return 0;
}
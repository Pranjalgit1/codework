#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// ==================== GRAPH (Updated addEdge) ====================
struct Edge{
    int dest;
    int wt;
    struct Edge* next;
};

struct Edge* createEdge(int dest, int weight){
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->wt = weight;
    newEdge->next = NULL;
    return newEdge;
}

// Single function - handles both directed and undirected
void addEdge(struct Edge* adjList[], int src, int dest, int wt){
    // Add src -> dest
    struct Edge* newEdge1 = createEdge(dest, wt);
    newEdge1->next = adjList[src];
    adjList[src] = newEdge1;
    
    // If undirected, add dest -> src   
        struct Edge* newEdge2 = createEdge(src, wt);
        newEdge2->next = adjList[dest];
        adjList[dest] = newEdge2;
    
}

void printGraph(struct Edge* adjList[], int V){
    printf("\nGraph representation (Adjacency List):\n");
    for(int i = 0; i < V; i++){
        printf("Vertex %d:", i);
        struct Edge* temp = adjList[i];
        while(temp != NULL){
            printf(" -> %d(weight = %d)", temp->dest, temp->wt);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ==================== MIN-HEAP ====================
struct Node{
    int v;
    int wt;
    int parent;
};

struct MinHeap{
    struct Node* arr[1000];
    int size;
};

struct Node* newNode(int v, int wt,int parent){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v;
    n->wt = wt;
    n->parent = parent;
    return n;
}

void swap(struct Node** a, struct Node** b){
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* h, int i){
    int smallest = i;   
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < h->size && h->arr[left]->wt < h->arr[smallest]->wt)
        smallest = left;
    if(right < h->size && h->arr[right]->wt < h->arr[smallest]->wt)
        smallest = right;
    
    if(smallest != i){
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

void push(struct MinHeap* h, int v, int wt,int parent){
    h->arr[h->size] = newNode(v, wt,parent);
    int i = h->size++;
    
    while(i > 0 && h->arr[i]->wt < h->arr[(i-1)/2]->wt){
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

struct Node* pop(struct MinHeap* h){
    struct Node* root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapify(h, 0);
    return root;
}

// ==================== PRIM'S ALGORITHM ====================
void primsMST(struct Edge* adjList[], int V){
    bool vis[V];
    for(int i = 0; i < V; i++) 
        vis[i] = false;
    
    struct MinHeap h;
    h.size = 0;

    
    int total = 0;
    
    push(&h, 0, 0,-1);   
    
    printf("\n========== PRIM'S MST ==========\n");
    printf("MST Edges:\n");
    
    while(h.size > 0){
        struct Node* curr = pop(&h);
       

        vis[curr->v] = true;
        total += curr->wt;

        printf("Edge: %d - %d, Weight: %d\n", curr->parent,curr->v,curr->wt);
        
        struct Edge* temp = adjList[curr->v];
        while(temp != NULL){
            if(!vis[temp->dest])
                push(&h, temp->dest, temp->wt,curr->v);
            temp = temp->next;
        }
        
        free(curr);
    }
    
    printf("\nTotal MST Weight: %d\n", total);  
    printf("================================\n");
}

// ==================== MAIN ====================
int main(){
    int V, src, dest, weight;
    char choice, graphType;
   
    
    printf("How many vertices are in the graph? ");
    scanf("%d", &V);

    struct Edge* adjList[V];
    for(int i = 0; i < V; i++){
        adjList[i] = NULL;
    }
    
    do {
        printf("\nEnter the source vertex: ");
        scanf("%d", &src);
        printf("Enter the destination vertex: ");
        scanf("%d", &dest);
        printf("Enter the weight of this edge: ");
        scanf("%d", &weight);
        
        addEdge(adjList, src, dest, weight); 
        printf("Added undirected edge: %d <--> %d (weight = %d)\n", src, dest, weight);
        printf("Do you want to add another Edge? (y/n): ");
        scanf(" %c", &choice);
        
    } while(choice == 'y' || choice == 'Y');

    printGraph(adjList, V);
    
    primsMST(adjList, V);
    

    return 0;
}
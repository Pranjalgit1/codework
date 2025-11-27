#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define INF INT_MAX


struct Edge{
    int dest;
    int wt;
    struct Edge* next;
};

struct Edge* createEdge(int dest, int wt){
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->wt = wt;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(struct Edge* adjList[], int src, int dest, int wt){
    struct Edge* newEdge = createEdge(dest, wt);
    newEdge->next = adjList[src];
    adjList[src] = newEdge;
}

//--------------------MINHEAP-----------------//
struct Node{
    int v;
    int wt;

};

struct MinHeap{
    struct Node* arr[1000];
    int size;
};

struct Node* newnode(int v,int wt){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->v = v;
    newnode->wt = wt;
   
    return newnode;
};

void swap(struct Node** a, struct Node** b){
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(struct MinHeap *h,int i){
    int small = i;
    int left = 2*i+1;
    int right = 2*i + 2;

    if(left < h->size && h->arr[left]->wt < h->arr[small]->wt)small = left;
    if(right < h->size && h->arr[right]->wt <h->arr[small]->wt)small = right;

    if(small != i){
        swap(&h->arr[small],&h->arr[i]);
        Heapify(h,small);
    }
}

void push(struct MinHeap* h,int v,int wt){
    h->arr[h->size] = newnode(v,wt);
    int i = h->size++;

    while(i > 0 && h->arr[i]->wt < h->arr[(i-1)/2]->wt){
        swap(&h->arr[i] , &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

struct Node* pop(struct MinHeap* h){
    struct Node* root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    Heapify(h,0);
    return root;
}

bool isEmpty(struct MinHeap* h){
    return h->size == 0;
}

//--------------------DIJKSTRA'S ALGORITHM---------------------//
void dijkstra(struct Edge* adjlist[],int V,int src){
    int dist[V];
    bool visited[V];

    for(int i = 0; i < V; i++){
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    struct MinHeap h;
    h.size = 0;
    push(&h,src,0);

    while(!isEmpty(&h)){
        struct Node* curr = pop(&h); //vertex with minimum distance
        int u = curr->v; //neighbouring vertex
        free(curr);

        visited[u] = true;
        struct Edge* temp = adjlist[u];
        while(temp != NULL){
            int v = temp->dest;
            int weight = temp->wt;

            if(!visited[v]  && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                push(&h,v,dist[v]);
            }
            temp = temp->next;
        }

    }
    printf("\nShortest distances from vertex %d:\n", src);
    printf("Vertex\tDistance\n");
    for(int i=0;i<V;i++){
        if(dist[i] == INF){
            printf("%d\tINF\n", i);
        }else{
            printf("%d\t%d\n", i, dist[i]);
        }
    }

}



int main(){
    int V, src, dest, weight;
    char choice;
     printf("========== DIJKSTRA'S ALGORITHM (HEAP) ==========\n\n");
    printf("How many vertices are in the graph? ");
    scanf("%d", &V);
    
    struct Edge* adjList[V];
    for(int i = 0; i < V; i++){
        adjList[i] = NULL;
    }
    
    do{
        printf("\nEnter the source vertex: ");
        scanf("%d", &src);
        printf("Enter the destination vertex: ");
        scanf("%d", &dest);
        printf("Enter the weight of this edge: ");
        scanf("%d", &weight);
        
       
        addEdge(adjList, src, dest, weight);
        
        printf("Do you want to add another Edge? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
    
    int startVertex;
    printf("\nEnter source vertex for Dijkstra: ");
    scanf("%d", &startVertex);
    
    dijkstra(adjList,V,startVertex);

      for(int i = 0; i < V; i++){
        struct Edge* edge = adjList[i];
        while(edge != NULL){
            struct Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    
    return 0;
}

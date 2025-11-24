#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Edge{
    int dest;
    int wt;
    struct Edge* next;
};


struct Edge* createEdge(int dest,int weight){
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->wt = weight;
    newEdge->next = NULL;
    return newEdge;
}
void addEdge(struct Edge* adjList[],int src,int dest,int wt){
    struct Edge* newEdge = createEdge(dest,wt);
    newEdge->next = adjList[src];
    adjList[src] = newEdge;

}
void printBFS(struct Edge* adjList[],int V,int startVertex){
    int queue[100];
    int front = 0;
    int rear = 0;

    // Boolean array for visited
    bool visited[V];
    for(int i =0;i<V;i++){
        visited[i] = false;
    }

    
    queue[rear++] = startVertex; // Add start vertex to queue
    printf("BFS Traversal: ");

    // While queue is not empty
    while(front < rear){
        int curr = queue[front++]; // Remove from queue

        if(!visited[curr]){
            
            visited[curr] = true;
            printf("%d ",curr);
            //add neighbours
            struct Edge* temp = adjList[curr];
            while (temp!=NULL)
            {
                queue[rear++] = temp->dest;
                temp = temp->next;
            }
        }
    }
    printf("\n");
}

int main(){
    int V,src,dest,weight = 1;
    char choice;
    printf("How many vertices are in the graph? ");
    scanf("%d", &V);
    struct Edge* adjList[V];

    for(int i = 0;i<V;i++){
        adjList[i] = NULL;
    }

    do{
        printf("\nEnter the source vertex: ");
        scanf("%d", &src);
        printf("Enter the destination vertex: ");
        scanf("%d", &dest);
        addEdge(adjList,src,dest,weight);
        printf("Do you want to add another Edge ?");
        scanf(" %c",&choice);
    }while(choice == 'y' || choice == 'Y');

    int startVertex;
    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &startVertex);
    printBFS(adjList,V,startVertex);


}

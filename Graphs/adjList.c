#include<stdio.h>
#include<stdlib.h>

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

void printGraph(struct Edge* adjList[],int V){
     printf("\nGraph representation (Adjacency List):\n");
     for(int i = 0;i<V;i++){
        printf("Vertex %d:",i);
        struct Edge* temp = adjList[i];
        while(temp!=NULL){
            printf("-> %d(weight = %d)",temp->dest,temp->wt);
            temp = temp->next;
        }
        printf("\n");
     }
}

int main(){
    int V,src,dest,weight;
    char choice;
    printf("How many vertices are in the graph? ");
    scanf("%d", &V);

    struct Edge* adjList[V];

    for(int i = 0;i<V;i++){
        adjList[i] = NULL;
    }

    do {
        printf("\nEnter the source vertex: ");
        scanf("%d", &src);
        printf("Enter the destination vertex: ");
        scanf("%d", &dest);
        printf("Enter the weight of this edge: ");
        scanf("%d", &weight);
        addEdge(adjList,src,dest,weight);
        printf("Do you want to add another Edge ?");
        scanf(" %c",&choice);
    }while(choice == 'y' || choice == 'Y');

    printGraph(adjList,V);

}
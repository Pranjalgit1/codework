#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Edge{
    int dest;
    int wt;
    struct Edge* next;
};

struct Edge* createEdge(int dest,int wt){
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->wt = wt;
    newEdge->next = NULL;
    return newEdge;
}
void addEdge(struct Edge* adjList[],int src,int dest,int wt){
    struct Edge* newEdge = createEdge(dest,wt);
    newEdge->next = adjList[src];
    adjList[src] = newEdge;

}
void DFS(struct Edge* adjList[],int current,bool visited[]){
    
    //print current vertex
    printf("%d ",current);
    
    //mark as visited
    visited[current] = true;
    
    //visit all neighbours
    struct Edge* temp = adjList[current];
    while(temp!=NULL){
        if(!visited[temp->dest]){
            DFS(adjList,temp->dest,visited);
        }
        temp = temp->next;
    }
}


int main(){
    int V,src,dest,weight=1;
    char choice;
    printf("How many vertices are in the graph? ");
    scanf("%d", &V);

    struct Edge* adjList[V];

    for(int i =0; i<V;i++){
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
    }while(choice == 'y' || choice =='Y');

    printf("\n");
    int startVertex;
    printf("Enter start vertex for DFS : \n");
    scanf("%d",&startVertex);

    //initialize visited array
    bool visited[V];
    for(int i = 0;i<V;i++){
        visited[i] = false;
    }

    printf("DFS Traversal: ");
    DFS(adjList, startVertex, visited);
    printf("\n");

    return 0;
}
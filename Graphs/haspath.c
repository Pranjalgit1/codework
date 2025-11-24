#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Edge{
    int dest;
    int wt;
    struct Edge *next;
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

bool Haspath(struct Edge* adjList[],int src,int dest,bool visited[]){
    if(src == dest)return true;

    visited[src] = true;
    struct Edge* temp = adjList[src];
    while(temp != NULL){
        if(!visited[temp->dest] && Haspath(adjList,temp->dest,dest,visited)){
            return true;
        }
        temp = temp->next;
    }
    return false;

}

int main(){
     int V,src,dest,weight = 1;;
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
        addEdge(adjList,src,dest,weight);
        printf("Do you want to add another Edge ?");
        scanf(" %c",&choice);
    }while(choice == 'y' || choice == 'Y');

    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    int newsrc,newdest;
    printf("\nEnter the source vertex for path: ");
        scanf("%d", &newsrc);
        printf("Enter the destination vertex for path: ");
        scanf("%d", &newdest);

    Haspath(adjList,newsrc,newdest,visited) ? printf("path exists\n") : printf("path doesnt exists\n");

    return 0;
}
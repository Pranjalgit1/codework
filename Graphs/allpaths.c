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

void printPath(int path[], int pathLen){
    for(int i = 0; i < pathLen; i++){
        printf("%d", path[i]);
    }
    printf("\n");
}

void allpaths(struct Edge* adjList[],int src,int dest,int path[],int pathlen){
    path[pathlen++] = src;

    if(src == dest){
        printPath(path,pathlen);
        return;
    }

    struct Edge *temp = adjList[src];
    while(temp != NULL){
        allpaths(adjList,temp->dest,dest,path,pathlen);
        temp = temp->next;
    }
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
    
    int start;
    int final;
    printf("\nEnter start of path : ");
    scanf("%d",&start);
    printf("\nEnter end of path : ");
    scanf("%d",&final);

    printf("\nAll paths from %d to %d:\n", start, final);
    int path[V];
    allpaths(adjList,start,final,path,0);

    return 0;
}
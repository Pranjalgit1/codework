#include<stdio.h>
#include<stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adjList[], int src, int dest){
    // Add edge from src to dest only
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

int main(){
    int vertices = 5;
    struct Node* adjList[vertices];
    
    // Initialize all lists to NULL
    for(int i = 0; i < vertices; i++){
        adjList[i] = NULL;
    }
    
    // Add edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    
    return 0;
}
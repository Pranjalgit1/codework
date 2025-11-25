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

// Find unvisited vertex with minimum distance
int neighbouringVertex(int dist[], bool visited[], int V){
    int min = INF;
    int minIndex = -1;
    
    for(int i = 0; i < V; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's Algorithm
void dijkstra(struct Edge* adjList[], int V, int src){
    int dist[V];       // Distance array
    bool visited[V];   // Visited array
    
    // Step 1: Initialize all distances to infinity, src to 0
    for(int i = 0; i < V; i++){
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
    
    // Step 2 & 3: Process all vertices
    for(int count = 0; count < V; count++){
        // Get vertex with minimum distance
        int u = neighbouringVertex(dist, visited, V);
        
        if(u == -1) break;  // All remaining vertices are unreachable
        
        // Mark current vertex as visited
        visited[u] = true;
        
        // Update distances of neighbors
        struct Edge* temp = adjList[u];
        while(temp != NULL){
            int v = temp->dest;
            int weight = temp->wt;
            
            // Relaxation: if dist[u] + weight < dist[v]
            if(!visited[v]  && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
            
            temp = temp->next;
        }
    }
    
    // Print shortest distances
    printf("\nShortest distances from vertex %d:\n", src);
    printf("Vertex\tDistance\n");
    for(int i = 0; i < V; i++){
        if(dist[i] == INF){
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main(){
    int V, src, dest, weight;
    char choice;
    
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
        
        if(src >= 0 && src < V && dest >= 0 && dest < V){
            addEdge(adjList, src, dest, weight);
        } else {
            printf("Invalid vertices!\n");
        }
        
        printf("Do you want to add another Edge? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
    
    int startVertex;
    printf("\nEnter source vertex for Dijkstra: ");
    scanf("%d", &startVertex);
    
    dijkstra(adjList, V, startVertex);
    
    return 0;
}
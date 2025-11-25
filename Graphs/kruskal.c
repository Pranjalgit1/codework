#include<stdio.h>
#include<stdlib.h>


struct Edge{
    int src;
    int dest;
    int weight;
};

int find(int parent[],int x){
    if(parent[x] == x)
        return parent[x];
    return parent[x] = find(parent,parent[x]);
}

void Union(int parent[],int rank[],int x,int y){
    int parA = find(parent,x);
    int parB = find(parent,y);

    if(rank[parA] < rank[parB]){
        parent[parA] = parB;
    }else if(rank[parA] > rank[parB]){
        parent[parB] = parA;
    }else{
        parent[parA] = parB;
        rank[parB]++;
    }
}

int compare(const void *a,const void *b){
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

void kruskalMST(struct Edge *edges,int V){
    qsort(edges,V-1,sizeof(edges[0]),compare); //sort by weight 

    printf("\nSorted Edges:\n");
    for(int i = 0; i < V-1; i++){
        printf("%d - %d, weight: %d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }

    //init DSU
    int parent[V];
    int rank[V];
    for(int i=0; i<V;i++){
        parent[i] = i;
        rank[i] = 0;
    }
    //Making MST
    int mstedges = 0;
    int total = 0;

    for(int i=0;i<V-1;i++){
        int parA = find(parent, edges[i].src);
        int parB = find(parent, edges[i].dest);

        if(parA != parB){
            printf("Edge : %d - %d,weight = %d\n",edges[i].src,edges[i].dest,edges[i].weight);
            Union(parent,rank,edges[i].src,edges[i].dest);
            total+= edges[i].weight;
            mstedges++;
        }else{
            printf("Skipped: %d - %d (creates cycle)\n", edges[i].src, edges[i].dest);
        }
    }
    printf("total weight : %d",total);


}





int main(){
    int V;

    printf("Enter vertices : ");
    scanf("%d",&V);

    struct Edge edges[V];

    printf("\nEnter edges (source destination weight):\n");
    for(int i = 0;i< V-1;i++){
        printf("Edge %d: ",i+1);
        scanf("%d %d %d",&edges[i].src,&edges[i].dest,&edges[i].weight);
    }

    kruskalMST(edges,V);

    return 0;
}
// Kruskal's Minimum Spanning Tree using Union Find concept
#include <stdio.h>
#include <string.h>
#include <limits.h>

void kruskal(int totalVertex, int graph[][totalVertex]);
void printMatrix(int totalVertex, int graph[][totalVertex]);
int find(int vertexToFind, int *visitedVertex);
int Union(int vertex1, int vertex2, int visitedVertex[]);

int main(){
    int totalVertex=0, totalEdges=0, src=0, dest=0, weight=0;

    scanf("%d %d\n", &totalVertex, &totalEdges);
    int graph[totalVertex][totalVertex];
    memset(graph, 0, sizeof graph);

    while(scanf("%d %d %d\n", &src, &dest, &weight)!=EOF){
        graph[src+1][dest+1] = weight;
    }
    kruskal(totalVertex, graph);
    // printMatrix(totalVertex, graph);

    return 0;
}

void kruskal(int totalVertex, int graph[][totalVertex]){
    int count=1, i=1, j, minWeight=INT_MAX, u, v, vertex1, vertex2, minimumCost=0;
    int visitedVertex[totalVertex+1];
    while(i<=totalVertex){
        visitedVertex[i] = 0;
        i++;
    }
    printf("> Your MST:\n");
    while(count<totalVertex){
        for (i=1; i<=totalVertex; i++){
            for (j=1; i<=totalVertex; i++){
                if (graph[i][j] < minWeight){
                    minWeight = graph[i][j];
                    u = vertex1 = i;
                    v = vertex2 = j;
                }
            }
        }
        u = find(u, visitedVertex);
    	v = find(v, visitedVertex);
    	if (Union(u,v, visitedVertex)){
            printf("(%d, %d): %d ", vertex1, vertex2, minWeight);
            minimumCost += minWeight;
        }
        graph[vertex1][vertex2] = graph[vertex2][vertex1] = 800;
    }
    printf("\n>> MINIMUM COST: %d", minimumCost);
}

int find(int vertexToFind, int visitedVertex[]){
    while(visitedVertex[vertexToFind]){
        vertexToFind = visitedVertex[vertexToFind];
    }
    return vertexToFind;
}

int Union(int vertex1, int vertex2, int visitedVertex[]){
    if (vertex1!=vertex2){
        visitedVertex[vertex2] = vertex1;
        return 1;
    }
    return 0;
}

void printMatrix(int totalVertex, int graph[][totalVertex]){
    for (int i=0; i<totalVertex; i++){
        for (int j=0; j<totalVertex; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
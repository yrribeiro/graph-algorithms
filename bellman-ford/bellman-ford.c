#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTEX 20

typedef struct EDGE{
    int src, dest, weight;
}EDGE;

void bellmanFord(int totalVertex, int distance[], int root[], int numOfArchs, EDGE *arch, int src);
void printPath (int src, int dest, int root[]);

int main(){
    int totalVertex, i=0, j, src;
    EDGE arch[MAX_VERTEX];
    int numOfArchs=0;

    scanf("%d %d", &totalVertex, &src);
    int distance[totalVertex], root[totalVertex], graph[totalVertex][totalVertex];

    for (i=0; i<totalVertex; i++){
        distance[i] = SHRT_MAX;
        root[i] = -1;
        for (j=0; j<totalVertex; j++){
            scanf("%d", &graph[i][j]);
            if (graph[i][j]){
                arch[numOfArchs].src = i;
                arch[numOfArchs].dest = j;
                arch[numOfArchs].weight = graph[i][j];
                numOfArchs++;
            }
        }
    }
    distance[src] = 0;

    bellmanFord(totalVertex, distance, root, numOfArchs, arch, src);

    return 0;
}

void bellmanFord(int totalVertex, int distance[], int root[], int numOfArchs, EDGE *arch, int src){
    int i=1, j, end;
    while(i<totalVertex){
        for (j=0; j<numOfArchs; j++){
            if (distance[arch[j].dest] > distance[arch[j].src] + arch[j].weight){
                distance[arch[j].dest] = distance[arch[j].src] + arch[j].weight;
                root[arch[j].dest] = arch[j].src;
            }
        }
        i++;
    }
    scanf("%d", &end);
    printf(">> This is your path from %d to %d: \n", src, end);
    printPath(src, end, root);
    printf("\nPath cost > %d", distance[end]);
}

void printPath (int src, int dest, int root[]){
    if (src==dest){
        printf("%d ", src);
    }else if (root[dest]==-1){
        printf(">> there's no path to this vertex!");
    }else{
        printPath(src, root[dest], root);
        printf("%d ", dest);
    }
}
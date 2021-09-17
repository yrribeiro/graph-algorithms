#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct EDGE{
    int src, dest, weight;
}EDGE;

typedef struct EDGE_LIST{
    EDGE data[20];
}EDGE_LIST;

void bellmanFord(int totalVertex, int distance[], int root[], int numOfArchs, EDGE_LIST arch, int src);
void printPath (int src, int dest, int root[]);

int main(){
    int totalVertex, i=0, j, src;
    EDGE_LIST arch;
    int numOfArchs=0;

    scanf("%d %d", &totalVertex, &src);
    int distance[totalVertex], root[totalVertex], graph[totalVertex][totalVertex];

    for (i=0; i<totalVertex; i++){
        distance[i] = INT_MAX;
        root[i] = -1;
        for (j=0; j<totalVertex; j++){
            scanf("%d", &graph[i][j]);
            if (graph[i][j]){
                arch.data[numOfArchs].src = i;
                arch.data[numOfArchs].dest = j;
                arch.data[numOfArchs].weight = graph[i][j];
                numOfArchs++;
            }
        }
    }
    distance[src] = 0;

    bellmanFord(totalVertex, distance, root, numOfArchs, arch, src);

    return 0;
}

void bellmanFord(int totalVertex, int distance[], int root[], int numOfArchs, EDGE_LIST arch, int src){
    int i=1, j, start, end;
    while(i<totalVertex){
        for (j=0; j<numOfArchs; j++){
            if (distance[arch.data[j].dest] > distance[arch.data[j].src] + arch.data[j].weight){
                distance[arch.data[j].dest] = distance[arch.data[j].src] + arch.data[j].weight;
                root[arch.data[j].dest] = arch.data[j].src;
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct EDGE{
    int src, dest, weight;
}EDGE;

void sort (EDGE *arch, int totalEdges);
void kruskal (EDGE *arch, int totalVertex, int totalEdges);
int find(int vertexToFind, int parent[], int totalVertex);
void Union(int findU, int findV, int parent[], int rank[]);
void printTree (EDGE *aux, int count);

int main(){
    int i, totalVertex, totalEdges;

    scanf("%d %d", &totalVertex, &totalEdges);
    EDGE arch[totalEdges];

    for (i=0; i<totalEdges; i++){
        scanf("%d %d %d", &arch[i].src, &arch[i].dest, &arch[i].weight);
    }
    sort(arch, totalEdges);

    printf(":Edges of your MST:\n");
    kruskal(arch, totalVertex, totalEdges);

    return 0;
}

void sort (EDGE *arch, int totalEdges){ // bubble sort
    int i, j, pivot;
    EDGE aux;
    for (i=1; i<totalEdges; i++) {
        for (j=0; j<totalEdges-i; j++){
            if (arch[j].weight > arch[j+1].weight){
                aux = arch[j];
                arch[j] = arch[j+1];
                arch[j+1] = aux;
            }
        }
    }
}

void kruskal(EDGE *arch, int totalVertex, int totalEdges){
    int i, j=0, u, v, findU, findV, rank[totalVertex], parent[totalVertex];
    EDGE aux[totalVertex];
    for (i=1; i<totalVertex+1; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    for (i=0; i<totalEdges; i++){
        if (totalVertex-1 == j){
            break;
        }else{
            u = arch[i].src;
            v = arch[i].dest;
            findU = find(u, parent, totalVertex);
            findV = find(v, parent, totalVertex);
            if (findU!=findV){
                aux[j] = arch[i];
                Union(findU, findV, parent, rank);
                j++;
            }
        }
    }
    printTree(aux, totalVertex-1);
}

int find(int vertexToFind, int parent[], int totalVertex){
    int root=vertexToFind, node=vertexToFind, predecessor;
    while(root!=parent[vertexToFind]){
        root = parent[vertexToFind];
    }
    while(node!=node){
        predecessor = parent[node];
        parent[node] = root;
        node = predecessor;
    }
    return root;
}

void Union(int findU, int findV, int parent[], int rank[]){
    if (rank[findU] == rank[findV]){
        rank[findU]++;
        parent[findV] = findU;
    }else if (rank[findU]>rank[findV]){
        parent[findV] = findU;
    }else{
        parent[findU] = findV;
    }
}

void printTree (EDGE *aux, int count){
    int i=0, finalCost=0;
    while(i<count){
        printf("(%d:%d) ", aux[i].src, aux[i].dest);
        finalCost += aux[i].weight;
        i++;
    }
    printf("\n:Cost: %d", finalCost);
}
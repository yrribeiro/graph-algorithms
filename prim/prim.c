#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


void prim(int vertex, int graph[][vertex]);
void readData();
void createEdge(int vertex, int graph[vertex][vertex], int src, int dest, int weight);
void initializeMatrix(int vertex, int graph[vertex][vertex]);

int main(){
    readData();
    return 0;
}

void prim(int vertex, int graph[][vertex]){
    int distancia[vertex], precedente[vertex], visitas[vertex], vertice[vertex], x = 0, z = 0, dist_min = INT_MAX;
    for(int v = 0; v < vertex; v++){
        distancia[v] = INT_MAX/2;
        precedente[v] = -1;
        visitas[v] = 0;
        vertice[v] = v;
    }
    distancia[0] = 0;
    for(int xi = 0; xi < vertex; xi++){
        for(int k=0; k< vertex; k++){
            if(graph[x][k] != -1 && distancia[k] > graph[x][k] && visitas[k] == 0){
                precedente[k] = x;
                distancia[k] = graph[x][k];
            }
        }
        visitas[x] = 1;
        z = 0;
        dist_min = INT_MAX;
        while (z < vertex){
            if(dist_min > distancia[z] && visitas[z] == 0){
                dist_min = distancia[z];
                x = z;
            }
            z++;
        }

    }
    int y = 1, cont = 0, aux, aux2;
    z = 1;
    for(int i = 1; i < vertex; i++)
    {
        if(vertice[i] > precedente[i])
            {
                aux = vertice[i];
                vertice[i] = precedente[i];
                precedente[i] = aux;
            }
    }
    for(int j=5; j>=1; j--){
		for(int i=0; i<j; i++){

			if(vertice[i]>vertice[i+1]){
				    aux=precedente[i];
                    precedente[i]=precedente[i+1];
                    precedente[i+1]=aux;
                    aux2 = vertice[i];
                    vertice[i] = vertice[i+1];
                    vertice[i+1] = aux2;
            }
        }
    }
    int agm = 0;

    for(int i = 1; i < vertex; i++){
        printf("(%d, %d) ", vertice[i]+1, precedente[i]+1);
        agm += graph[vertice[i]][precedente[i]];
    }
    printf("\nCUSTO AGM: %d \n", agm);
}

void initializeMatrix(int vertex, int graph[vertex][vertex]){
    for(int x = 0; x< vertex; x++){
        for(int k=0; k< vertex; k++)
                graph[x][k] = -1;
    }

}

void readData(){
    FILE *data;
    int vertex=0, edges=0, src=0, dest=0, weight=0, i=0;
    data = fopen("prim_input.input", "r");
    if (data==NULL){
        fputs("Cannot open source file\n", stderr);
        exit(EXIT_FAILURE);
    }else{
        size_t maxLen = 6;
        char *line= malloc(6*sizeof(char));
        vertex = fgetc(data) - '0';
        // printf("%d\n", vertex);
        int graph[vertex][vertex];
        initializeMatrix(vertex, graph);
        while (getline(&line, &maxLen, data) > 0)
        {
            if (i != 0)
            {
                if (line[0])
                    src = line[0] - '0';
                if (line[2])
                    dest = line[2] - '0';
                if (line[4])
                    weight = line[4] - '0';
                else
                    weight = 1;
                createEdge(vertex, graph, src-1, dest-1, weight);

            }

            i++;
        }
        printf("\n");
        // para printar a matrix
        // for(int x = 0; x < vertex; x++){
        //     for(int k=0; k< vertex; k++)
        //         printf("%d ", graph[x][k]);
        //     printf("\n");
        // }
        prim(vertex, graph);
        if (line)
            free(line);
        fclose(data);
        exit(EXIT_SUCCESS);
    }
}

void createEdge(int vertex, int graph[vertex][vertex], int src, int dest, int weight){
    graph[src][dest] = weight;
    graph[dest][src] = weight;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void djikstra(int vertex, int graph[][vertex]);
void readData();
void createEdge(int vertex, int graph[vertex][vertex], int src, int dest, int weight);
void initializeMatrix(int vertex, int graph[vertex][vertex]);

int main(){
    readData();
    return 0;
}

void djikstra(int vertex, int graph[][vertex]){
    int distancia[vertex], precedente[vertex], visitas[vertex], x = 0, z = 0, dist_min = INT_MAX;
    int vertice_inicial = 0, vertice_final = 6, soma = 0;
    distancia[0] = 0;
    precedente[0] = -1;
    visitas[0] = 0;
    for(int v = 1; v < vertex; v++){
        distancia[v] = INT_MAX/2;
        precedente[v] = -1;
        visitas[v] = 0;
    }
    for(int xi = 0; xi < vertex; xi++){
        for(int k=0; k< vertex; k++){
            if(graph[x][k] != -1 && distancia[k] > graph[x][k]){
                distancia[k] = graph[x][k];
                precedente[k] = x;
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
    int  i = 0, y;
    while(i < vertice_final)
    {
        y = i;
        while (vertice_inicial != y)
        {
            soma += distancia[y];
            y = precedente[y];

        }
        printf("%d:%d ", i+1,  soma);
        soma = 0;
        i++;
    }
    printf("\n");
    for (int y = 0; y < vertex; y++){
        printf("para chegar em %d, distancia :%d, precendente %d\n", y+1,  distancia[y], precedente[y]+1);
    }
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
    data = fopen("sample.input", "r");

    if (data==NULL){
        fputs("Cannot open source file\n", stderr);
        exit(EXIT_FAILURE);
    }else{
        size_t maxLen = 6;
        char *line= malloc(6*sizeof(char));
        vertex = fgetc(data) - '0';

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

        // para printar a matriz
        // for(int x = 0; x < vertex; x++){
        //     for(int k=0; k< vertex; k++)
        //         printf("%d ", graph[x][k]);
        //     printf("\n");
        // }

        djikstra(vertex, graph);

        if (line)
            free(line);
        fclose(data);
        exit(EXIT_SUCCESS);
    }
}

void createEdge(int vertex, int graph[vertex][vertex], int src, int dest, int weight){
    graph[src][dest] = weight;
}

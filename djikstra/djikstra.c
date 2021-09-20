#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


void djikstra(int vertex, int graph[][vertex], int start);
void readData();
void createEdge(int vertex, int graph[vertex][vertex], int src, int dest, int weight);
void initializeMatrix(int vertex, int graph[vertex][vertex]);

int main(){
    readData();
    return 0;
}

void djikstra(int vertex, int graph[][vertex], int start){
    int distancia[vertex], precedente[vertex], visitas[vertex], x = start-1, z = 0, dist_min = INT_MAX;
    
    for(int v = 0; v < vertex; v++)
    {
        if(v == x)
        {
            distancia[x] = 0;
            precedente[x] = -1;
            visitas[x] = 0;
        }
        else
        {
            distancia[v] = INT_MAX/2;
            precedente[v] = -1;
            visitas[v] = 0;
        }
    }
    for(int xi = 0; xi < vertex; xi++)
    {

        for(int k=0; k < vertex; k++)
        {
            if(graph[x][k] != -1 && distancia[k] > graph[x][k] + distancia[x])
            {
                precedente[k] = x;
                distancia[k] = graph[x][k] + distancia[x];

            }
        }
        visitas[x] = 1;
        z = 0;
        dist_min = INT_MAX;
        while (z < vertex)
        {
            if(dist_min > distancia[z] && visitas[z] == 0)
            {
                dist_min = distancia[z];
                x = z;
            }
            z++;
        }

    }
    for (int y = 0; y < vertex; y++)
    {
        printf("%d -> %d = %d\n", start, y+1,  distancia[y]);
    }
    printf("\n");
}

void initializeMatrix(int vertex, int graph[vertex][vertex]){
    for(int x = 0; x< vertex; x++){
        for(int k=0; k< vertex; k++)
                graph[x][k] = -1;
    }

}

void readData(){
    FILE *data;
    int vertex=0, edges=0, src=0, dest=0, weight=0, i=0, start;
    // printf("Escolha o vertice que irá iniciar o caminho!\n");
    scanf("%d", &start);
    data = fopen("diska_input.input", "r");
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
        printf("\n");
        djikstra(vertex, graph, start);
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
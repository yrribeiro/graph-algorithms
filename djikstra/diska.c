#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void djikstra();
void readData();
void createEdge(int edges, int graph[][edges], int src, int dest, int weight);
void initializeMatrix(int vertex, int graph[][vertex]);

int main(){
    readData();
    return 0;
}

void djikstra(){
    // alguma coisa
}

void initializeMatrix(int vertex, int graph[][vertex]){
    for(int x = 0; x<=vertex+1; x++)
        {
            for(int k=0; k<vertex+1; k++){
                graph[x][k] = 0;
            }
        }
}


void readData(){
    FILE *data;
    int vertex=0, edges=0, src=0, dest=0, weight=0, i=0;

    data = fopen("diska_input.input", "r");
    if (data==NULL){
        fputs("Cannot open source file\n", stderr);
        exit(EXIT_FAILURE);
    }else{
        size_t maxLen = 6;
        char *line= malloc(6*sizeof(char));

        vertex = fgetc(data) - '0';
        int graph[vertex+1][vertex+1];
        initializeMatrix(vertex, graph);

        while (getline(&line, &maxLen, data) > 0)
        {
            if (i != 0)
            {
                if (line[0]){
                    src = line[0] - '0';
                }
                if (line[2]){
                    dest = line[2] - '0';
                }
                if (line[4]){
                    weight = line[4] - '0';
                }else{
                    weight = 1;
                }
                // printf("\n-> primeiro vertice: %d segundo vertice: %d peso: %d", src, dest, weight);
                createEdge(edges, graph, src, dest, weight);
                
            }
            i++;
        }


        if (line)
            free(line);
        fclose(data);
        exit(EXIT_SUCCESS);
    }
}

void createEdge(int vertex, int graph[][vertex], int src, int dest, int weight){
    printf("\n%d %d %d\n", src, dest, weight);
    graph[src][dest] = weight;
    for(int x = 0; x < vertex+1; x++)
    {
        for(int k=0; k<vertex+1; k++){
            printf("%d ", graph[x][k]);
        }            printf("\n");
    }
}
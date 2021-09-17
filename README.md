# graph-algorithms
this is a work in progress...

## How to run
Open your choosed algorithm folder > compile > execute.
Example, to run Ford:
```
cd bellman-ford
gcc bellman-ford.c -o ford
./ford < ford.input
```

### Bellman-Ford
The Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other vertices in a weighted digraph. In our project it's possible to select the source and the destination vertex. (built up using adjacency matrix concept)

#### Input format
```
[total of vertex] [start vertex]

    [ADJACENCY MATRIX - size totalVertex^2]

[end vertex]
```
Two integers, typed side by side, representing total number of vertex and the source vertex respectively (WATCH OUT! The first vertex must be 0, the second is 1 and so on...). In sequence, type your adjacency matrix where each weight will be in one line. Finally, the last number must be the destination vertex. You can see a sample in ford.input.

### Kruskal
Kruskal’s algorithm is a greedy algorithm in graph theory that finds a minimum spanning tree for a connected weighted graph. It finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

### Djikstra

### Prim
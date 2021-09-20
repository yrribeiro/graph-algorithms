# Prim
Prim's algorithm (also known as Jarník's algorithm) is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

## Input format
```
[total of vertex] [total of edges]
[source vertex] [destination vertex] [edge weight] - for each edge declared previously
```
Two integers, typed side by side, representing total number of vertex and total of edges respectively (WATCH OUT! The first vertex must be 1, the second is 2 and so on...). In sequence, a 3*[total of edges] matrix representing the graph's edges and it's weight. The output will give you the edges of a MST and it's path cost.

To test other input, save your changes at prim_input.input, the algorithm cannot read from another file.
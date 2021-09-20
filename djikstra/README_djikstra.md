# Djikstra
The algorithm exists in many variants. Dijkstra's original algorithm found the shortest path between two given nodes, but a more common variant (which this project is based) fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a shortest-path tree.

## Input format
```
[starting vertex] [total of vertex] [total of edges]
[source vertex] [destination vertex] [edge weight] - for each edge declared previously
```
Three integers, typed side by side, representing the starting vertex, total number of vertex and total of edges respectively (WATCH OUT! The first vertex must be 1, the second is 2 and so on...). In sequence, a 3*[total of edges] matrix representing the graph's edges and it's weight. The output will give you a list of path cost, how many does it takes to move from [starting vertex] to each other vertex in the graph.
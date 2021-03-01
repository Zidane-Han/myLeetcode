# Graph

## Implementation
- adjacent matrix
- adjacent list

## Problem: Topological sort

- Directional, no cycle
- Method: DFS

## Problem: Strongly connected components

- Directional, loop
- Complexity: O(V+E)

```html
1. call DFS(G) to compute finishing time u.f for each vertex u
2. compute G.transpose
3. call DFS(G.transpose), but in the main loop of DFS, consider the vertices in order of decreasing u.f (in step one)
4. output the vertices of each tree in the depth-first forest in step three
```

## Problem: Minimum spanning tree (MST)

- Description: connect `n` points with minimum weighted connections

- Non-directional, weighted

- Greedy method

- Complexity: O(E*lgV), O(E+VlgV) with Fibonacci heap

- Kruskal algorithm

  Search each edge in nondecreasing order by weight. If the edge can connect two different trees, add it into the forest.

```html
for each vertex v in G.V
	MAKESET(v);

sort the edges into nondecreasing order by weight w;

for each edge(u, v) in G.E
	if GET-ROOT(u) != GET-ROOT(v)
		UNION(u, v);

return;
```

- Prim algorithm

```html
construct graph with adj list;

init priority queue Q;

while Q is not empty
	u = EXTRACT-MIN(Q)
	for each v in adj[u]
		if v in Q and w(u,v) < v.cost
      v.key = w(u,v)
```

## Problem: Shortest path

**Bellman-Ford algorithm**

- Directional, (negative) weighted, single source
- Complexity: O(VE)

    ```html
    for i = 1 to G.V-1
        for each edge (u,v) in G.E
            RELAX(u,v,w)
    for each edge (u,v) in G.E
        if v.d > u.d + w(u,v)
            return FALSE
    return TRUE
    ```

- Directional, no cycle, (negative) weighted, single source
- Complexity: O(V+E)

    ```html
    for each u, taken in topologically sorted order
        for each v in G.adj[u]
            RELAX(u,v,w)
    ```

**Dijkstra’s algorithm**

- Directional, non-negative weighted, single source
- Complexity: O(V^2) with array; O((V+E)lgV) with binary heap; O((VlgV+E) with Fibonacci heap
- Greedy method

    ```html
    priority queue Q = G.V
    while Q is not empty
        u = EXTRACT-MIN(Q)
        S.add(u)
        for each v in G.adj[u]
            RELAX(u,v,w)
    ```

**Floyds-Warshall**

- Directional, (negative) weighted, all sources

- Complexity: O(V^3)

- Method: DP

    transition function: `D[i][j] = min(D[i][j], D[i][k] + D[k][j])`

    ```cpp
    void Floyds() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }
    ```

## Problem: Maximum flow 
- Ford-Fulkerson method

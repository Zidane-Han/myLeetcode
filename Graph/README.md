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

- Prim algorithm

```html
for each u in G.V
	u.key = inf
	u.pi = NIL

r.key = 0
Q = G.V

while Q is not empty
	u = EXTRACT-MIN(Q)
	for each v in G.adj[u]
		if v in Q && w(u,v) < v.key
    	v.pi = u
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

  $$ d^{k}_{ij}=min(d^{k-1}_{ij},d^{k-1}_{ik}+d^{k-1}_{kj}) $$
  
  
## Problem: Maximum flow 
- Ford-Fulkerson method

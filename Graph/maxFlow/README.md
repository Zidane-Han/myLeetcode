# maxFlow

## Ford-Fulkerson method

- Augmenting path. Find an undirected path from s to t such that:
  - can increase flow on forward edges (not full)
  - can decrease flow on backward edges (not empty)
- Method

```html
1. Start with 0 flow
2. While there exists an augmenting path:
- find an augmenting path
- compute bottleneck capacity
- increase flow on that path by bottleneck capacity
3. Terminate: all paths from s to t are blocked by either a full forward edge or an empty backward edge.
```

- Implementation

  - FlowEdge

  ```cpp
  // create flow edge
  void FlowEdge(int v, int w, double capacity) {
  	this.v = v;
    this.w = w;
    this.capacity = capacity;
  }
  
  // other endpoint
  int other(int vertex) {
    if (vertext == v)	return w;
    else if (vertext == w)	return v;
  }
  
    
  // residual capacity toward v
  double residualCapcityTo(int vertex) {
    if (vertext == v)	return flow;
    else if (vertext == w)	return capacity-flow;
  }
  
  // add delta flow toward v
  void addResidualFlowTo(int v, double delta) {
    if (vertext == v)	flow -= delta;
    else if (vertext == w)	flow += delta;
  }
  ```

- - FlowNetwork

  ```java
  public class FlowNetwork
  {
    private final int V;
    private Bag<FlowEdge>[] adj;
    
    public FlowNetwork(int V) {
      this.V = V;
      adj = (Bag<FlowEdge>[]) new Bag[V];
      for (int v = 0; v < V; v++) {
        adj[v] = new Bag<FlowEdge>();
      }
    }
    
    public void addEdge(FlowEdge e) {
      int v = e.from();
      int w = e.to();
      adj[v].add(e);
      adj[w].add(e);
    }
    
    public Iterable<FlowEdge> adj(int v) {
      return adj[v];
    }
  }
  ```

- - Ford-Fulkerson

  ```cpp
  void FordFulkerson(FlowNetwork G, int s, int t) {
    double value = 0;
    while (hasAugmentPath(G, s, t)) {
      double bottle = DBL_MAX;
      for (int v = t; v != s; v = edgeTo[v].other(v)) {
        bottle = min(bottle, edgeTo[v].residualCapacity(v));
      }
      
      for (int v = t; v != s; v = edgeTo[v].other(v)) {
       	edgeTo[v].addResidualFlowTo(v, bottle); 
      }
      value += bottle;
    }
  }
  
  bool hasAugmentPath(FlowNetwork G, int s, int t) {
    edgeTo = new FlowEdge[G.V()];
    marked = new boolean[G.V()];
    
    Queue<Integer> q = new Queue<Integer>();
    q.enqueue(s);
    marked[s] = true;
    while (!q.isEmpty()) {
    	int v = q.dequeue();
      for (FlowEdge e : G.adj(v)) {
        int w = e.other(v);
        if (e.residualCapacityTo(w) > 0 && !marked[w]) {
          edgeTo[w] = e;
          marked[w] = true;
          q.enqueue(w);
        }
      }
    }
    return mared[t];	// is t reachable from s in residual network?
  }
  ```

  

- Complexity

  | augmenting path | Number of paths | Implementation |
  | --------------- | --------------- | -------------- |
  | Shortest path   | < 0.5EU         | Queue(BFS)     |
  | fattest path    | < E*ln(EU)      | Priority queue |
  | random path     | < EU            | random queue   |
  | DFS path        | < EU            | Stack(DFS)     |

  
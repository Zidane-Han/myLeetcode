# Union Find

**Make Set**

- O(N)

```c++
vector<int> uf(N, 0);
for (int i = 0; i < N; i++) {
    uf[i] = i;
}	
```

**Union**

- ONLY the root has the same value as its index.
- Complexity: O(N) 

```c++
void union(int p, int q) {
    int pid = root(p);
    int qid = root(q);
    uf[pid] = qid;
}

bool connected(int p, int q) {
    return (root(p) == root(q));
}
```

**Find**

- Complexity: O(N) 

```c++
int root(int i) {
	while (i != uf[i]) {
    i = uf[i];
  }
  return i;
}
```



**Improvement**

- Weighted quick-union

  - O(lgN) for union and connected

  ```c++
  // maintain extra array sz[i] to count number of objects in the tree rooted at i
  void union(int p, int q) {
  	int pid = root(p);
  	int qid = root(q);
    
    if (sz[pid] < sz[qid]) {
    	uf[pid] = qid;
      sz[qid] = sz[pid];
    } else {
      uf[qid] = pid;
      sz[pid] = sz[qid];
    }
  }
  ```

- Path compression

  ```c++
  int root(int i) {
  	while (i != uf[i]) {
      uf[i] = uf[uf[i]];	// flatten the tree
      i = uf[i];
    }
    return i;
  }
  ```

  

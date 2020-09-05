# Union Find

**Make Set **

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
    i = uf[i]
  }
  return i;
}
```



**Improvement**

- Weighted quick-union
- Path compression


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // connections
        vector<vector<int>> graph(n+1, vector<int>(n+1, -1));
        for (auto edge : times) {
            graph[edge[0]][edge[1]] = edge[2];
        }
        
        // dist from source point
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        
        // queue for bfs
        queue<int> q;
        q.push(k);
        
        while (!q.empty()) {
            unordered_set<int> visited;
            for (int i = q.size(); i >= 1; i--) {
                int u = q.front();
                q.pop();
                
                for (int v = 1; v <= n; v++) {
                    if (graph[u][v] != -1 && dist[u] + graph[u][v] < dist[v]) {
                        if (!visited.count(v)) {
                            q.push(v);
                            visited.insert(v);
                        }
                    
                        dist[v] = dist[u] + graph[u][v];
                    }
                }   
            }
        }
        
        int res = *max_element(dist.begin() + 1, dist.end());  
        return (res == INT_MAX) ? -1 : res;
    }
};



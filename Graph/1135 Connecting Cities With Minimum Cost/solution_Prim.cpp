class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        typedef pair<int, int> pii;
        vector<vector<pii>> adj(N+1);
        for (auto connect : connections) {
            adj[connect[0]].push_back({connect[1], connect[2]});
            adj[connect[1]].push_back({connect[0], connect[2]});
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 1});    // cost, src
        
        vector<bool> visited(N+1, false);
        
        vector<int> mincost(N+1, INT_MAX);
        int res = 0;
        while (!pq.empty()) {
            auto currt = pq.top(); pq.pop();
            int w = currt.first;
            int u = currt.second;
            if (visited[u]) continue;
            visited[u] = true;
            res += w;
            for (auto v : adj[u]) {
                if (v.second < mincost[v.first]) {
                    mincost[v.first] = v.second;
                    pq.push({v.second, v.first});
                }
            }
            
        }
        
        for (int i = 1; i < N+1; i++) {
            if (!visited[i]) return -1;
        }
        
        return res;
    }
};
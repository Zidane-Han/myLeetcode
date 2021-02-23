class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjcent list (source: weight, target)
        typedef pair<int, int> pii;
        vector<vector<pii>> adj(n+1);
        for (auto edge : times) {
            adj[edge[0]].emplace_back(edge[2], edge[1]);
        }
        
        // dist
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        
        // pq
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto currt = pq.top();
            pq.pop();
            int weight = currt.first;
            int u = currt.second;
            
            for (auto v : adj[u]) {
                if (weight + v.first < dist[v.second]) {
                    dist[v.second] = weight + v.first;
                    pq.push({dist[v.second], v.second});
                }
            }
        }
        
        int res = *max_element(dist.begin() + 1, dist.end());  
        return (res == INT_MAX) ? -1 : res;
    }
};



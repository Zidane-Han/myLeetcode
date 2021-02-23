class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // adj list
        typedef pair<int, int> pii;
        vector<vector<pii>> adj(n+1);
        for (auto edge : flights) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
        // pq for bfs (total prices, node, i-stops from src)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            auto currt = pq.top(); pq.pop();
            int price = currt[0];
            int node = currt[1];
            int stop = currt[2];
            
            if (node == dst)    return price;
            if (stop <= K) {
                for (auto next : adj[node]) {
                    pq.push({price+next.second, next.first, stop+1});
                }   
            }
        }
        
        return -1;
    }
};

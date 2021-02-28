class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // graph (src:[target, cost]; index = y + x * n)
        typedef pair<int, int> pii;
        vector<vector<pii>> graph(m*n);
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                int dir = grid[x][y]; 
                int cost;
                if (y+1 < n)    graph[y+x*n].emplace_back(y+x*n+1, (dir != 1));
                if (y-1 >= 0)    graph[y+x*n].emplace_back(y+x*n-1, (dir != 2));
                if (x+1 < m)    graph[y+x*n].emplace_back(y+x*n+n, (dir != 3));
                if (x-1 >= 0)    graph[y+x*n].emplace_back(y+x*n-n, (dir != 4));
            }
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;  // (total cost by now, src)
        pq.push({0, 0});
        
        vector<int> cost(m*n, INT_MAX);
        cost[0] = 0;

        while (!pq.empty()) {
            auto currt = pq.top();  pq.pop();
            int ucost = currt.first;
            int u = currt.second;
            if (u == m*n-1) continue;
            for (auto v : graph[u]) {
                if (ucost + v.second < cost[v.first]) {
                    cost[v.first] = ucost + v.second;
                    pq.push({cost[v.first], v.first});
                }
            }
        }
        
        return cost[m*n-1];
    }
};
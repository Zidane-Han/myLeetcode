class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        
        // graph (<target, tar_val>; index = y + x * n)
        typedef pair<int, int> pii;
        vector<vector<pii>> graph(m*n);
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (y+1 < n)    graph[y+x*n].emplace_back(y+x*n+1, A[x][y+1]);
                if (y-1 >= 0)   graph[y+x*n].emplace_back(y+x*n-1, A[x][y-1]);
                if (x+1 < m)    graph[y+x*n].emplace_back(y+x*n+n, A[x+1][y]);
                if (x-1 >= 0)   graph[y+x*n].emplace_back(y+x*n-n, A[x-1][y]);
            }
        }
        
        priority_queue<pair<int, int>> pq;  // largest at top
        pq.push({A[0][0], 0});  // value, src_index
        
        vector<int> res(m*n, 0);
        res[0] = A[0][0];
        
        while (!pq.empty()) {
            auto currt = pq.top(); pq.pop();
            int val = currt.first;
            int u = currt.second;
            if (u == m*n-1) continue;
            
            for (auto v : graph[u]) {
                if (min(val, v.second) > res[v.first]) {
                    res[v.first] = min(val, v.second);
                    pq.push({res[v.first], v.first});
                }
            }    
        }
        
        return res[m*n-1];
    }
};
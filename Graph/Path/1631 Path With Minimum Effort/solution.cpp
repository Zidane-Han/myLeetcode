class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        // construct graph
        typedef pair<int, int> pii;
        vector<vector<pii>> graph(row*col);
        // horizontal connect
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col-1; j++) {
                int delta = abs(heights[i][j] - heights[i][j+1]);
                graph[col*i+j].emplace_back(col*i+j+1, delta);
                graph[col*i+j+1].emplace_back(col*i+j, delta);
            }
        }
        // vertical connect (index = col*i + j)
        for (int i = 0; i < row-1; i++) {
            for (int j = 0; j < col; j++) {
                int delta = abs(heights[i][j] - heights[i+1][j]);
                graph[col*i+j].emplace_back(col*i+j+col, delta);
                graph[col*i+j+col].emplace_back(col*i+j, delta);
            }
        }
        
        // priority queue (mindiff, src)
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        
        // mindiff
        vector<int> mindiff(row*col, INT_MAX);
        mindiff[0] = 0;
        
        // visited
        vector<bool> visited(row*col, false);
        
        
        while (!pq.empty()) {
            auto currt = pq.top(); pq.pop();
            int diff = currt.first;
            int u = currt.second;
            if (visited[u]) continue;
            visited[u] = true;
            
            for (auto v : graph[u]) {
                if (max(diff, v.second) < mindiff[v.first]) {
                    mindiff[v.first] = max(diff, v.second);
                    if (v.first != row*col-1)   pq.push({mindiff[v.first], v.first});
                }
            }
        }
        
        return mindiff[row*col-1];
    }
};
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // Dijkstra
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        dists[start[0]][start[1]] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, start[0], start[1]});
        
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        
        while (!pq.empty()) {
            auto currt = pq.top();  pq.pop();
            if (currt[1] == destination[0] && currt[2] == destination[1]) continue;
            
            for (auto dir : dirs) {
                int x = currt[1];
                int y = currt[2];
                int dist = currt[0];
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                    dist++;
                }
                x -= dir[0];
                y -= dir[1];
                dist--;
                
                if (dists[x][y] > dist) {
                    dists[x][y] = dist;
                    pq.push({x, y, dist});
                }
            }
        }
        
        int res = dists[destination[0]][destination[1]];
        return (res == INT_MAX) ? -1 : res;
    }
};
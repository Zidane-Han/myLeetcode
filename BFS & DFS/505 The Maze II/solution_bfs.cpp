class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // BFS
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        dists[start[0]][start[1]] = 0;
        
        queue<vector<int>> q;
        q.push({start[0], start[1]});
        
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto currt = q.front();  q.pop();
            if (currt == destination) continue;
            
            for (auto dir : dirs) {
                int x = currt[0];
                int y = currt[1];
                int dist = dists[x][y];
                
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
                    q.push({x, y});
                }
            }
        }
        
        int res = dists[destination[0]][destination[1]];
        return (res == INT_MAX) ? -1 : res;
    }
};
class Solution {
private:
    vector<vector<int>> dirs;
    vector<int> dst;
    
    void dfs(vector<vector<int>>& maze, vector<int>& node, vector<vector<int>>& dists) {
        if (node == dst) return;
        
        for (auto dir : dirs) {
            int x = node[0];
            int y = node[1];
            int dist = dists[x][y];
            
            while (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0) {
                x += dir[0];
                y += dir[1];
                dist++;
            }
            x -= dir[0];
            y -= dir[1];
            dist--;
            
            if (dists[x][y] > dist) {
                dists[x][y] = dist;
                vector<int> tmp = {x, y};
                dfs(maze, tmp, dists);
            }
            
        }
        
        return;
    }
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // DFS
        dst = destination;
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        dists[start[0]][start[1]] = 0;
        
        dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        
        dfs(maze, start, dists);
        
        int res = dists[destination[0]][destination[1]];
        return (res == INT_MAX) ? -1 : res;
    }
};
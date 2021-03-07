class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        // Dijkstra
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<int>> dists(m, vector(n, INT_MAX));   // pos:dist
        dists[ball[0]][ball[1]] = 0;
        
        unordered_map<int, string> strs;   // pos(y+n*x):res
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, ball[0], ball[1]});
        
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        vector<char> letters = {'u', 'd', 'r', 'l'};
        
        while (!pq.empty()) {
            auto currt = pq.top();  pq.pop();
            if (currt[1] == hole[0] && currt[2] == hole[1]) break;
            
            for (int i = 0; i < 4; i++) {
                int dist = currt[0];
                int x = currt[1];
                int y = currt[2];
                // add holes
                while (x+dirs[i][0] >= 0 && x+dirs[i][0] < m && y+dirs[i][1] >= 0 && y+dirs[i][1] < n && maze[x+dirs[i][0]][y+dirs[i][1]] == 0) {
                    x += dirs[i][0];
                    y += dirs[i][1];
                    dist++;
                    if (x == hole[0] && y == hole[1]) break;
                }
                
                if (dists[x][y] > dist) {
                    dists[x][y] = dist;
                    strs[y+n*x] = strs[currt[2]+n*currt[1]] + letters[i];
                    pq.push({dist, x, y});
                    continue;
                } else if (dists[x][y] == dist && strs[y+n*x].compare(strs[currt[2]+n*currt[1]] + letters[i]) > 0) {
                    strs[y+n*x] = strs[currt[2]+n*currt[1]] + letters[i];
                    pq.push({dist, x, y});
                }
                
            }
        }
        
        return (strs.count(hole[1] + n*hole[0])) ? strs[hole[1] + n*hole[0]] : "impossible";
    }
};
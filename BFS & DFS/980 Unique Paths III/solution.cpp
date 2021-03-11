class Solution {
private:
    int row;
    int col;
    int res = 0;
    int cntzero = 0;
    vector<int> start;
    
    void dfs(int x, int y, int cnt, vector<vector<int>>& grid) {
        if (grid[x][y] == -1 || grid[x][y] == 3) {
            return;
        }
        
        if (grid[x][y] == 2) {
            if (cnt == cntzero + 1) res++;
            return;
        }
        
        grid[x][y] = 3;
        cnt++;
        
        if (x < row - 1)    dfs(x+1, y, cnt, grid);
        if (x > 0)          dfs(x-1, y, cnt, grid);
        if (y > 0)          dfs(x, y-1, cnt, grid);
        if (y < col - 1)    dfs(x, y+1, cnt, grid);
        
        grid[x][y] = 0;
        cnt--;
        
        return;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // dfs
        row = grid.size();
        col = grid[0].size();
        // find start & end point
        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                if (grid[x][y] == 0) {
                    cntzero++;
                } else if (grid[x][y] == 1) {
                    start = {x, y};
                }
            }
        }
        
        dfs(start[0], start[1], 0, grid);
        
        return res;
    }
};

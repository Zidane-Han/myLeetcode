class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> score(row, vector<int>(col, 0));
        score[0][0] = grid[0][0];
        for (int i = 1; i < col; i++)   score[0][i] = score[0][i-1] + grid[0][i];
        for (int i = 1; i < row; i++)   score[i][0] = score[i-1][0] + grid[i][0];
        // traverse
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                score[i][j] = min(score[i-1][j], score[i][j-1]) + grid[i][j];
            }
        }
        
        return score[row-1][col-1];
    }
};
class Solution {
private:
    bool isValid(int row, int col, vector<string>& puzz) {
        for (int i = 0; i < row; i++) {
            if (puzz[i][col] == 'Q') {
                return false;
            }
        }
        
        for (int j = 0; j < col; j++) {
            if (puzz[row][j] == 'Q') {
                return false;
            }
        }
        
        for (int i = 0; i < row; i++) {
            int m = col - (row - i);
            int n = col + (row - i);
            if (m >= 0 && puzz[i][m] == 'Q')    return false;
            if (n >= 0 && puzz[i][n] == 'Q')    return false;
        }
            
        return true;
    }
    
    void helper(int row, vector<string>& puzz, vector<vector<string>>& res) {
        int n = puzz.size();
        if (row == n) {
            res.push_back(puzz);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, puzz)) {
                puzz[row][i] = 'Q';
                helper(row + 1, puzz, res);
                puzz[row][i] = '.';
            }
        }
        
        return;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> puzz(n, string(n, '.'));
        helper(0, puzz, res);
        return res;
    }
};
class Solution {
private:
    bool helperSudoku(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j >= 9) return helperSudoku(board, i+1, 0);
        if (board[i][j] != '.') {
            // go next
            return helperSudoku(board, i, j+1);    
        }
        for (char c = '1'; c <= '9'; c++) {
            if (!isValid(board, i, j, c))   continue;
            board[i][j] = c;
            if (helperSudoku(board, i, j+1))  return true;
            board[i][j] = '.';
        }
        
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j, char val) {
        // check row
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == val) return false;
        }
        
        // check col
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == val) return false;
        }
        
        // check cell
        int row = i - i%3;
        int col = j - j%3;
        for (int m = 0; m < 3; m++) {
            for (int n = 0; n < 3; n++) {
                if (board[row + m][col + n] == val)   return false;
            }
        }
        
        return true;
    }
    
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        helperSudoku(board, 0, 0);
    }
};
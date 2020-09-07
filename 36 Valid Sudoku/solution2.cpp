class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m,n,t,l;
        for (int i=0;i<9;++i) {
            for (int j=0;j<8;++j) {
                for (int k=j+1;k<9;++k) {
                    m=i/3*3+j/3; n=i%3*3+j%3; t=i/3*3+k/3; l=i%3*3+k%3;
                    if ((board[i][k]!='.' && board[i][k] == board[i][j]) || 
						(board[k][i]!='.' && board[k][i] == board[j][i]) || 
						(board[t][l]!='.' && board[m][n] == board[t][l])) 
                        return false;
                }
            }
        }
        return true;
    }
};
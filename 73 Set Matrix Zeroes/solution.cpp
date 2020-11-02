class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        bool rowzero = false;
        bool colzero = false;
        
        for (int i = 0; i < col; i++) {
            if (matrix[0][i] == 0) {
                rowzero = true;
                break;
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                colzero = true;
                break;
            }
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < col; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        if (rowzero) {
            for (int i = 0; i < col; i++)   matrix[0][i] = 0;
        }
        
        if (colzero) {
            for (int i = 0; i < row; i++)   matrix[i][0] = 0;
        }
        
    }
};
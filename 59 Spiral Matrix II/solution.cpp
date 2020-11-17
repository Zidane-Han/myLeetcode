class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int val = 1;
        
        int left = 0;
        int right = n-1;
        int up = 1;
        int down = n-1;
        
        while (true) {
            // right
            if (left > right)   break;
            for (int i = left; i <= right; i++, val++) {
                mat[up-1][i] = val;
            }
            right--;
            // down
            if (up > down)   break;
            for (int j = up; j <= down; j++, val++) {
                mat[j][right+1] = val;
            }
            down--;
            //left
            if (left > right)   break;
            for (int i = right; i >= left; i--, val++) {
                mat[down+1][i] = val;
            }
            left++;
            // up
            if (up > down)   break;
            for (int j = down; j >= up; j--, val++) {
                mat[j][left-1] = val;
            }
            up++;
        }
        
        return mat;
    }
};
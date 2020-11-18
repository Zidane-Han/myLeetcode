class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)   return false;
        if (matrix[0].size() == 0)   return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
       
        for (int i = 0; i < row; i++) {
            if (matrix[i][col-1] < target) {
                continue;
            } else if (matrix[i][0] <= target && matrix[i][col-1] >= target) {
                vector<int> v = matrix[i];
                return (find(v.begin(), v.end(), target) != v.end());
            } else {
                return false;
            }
        }
        
        return false;
    }
};
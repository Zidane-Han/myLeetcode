class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)   return false;
        if (matrix[0][0] > target || matrix.back().back() < target) return false;
        
        int x = matrix.size() - 1;
        int y = 0;
        
        while (true) {
            if (matrix[x][y] > target) x--;
            else if (matrix[x][y] < target) y++;
            else return true;
            
            if (x < 0 || y >= matrix[0].size())   break;
        }
        
        return false;
    }
};
class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        
        int res = 0;
        vector<int> monoq = {};
        for (int i = 0; i < heights.size(); i++) {
            if (monoq.empty() || heights[i] >= heights[monoq.back()]) {
                monoq.push_back(i);
            } else {
                // delete element (while) and update values
                int ele = monoq.back();
                monoq.pop_back();
                
                int len;
                if (monoq.empty()) {
                    len = i;
                } else {
                    len = i - monoq.back() - 1;
                }
                
                res = max(res, heights[ele]*len);
                i--;
            }
        }
        
        return res;     
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int res = 0;
        vector<int> height(col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
            }
            res = max(res, largestRectangleArea(height));
        }
        
        return res;
    }
};
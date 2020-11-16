class Solution {
private:
    vector<int> hlimit;
    vector<int> vlimit;
    
    void helper(int row, int col, char dir, vector<int>& res, vector<vector<int>>& matrix) {
        if ((dir == 'r' || dir == 'l') && (hlimit[0] > hlimit[1]))  return;
        if ((dir == 'u' || dir == 'd') && (vlimit[0] > vlimit[1]))  return;
        
        if (dir == 'r') {
            for (int i = hlimit[0]; i <= hlimit[1]; i++) {
                res.push_back(matrix[row][i]);
            }
            hlimit[1] -= 1;
            helper(row, hlimit[1]+1, 'd', res, matrix);
        } else if (dir == 'd') {
            for (int i = vlimit[0]; i <= vlimit[1]; i++) {
                res.push_back(matrix[i][col]);
            }
            vlimit[1] -= 1;
            helper(vlimit[1]+1, col, 'l', res, matrix);
        } else if (dir == 'l') {
            for (int i = hlimit[1]; i >= hlimit[0]; i--) {
                res.push_back(matrix[row][i]);
            }
            hlimit[0] += 1;
            helper(row, hlimit[0]-1, 'u', res, matrix);
        } else {
            // dir = 'u'
            for (int i = vlimit[1]; i >= vlimit[0]; i--) {
                res.push_back(matrix[i][col]);
            }
            vlimit[0] += 1;
            helper(vlimit[0]-1, col, 'r', res, matrix);
        }
            
        return;
    }
    
public:
    // order: r(ight) -> d(own) -> l(eft) -> u(p)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> res = {};
        hlimit = {0, col-1};
        vlimit = {1, row-1};
        
        helper(0, 0, 'r', res, matrix);
        
        return res;
    }
};
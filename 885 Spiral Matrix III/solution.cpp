class Solution {
private:
    vector<vector<int>> res;
    
    void add(int x, int y, int row, int col) {
        if (x >= 0 && x < row && y >= 0 && y < col) res.push_back({x, y});
    }

public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        // 1,1,2,2,3,3,4,4 (right->down(+1)->left->up(+1))
        // 0<= x < 5; 0 <= y < 6
        res = {};    
        int step = 1;
        while (res.size() < R * C) {
            // right
            for (int i = 0; i < step; i++) {
                add(r0, c0, R, C);
                c0++;
            }
            // down
            for (int i = 0; i < step; i++) {
                add(r0, c0, R, C);
                r0++;
            }
            step++;
            
            // left
            for (int i = 0; i < step; i++) {
                add(r0, c0, R, C);
                c0--;
            }
            // up
            for (int i = 0; i < step; i++) {
                add(r0, c0, R, C);
                r0--;
            }
            step++;
        }
        
        return res;
    }
};
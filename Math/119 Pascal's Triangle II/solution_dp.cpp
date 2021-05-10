class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // dp
        // pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]
        
        vector<int> currt, prev = {1};
        
        for (int i = 1; i <= rowIndex; i++) {
            currt.assign(i+1, 1);
            for (int j = 1; j < i; j++) {
                currt[j] = prev[j-1] + prev[j];
            }
            
            //prev = currt;
            prev = move(currt);
        }
        
        return prev;
    }
};
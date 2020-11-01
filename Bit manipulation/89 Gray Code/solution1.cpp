class Solution {
public:
    vector<int> grayCode(int n) {
        // mirror
        vector<int> res = {0};
        
        for (int i = 1; i <= n; i++) {
            int size = res.size();
            for (int k = size - 1; k >= 0; k--) {
                res.push_back((1 << i - 1) | res[k]);
            }
        }
        
        return res;
    }
};


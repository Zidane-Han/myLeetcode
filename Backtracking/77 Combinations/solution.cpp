class Solution {
private:
    vector<vector<int>> res;
    
    void helper(int index, vector<int>& currt, int n, int k) {
        if (index == n && k > 0)    return;
        
        if (k == 0) {
            res.push_back(currt);
            return;
        }
        
        for (int i = index + 1; i <= n; i++) {
            currt.push_back(i);
            helper(i, currt, n, k-1);
            currt.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        res = {};
        
        for (int i = 1; i <= n; i++) {
            vector<int> tmp = {i};
            helper(i, tmp, n, k-1);    
        }
        
        return res;
    }
};
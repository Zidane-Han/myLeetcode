class Solution {
private:
    void helper(int num, int sum, int last_val, vector<int>& currt, vector<vector<int>>& res) {
        if (sum == 0 && num == 0) {
            res.push_back(currt);
            return;
        } else if (sum > 0 && num > 0) {
            for (int val = last_val + 1; val < 10; val++) {
            currt.push_back(val);
            helper(num-1, sum-val, val, currt, res);
            currt.pop_back();
            }
        } else {
            return;
        }
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res = {};
        vector<int> currt = {};
        
        helper(k, n, 0, currt, res);
        
        return res;
    }
};
class Solution {
private:
    void helper(int target, vector<int>& nums, vector<int>& currt, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(currt);
        }
        
        for (int val : nums) {
            currt.push_back(val);
            helper(target-val, nums, currt, res);
            currt.pop_back();
        }
        
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> res = {};
        vector<int> currt = {};
        
        helper(target, nums, currt, res);
        
        return res.size();
    }
};
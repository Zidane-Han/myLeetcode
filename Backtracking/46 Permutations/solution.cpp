class Solution {
public:
    void helper(vector<int>& nums, vector<bool>& visited, vector<int>& currt, vector<vector<int>>& res) {
        if (currt.size() == nums.size()) {
            res.push_back(currt);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])    continue;
            currt.push_back(nums[i]);
            visited[i] = true;
            helper(nums, visited, currt, res);
            currt.pop_back();
            visited[i] = false;
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        
        vector<int> currt = {};
        helper(nums, visited, currt, res);
        
        return res;
    }
};
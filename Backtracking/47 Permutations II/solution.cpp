class Solution {
public:
    void helper(vector<bool>& visited, vector<int>& nums, vector<int>& currt, vector<vector<int>>& res) {
        if (currt.size() == nums.size()) {
            res.push_back(currt);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i]==nums[i-1] && !visited[i-1])   continue;
            
            visited[i] = true;
            currt.push_back(nums[i]);
            helper(visited, nums, currt, res);
            visited[i] = false;
            currt.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> currt = {};
        
        helper(visited, nums, currt, res);
        
        return res;
    }
};
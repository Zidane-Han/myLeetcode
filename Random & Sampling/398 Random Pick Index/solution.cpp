class Solution {
private:
    map<int, vector<int>> table;
    
public:
    Solution(vector<int>& nums) {
        for (int k = 0; k < nums.size(); k++) {
            table[nums[k]].push_back(k);
        }    
    }
    
    int pick(int target) {
        int len = table[target].size();
        return table[target][rand() % len];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
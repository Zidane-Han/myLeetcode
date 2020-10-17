class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, len-1);
        
        dp[0] = 0;
        for (int i = 0; i < len; i++) {
            int tmp = nums[i];
            for (int j = 1; j <= tmp && i+j < len; j++) {
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        
        return dp[len-1];
    }
};
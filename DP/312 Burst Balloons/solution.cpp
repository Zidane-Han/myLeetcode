class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(len+2, vector<int>(len+2, 0));
        
        for (int interval = 1; interval <= len; interval++) {
            for (int i = 1; i <= len-interval+1; i++) {
                int j = i + interval - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }
        
        return dp[1][len];
    }
};
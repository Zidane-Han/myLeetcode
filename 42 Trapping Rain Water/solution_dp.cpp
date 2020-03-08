/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int len = height.size();

        int tmp = 0;
        vector<int> dp(len, 0);
        // left to right
        for (int i = 0; i < len; i++) {
            dp[i] = tmp;
            tmp = max(tmp, height[i]);
        }
        // right to left and do calculation
        tmp = 0;
        for (int i = len-1; i >= 0; i--) {
            dp[i] = min(tmp, dp[i]);
            tmp = max(tmp, height[i]);
            if (dp[i] > height[i]) {
                water += (dp[i] - height[i]);
            }
        }

        return water;
    }

};
// @lc code=end
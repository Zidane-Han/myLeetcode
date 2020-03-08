/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 1. find the max elements
        // 2. left to max_element 
        // 3. max_element to right
        int water = 0;
        int maxPos = max_element(height.begin(), height.end()) - height.begin();
        int len = height.size();

        int l_peak = 0;
        for (int left = 0; left < maxPos; left++) {
            if (height[left] > l_peak) {
                l_peak = height[left];
            } else {
                water += (l_peak - height[left]);
            }
        }

        int r_peak = 0;
        for (int right = len-1; right > maxPos; right--) {
            if (height[right] > r_peak) {
                r_peak = height[right];
            } else {
                water += (r_peak - height[right]);
            }
        }

        return water;
    }

};
// @lc code=end

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

        int left = 0;
        int right = len - 1;
        while (left < right)
        {
            int tmp = min(height[left], height[right]); // level of the wall

            if (tmp == height[left]) {
                left++;
                while (left < right && tmp > height[left]) {
                    water += (tmp - height[left]);
                    left++;
                }
            } else {
                right--;
                while (left < right && tmp > height[right])
                {
                    water += (tmp - height[right]);
                    right--;
                }
                
            }


        }
        
        return water;
    }

};
// @lc code=end
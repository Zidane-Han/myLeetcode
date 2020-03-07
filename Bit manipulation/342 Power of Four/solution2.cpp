/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num & 0x55555555) != 0 && (num & (num - 1)) == 0;
    }
};
// @lc code=end
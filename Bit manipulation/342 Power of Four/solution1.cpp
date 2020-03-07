/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 1) {
            return false;
        }

        int x = log2(num);

        return (x == log2(num)) && (x%2 == 0);
    }
};
// @lc code=end


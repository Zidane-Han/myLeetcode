/*
 * [32] Longest Valid Parentheses
 */


class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<int> dp(len+1, 0);

        for (int i = 2; i <= len; i++) {
            if (s[i-1] == ')') {
                if (s[i-2] == '(') dp[i] = dp[i-2]+2;

                if (s[i-2] == ')' && i-2-dp[i-1] >= 0 && s[i-2-dp[i-1]] == '(') {
                    dp[i] = dp[i-1] + dp[i-2-dp[i-1]] + 2;
                }
            }

        }        

        return *max_element(dp.begin(), dp.end());
    }
};
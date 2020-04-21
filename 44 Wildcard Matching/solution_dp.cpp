/*
 *
 * [44] Wildcard Matching
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.size();
        int len_p = p.size();

        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));
        // boundary conditions
        dp[0][0] = true;
        for (int i = 1; i <= len_p; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            }
        }

        // DP
        for (int i = 1; i <= len_s; i++) {
            for (int j = 1; j <= len_p; j++) {
                if (p[j - 1] == '*') {
                    // this is important
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[len_s][len_p];
    }
};
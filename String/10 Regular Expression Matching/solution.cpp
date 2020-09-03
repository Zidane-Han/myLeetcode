/*
 *
 * [10] Regular Expression Matching
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.size();
        int len_p = p.size();
        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= len_p; j++) {
            dp[0][j] = (p[j-1] == '*' ? dp[0][j-2] : false);
        }
        
        for (int i = 1; i <= len_s; i++) {
            for (int j = 1; j <= len_p; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } 
                
                if (p[j-1] == '*') {
                    // match with preceeding
                    if (s[i-1] == p[j-2] || p[j-2] == '.') {
                        // dp[i][j-2]-> *=0
                        // dp[i-1][j]-> *=repeat
                        dp[i][j] = (dp[i-1][j] || dp[i][j-2]);
                    } else {
                        // unmatch, then suppose *=0
                        dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        
        return dp[len_s][len_p];
    }
};
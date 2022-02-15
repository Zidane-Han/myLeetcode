class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 + n2 != s3.size()) {
            return false;
        }
        
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1));
        // init
        dp[0][0] = true;
        for (int i = 0; i < n1; i++) {
            dp[i+1][0] = (dp[i][0] && s1[i] == s3[i]);
        }
        for (int i = 0; i < n2; i++) {
            dp[0][i+1] = (dp[0][i] && s2[i] == s3[i]);
        }
        
        // dp
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                dp[i+1][j+1] = ((dp[i][j+1] && s1[i] == s3[i+j+1]) || (dp[i+1][j] && s2[j] == s3[i+j+1]));
            }
        }

        return dp[n1][n2];
    }
};
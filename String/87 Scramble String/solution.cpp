class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2)   return true;
        int len = s1.size();
        
        vector<vector<vector<bool>>> dp(len, vector<vector<bool>>(len, vector<bool>(len + 1)));
        
        // i: start index of s1
        // j: start index of s2
        // k: length of two substrings
        
        for (int k = 1; k <= len; k++) {
            for (int i = 0; i <= len - k; i++) {
                for (int j = 0; j <= len -k; j++) {
                    if (k == 1) {
                        dp[i][j][k] = (s1[i] == s2[j]);
                    } else {
                        for (int n = 1; n < k; n++) {
                            if ((dp[i][j][n] && dp[i+n][j+n][k-n])||(dp[i][j+k-n][n] && dp[i+n][j][k-n])) {
                                dp[i][j][k] = true;
                            }
                            
                        }    
                    }
                }
            }
        }
        
        
        return dp[0][0][len];
    }
};

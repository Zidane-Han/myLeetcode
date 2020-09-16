class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())  return "";
        
        int len = s.size();
        
        int left = 0;
        int maxlen = 1;

        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
            for (int j = 0; j < i; j++) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j+1][i-1]));
                if (dp[j][i] && maxlen < i - j + 1) {
                    maxlen = i - j + 1;
                    left = j;
                }
            }
        }


        return s.substr(left, maxlen);
    }
};
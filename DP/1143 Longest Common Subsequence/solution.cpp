class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        
        int res[len1+1][len2+1];
        // boundary conditions
        for (int i = 0; i <= len1; i++) res[i][0] = 0;
        for (int j = 0; j <= len2; j++) res[0][j] = 0;
        
        // transition
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i-1] == text2[j-1]) {
                    res[i][j] = res[i-1][j-1] + 1;
                } else {
                    res[i][j] = max(res[i-1][j], res[i][j-1]);
                }
            }
        }
        
        return res[len1][len2];
    }
};

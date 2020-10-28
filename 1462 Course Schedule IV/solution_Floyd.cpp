class Solution { 
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (auto courses : prerequisites) {
            dp[courses[0]][courses[1]] = true;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][k] && dp[k][j])   dp[i][j] = true;
                }
            }
        }

        vector<bool> ans = {};
        for (auto query : queries) {
            ans.push_back(dp[query[0]][query[1]]);
        }
        return ans;
    }
};
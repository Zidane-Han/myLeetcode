class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 1);
        vector<int> ptr(primes.size(), 0);
        
        for (int i = 1; i < n; i++) {
            int val = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                val = min(val, dp[ptr[j]] * primes[j]);
            }
            
            for (int j = 0; j < primes.size(); j++) {
                if (val == dp[ptr[j]] * primes[j]) ptr[j]++;
            }
            
            dp[i] = val;
        }
        
        return dp[n-1];
    }
};
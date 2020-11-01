class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int len = arr.size();
        vector<vector<int>> arrsort;
        for (int i = 0; i < len; i++) {
            arrsort.push_back({arr[i], i});
        }
        sort(arrsort.begin(), arrsort.end());   // (value, index)
        
        vector<int> dp(len, 1);
        for (auto element : arrsort) {
            int value = element[0];
            int index = element[1];
        
            for (int left = index - 1; left >= index - d && left >= 0; left--) {
                if (arr[left] >= value) break;
                dp[index] = max(dp[index], dp[left] + 1);
            }
            
            for (int right = index + 1; right <= index + d && right < len; right++) {
                if (arr[right] >= value) break;
                dp[index] = max(dp[index], dp[right] + 1);
            }
            
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        
        int ldist = 0;
        int rdist = nums.back() - nums[0];
        
        while (ldist < rdist) {
            int mid = ldist + (rdist - ldist) / 2;
            int pair = 0;
            
            // sliding window
            int start = 0;
            for (int i = 0; i < len; i++) {
                while (start < len && nums[i] - nums[start] > mid)    start++;
                pair += (i - start);
            }
            
            if (pair < k) {
                ldist = mid + 1;
            } else {
                rdist = mid;
            }    
        }
        
        return rdist;
    }
};
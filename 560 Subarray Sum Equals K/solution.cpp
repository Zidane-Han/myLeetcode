class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;  // (sum, times)
        freqs[0] = 1;
        
        int res = 0;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            
            if (freqs.find(sum - k) != freqs.end()) {
                res += freqs[sum-k];
            } 
            
            freqs[sum] += 1;
        }
        
        return res;
    }
};
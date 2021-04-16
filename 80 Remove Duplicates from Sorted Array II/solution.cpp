class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // i is a fast ptr; len is a slow ptr
        int n = nums.size();
        if (n < 2)  return n;
        int len = 2;
        
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[len-2] || nums[i] != nums[len-1]) {
                nums[len] = nums[i];
                len++;
            }
        }
        
        return len;
    }
};
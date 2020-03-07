class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // from back to front
        // if decrease order, reverse
        // the same or increasing, extend, reverse and exchange

        int len = nums.size();
        if (len == 0 || len == 1) return;

        int i = len-2;

        while (i >= 0 && nums[i] >= nums[i+1]) {i--;}

        if (i >= 0) {
            // swap the pos just larger than nums[i], from right to left
            int j = len-1;
            while (j>=0 && nums[j] <= nums[i]) {j--;}
            swap(nums[i], nums[j]);

        }

        reverse(nums.begin()+i+1, nums.end());
    }
};

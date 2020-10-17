class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        int furthest = 0;
        int max_reachable = 0;

        for (int i = 0; i < len; i++) {
            max_reachable = max(max_reachable, nums[i]+i);
            if (i == furthest) {
                if (max_reachable >= len-1) {
                    return true;
                } else if (max_reachable <= furthest) {
                    return false;
                } else {
                    furthest = max_reachable;
                }
            }
        }

        return true;
    }
};
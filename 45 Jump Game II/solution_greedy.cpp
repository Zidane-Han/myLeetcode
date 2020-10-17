class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)   return 0;

        int jumps = 0;
        int furthest = 0;
        int max_reachable = 0;

        for (int i = 0; i < len; i++) {
            max_reachable = max(max_reachable, nums[i]+i);
            if (i == furthest) {
                jumps++;
                if (max_reachable >= len-1) {
                    return jumps;
                } else {
                    furthest = max_reachable;
                }
            }
        }
        
        return jumps;
    }
};
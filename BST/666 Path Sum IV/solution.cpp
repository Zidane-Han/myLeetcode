/*
level k:         (n)
                 / \
level k+1: (2n-1)   (2n)
*/
class Solution {
private:
    int res;
    unordered_map<int, int> dict;
    
    void dfs(int pos, int sum) {
        sum += dict[pos];
        
        int level = pos/10;
        int index = pos%10;
        int lnode = 10 * (level + 1) + (2 * index - 1);
        int rnode = 10 * (level + 1) + (2 * index);
        
        if (!dict.count(lnode) && !dict.count(rnode)) {
            res += sum;
        }
        
        if (dict.count(lnode))  dfs(lnode, sum);
        if (dict.count(rnode))  dfs(rnode, sum);
        
        return;
    }
    
public:
    int pathSum(vector<int>& nums) {
        res = 0;
        
        // construct map
        for (auto num : nums) {
            dict[num/10] = num%10;
        }
        
        dfs(nums[0]/10, 0);
        
        return res;
    }
};
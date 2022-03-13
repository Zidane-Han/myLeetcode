/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right)   return nullptr;
        int mid = left + (right - left) / 2;
        
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = helper(nums, left, mid - 1);
        cur->right = helper(nums, mid + 1, right);
        
        return cur;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, (int)(nums.size()-1));
    }
};
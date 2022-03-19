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
    // res: the maximum path sum
    // int: the maximum of the half-branch passing through the root
    int helper(TreeNode* root, int& res) {
        if (!root)  return 0;
        
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        
        res = max(res, root->val + left + right);
        res = max(res, root->val + left);
        res = max(res, root->val + right);
        res = max(res, root->val);
        
        return max(root->val, root->val + max(left, right));
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        
        helper(root, res);
        
        return res;
    }
};
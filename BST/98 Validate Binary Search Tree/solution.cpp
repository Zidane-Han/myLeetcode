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
    bool helper(TreeNode* node, long minval, long maxval) {
        if (node == nullptr)    return true;
        
        if (node->val <= minval || node->val >= maxval) return false;
        
        return (helper(node->left, minval, node->val) && helper(node->right, node->val, maxval));
    }
    
public:
    bool isValidBST(TreeNode* root) {
        // maintain a range (min, max), if left (min, node), if right (node, right)
        // inorder
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

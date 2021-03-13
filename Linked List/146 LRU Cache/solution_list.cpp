/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* node, int sum, int value) {
        if (node == nullptr) {
            return false;
        } else {
            value += node->val;
        }
        
        if (value == sum && node->left == nullptr && node->right == nullptr) {
            return true;
        } else {
            return (dfs(node->left, sum, value) || dfs(node->right, sum, value));
        }
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        else return dfs(root, sum, 0);
        
        
    }
};
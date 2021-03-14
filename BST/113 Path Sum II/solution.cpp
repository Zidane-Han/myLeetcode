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
    vector<vector<int>> res;
    
    void dfs(TreeNode* node, int target, vector<int> tmp) {
        if (node == nullptr)  return;
        target -= node->val;
        tmp.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && target == 0) {
            res.push_back(tmp);
            return;
        }
        
        dfs(node->left, target, tmp);
        dfs(node->right, target, tmp);
        return;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res = {};
        
        dfs(root, targetSum, {});
        
        return res;
    }
};
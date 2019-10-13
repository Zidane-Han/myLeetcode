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
    void postorderTraversal(TreeNode* node, vector<int>& table) {
        if (node != nullptr) {
            this->postorderTraversal(node->left, table);
            this->postorderTraversal(node->right, table);
            table.push_back(node->val);
        }
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res = {};
        this->postorderTraversal(root, res);
        return res;
    }
};

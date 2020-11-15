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
public:
    // divide and conquer
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        if (start > end)    return {nullptr};
        
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            auto left = helper(start, i-1);
            auto right = helper(i+1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
            
        }
        
        return res;
    }
};

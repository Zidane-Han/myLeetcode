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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        
        while (cur) {
            if (cur->left) {
                TreeNode* p = cur->left;    // most right node
                while (p->right && p->right != cur) {
                    p = p->right;
                }
                if (!p->right) {
                    p->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    p->right = nullptr; // recover
                }
            }
            
            if (pre && cur->val < pre->val) {
                if (!first) first = pre;
                second = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        
        swap(first->val, second->val);
    }
};

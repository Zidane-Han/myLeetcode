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
    void inorder(TreeNode* node, vector<int>& v) {
        if (node != nullptr) {
            this->inorder(node->left, v);
            v.push_back(node->val);
            this->inorder(node->right, v);
        }
        
        return;
    }
    
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> v1 = {};
        this->inorder(root1, v1);
        vector<int> v2 = {};
        this->inorder(root2, v2);
        
        // two-sum prob -- one pass
        int i = 0;
        int j = v2.size() -1;
        while (i < v1.size() && j >= 0) {
            if (v1[i] + v2[j] == target) {
                return true;
            } else if (v1[i] + v2[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
};

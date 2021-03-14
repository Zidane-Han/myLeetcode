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
    int res;
    
    void updatetmp(int value, vector<int>& tmp, const int sum) {
        for (int i = 0; i < tmp.size(); i++) {
            tmp[i] += value;
            if (tmp[i] == sum)  res++;
        }
        
        tmp.push_back(value);
        if (value == sum) res++;
        
        return;
    }
    
    
    void dfs(TreeNode* node, vector<int> tmp, const int sum) {
        if (node == nullptr)    return;
        this->updatetmp(node->val, tmp, sum);
        
        dfs(node->left, tmp, sum);
        dfs(node->right, tmp, sum);
        
        return;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        res = 0;
        
        dfs(root, {}, sum);
        
        return res;
    }
};
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
    TreeNode* makeTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& postorder, int postLeft, int postRight) {
        if (preLeft > preRight || postLeft > postRight) {
            return nullptr;
        }
        
        if (preLeft == preRight) {
            return new TreeNode(preorder[preLeft]);
        }
        
        int i = 0;  // index of root of the left-branch at postorder
        for (i = postLeft; i <= postRight; i++) {
            if (postorder[i] == preorder[preLeft + 1])  break;
        }
        
        
        TreeNode* cur = new TreeNode(preorder[preLeft]);
        cur->left = makeTree(preorder, preLeft + 1, preLeft + 1 + i - postLeft, postorder, postLeft, i);
        cur->right = makeTree(preorder, preRight + 2 + i - postRight, preRight, postorder, i + 1, postRight - 1);
        
        return cur;
    }
    
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return makeTree(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
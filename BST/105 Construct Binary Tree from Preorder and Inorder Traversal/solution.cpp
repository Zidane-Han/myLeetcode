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
private:
    TreeNode* makeTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) {
            return nullptr;
        }
        
        int i = 0;  // index of the root in inorder list
        for (i = iLeft; i <= iRight; i++) {
            if (inorder[i] == preorder[pLeft]) {
                break;
            }
        }
        
        TreeNode* cur = new TreeNode(preorder[pLeft]);
        cur->left = makeTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        cur->right = makeTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        
        return cur;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return makeTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
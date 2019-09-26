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
    void PreOrder(TreeNode* node, int x, int y, map<int, map<int, vector<int>>>& table){
        if (node != nullptr) {
            // add value into the table
            table[x][y].push_back(node->val);
            
            this->PreOrder(node->left, x-1, y+1, table);
            this->PreOrder(node->right, x+1, y+1, table);
        }
    }
    
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res = {};
        if (root == nullptr) return res;
        map<int, map<int, vector<int>>> table;
        
        this->PreOrder(root, 0, 0, table);
        
        // take table values into res
        for (auto itx = table.begin(); itx != table.end(); itx++) {
            vector<int> temp = {};
            for (auto ity = itx->second.begin(); ity != itx->second.end(); ity++) {
                temp.insert(temp.end(), ity->second.begin(), ity->second.end());
            }
            res.push_back(temp);
        }
        
        return res;
    }
};

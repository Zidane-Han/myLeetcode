/*
 *
 * [684] Redundant Connection
 */

// if two nodes have the same root, then they cannot be connected!

class Solution {
private:
    int getRoot(int x, vector<int>& root) {
        while (root[x] != 0) {
            x = root[x];
        }
        return x;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(1001, 0);
        
        for (auto edge : edges) {
            int x = getRoot(edge[0], root);
            int y = getRoot(edge[1], root);

            if (x == y)   return edge;

            root[x] = y;
        }

        return {};
    }
};



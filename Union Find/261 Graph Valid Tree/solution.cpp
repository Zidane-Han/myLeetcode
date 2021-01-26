class Solution {
private:
    int root(vector<int>& uf, int i) {
        while(uf[i] != -1) {
            i = uf[i];
        }
        return i;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> uf(n, -1);
        
        for (auto edge : edges) {
            int proot = root(uf, edge[0]);
            int qroot = root(uf, edge[1]);
            if (proot == qroot) {
                return false;
            }
            uf[proot] = qroot;
        }
        
        return (edges.size() == n-1);
        
    }
};

class Solution {
private:
    vector<int> uf;
    
    int root(int i) {
        while (i != uf[i]) {
            uf[i] = uf[uf[i]];
            i = uf[i];
        }
        return i;
    }
    
    void connect(int p, int q) {
        int pid = root(p);
        int qid = root(q);
        uf[pid] = qid;
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        uf.resize(n);
        for (int i = 0; i < n; i++) {
            uf[i] = i;
        }
        
        for (auto edge : edges) {
            connect(edge[0], edge[1]);
        }
        
        // find different roots in uf
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(root(uf[i]));
        }
        
        return s.size();
    }
};


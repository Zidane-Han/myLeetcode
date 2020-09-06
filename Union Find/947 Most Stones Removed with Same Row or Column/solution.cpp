class Solution {
private:
    void makeUF(vector<int>& root) {
        root.resize(20000);
        for (int i = 0; i < root.size(); i++) {
            root[i] = i;
        }
    }
    
    int find(int i) {
        while (i != root[i]) {
            i = root[i];
        }
        return i;
    }
    
    void connect(int p, int q) {
        int pid = find(p);
        int qid = find(q);
        
        root[pid] = qid;
    }
    
public:
    vector<int> root;
    // res = points - disjointed set
    // row = index; col = index + 10000
    // union(row, col)
    int removeStones(vector<vector<int>>& stones) {
        makeUF(root);
        for (auto stone : stones) {
            connect(stone[0], stone[1]+10000);
        }
        
        // res = stones - sets
        set<int> nset;
        for (auto stone : stones) {
            nset.insert(find(stone[0]));
        }
        
        return stones.size() - nset.size();
    }
};
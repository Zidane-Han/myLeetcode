class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        // corner cases
        if (n == 1 && find(seqs.begin(), seqs.end(), org) == seqs.end()) {
            return false;
        } 
        
        unordered_map<int, unordered_set<int>> g;   // adj list
        vector<int> degree(n+1, 0); // out degree
        int cnt = 0; // num of nodes' degree larger than 0
        // build graph
        for (auto seq : seqs) {
            for (int i = seq.size() - 1; i >= 0; i--) {
                if (seq[i] < 0 || seq[i] > n)   return false;
                
                if (i > 0 && g[seq[i]].count(seq[i-1]) == 0) {
                    g[seq[i]].insert(seq[i-1]);
                    if (degree[seq[i-1]]++ == 0) {
                        cnt++;
                    }
                }   
            }
        }

        if (cnt != n-1) return false;
        for (int i = n-1; i >= 0; i--) {
            if (degree[org[i]] > 0) return false;
            for (auto p : g[org[i]]) {
                degree[p]--;
                if (degree[p] == 0 && p != org[i-1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
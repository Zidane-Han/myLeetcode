class Solution {
private:
    void connect(int p, int q, vector<int>& uf) {
        int pid = root(p, uf);
        int qid = root(q, uf);
        uf[pid] = qid;
        return;
    }
    
    int root(int i, vector<int>& uf) {
        while (i != uf[i]) {
            uf[i] = uf[uf[i]];
            i = uf[i];
        }
        return i;
    }
    
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        // Kruskal algorithm
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto connection : connections) {
            pq.push({connection[2], connection[0], connection[1]});
        }
        
        // make-set
        vector<int> uf(N+1, 0);
        for (int i = 1; i < N+1; i++) {
            uf[i] = i;
        }
        
        int cost = 0;
        int nedge = 0;
        while (!pq.empty()) {
            auto currt = pq.top();  pq.pop();
            int c = currt[0];
            int u = currt[1];
            int v = currt[2];
            if (root(u, uf) != root(v, uf)) {
                connect(u, v, uf);
                cost += c;
                nedge++;
            }
        }
        
        return (nedge == N-1) ? cost : -1;        
    }
};
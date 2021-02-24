class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // adj list
        typedef pair<int, double> pid;
        vector<vector<pid>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        
        // prob results
        vector<double> probs(n, 0);
        probs[start] = 1;
        // priority_queue
        priority_queue<pair<double, int> > pq;
        pq.push({1, start});
        // visited
        vector<bool> visited(n, false);
        
        while (!pq.empty()) {
            auto currt = pq.top();   pq.pop();
            double prob = currt.first;
            int u = currt.second;
            
            if (visited[u]) {
                continue;
            } else {
                visited[u] = true;
            }
            
            for (auto v : graph[u]) {
                if (prob * v.second > probs[v.first]) {
                    probs[v.first] = prob * v.second;
                    if (v.first != end) {
                        pq.push({probs[v.first], v.first});
                    }
                }
            }
            
        }
        
        return probs[end];
    }
};


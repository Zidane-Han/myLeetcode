class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // bfs
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in_degree(numCourses, 0);
        queue<int> q = {};
        vector<int> res = {};
        
        for (auto pair : prerequisites) {
            graph[pair[1]].push_back(pair[0]);
            in_degree[pair[0]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }
        
        while (!q.empty()) {
            int currt = q.front();
            q.pop();
            
            for (int k : graph[currt]) {
                in_degree[k]--;
                if (in_degree[k] == 0) {
                    q.push(k);
                    res.push_back(k);
                }
            }
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] != 0)  return {};
        }
        
        return res;
    }
};
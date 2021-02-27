class Solution {
private:
    vector<vector<int>> res;
    
    void dfs(vector<vector<int>>& graph, vector<bool>& v, int currt, int dst, vector<int> path) {
        path.push_back(currt);
        if (currt == dst) {
            res.push_back(path);
            return;
        } 
        
        v[currt] = true;
        for (int node : graph[currt]) {
            dfs(graph, v, node, dst, path);
        }
        v[currt] = false;
        return;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // dfs
        int n = graph.size();
        // visited
        vector<bool> v(n, false);
        vector<int> path = {};
        dfs(graph, v, 0, n-1, path);
        
        return res;
    }
};
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int currt, int dst) {
        if (currt == dst)   return true;
        if (graph[currt].empty() || visited[currt])   return false;
        visited[currt] = true;
        
        for (int v : graph[currt]) {
            if (!dfs(graph, visited, v, dst)) {
                return false;
            }
        }
        visited[currt] = false;
        return true;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        // dfs
        // construct graph
        vector<vector<int>> graph(n, vector<int>());
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        if (!graph[destination].empty())  return false;   // dst without outgoing
        
        // visited
        vector<bool> visited(n, false);
        
        return dfs(graph, visited, source, destination);
    }
};
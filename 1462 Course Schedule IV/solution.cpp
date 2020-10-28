class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visit, int currt, int target) {
        if (visit[currt]) {
            return false;
        } else {
            visit[currt] = true;
        }
        
        if (currt == target)    return true;
        for (int course : graph[currt]) {
            if (dfs(graph, visit, course, target))  return true;
        }
        return false;
    }
    
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto courses : prerequisites) {
            graph[courses[0]].push_back(courses[1]);
        }
        
        vector<bool> ans = {};
        for (auto query : queries) {
            vector<bool> visit(n, false);
            ans.push_back(dfs(graph, visit, query[0], query[1]));
        }
        
        return ans;
    }
};
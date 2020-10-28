class Solution {
private:
    vector<vector<int>> memo;

    bool dfs(vector<vector<int>>& graph, int currt, int target) {
        if (currt == target) {
            memo[currt][target] = 1;
            return true;
        } 

        if (memo[currt][target] != -1) {
            return memo[currt][target];
        }  

        for (int course : graph[currt]) {
            if (dfs(graph, course, target)) {
                memo[course][target] = 1;
                return true;
            }  
        }

        memo[currt][target] = 0;
        return false;
    }
    
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto courses : prerequisites) {
            graph[courses[0]].push_back(courses[1]);
        }
        
        vector<bool> ans = {};
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        for (auto& query : queries) {
            vector<bool> visit(n, false);
            ans.push_back(dfs(graph, query[0], query[1]));
        }
        
        return ans;
    }
};
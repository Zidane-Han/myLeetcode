/*
 *
 * [207] Course Schedule
 */

class Solution {
private:
    bool canFinishDFS(vector<vector<int>>& graph, vector<int>& visit, int node) {
        if (visit[node] == 1)   return true;
        if (visit[node] == -1)   return false;
        
        visit[node] = -1;
        for (auto n : graph[node]) {
            if (!canFinishDFS(graph, visit, n))    return false;
        }
        visit[node] = 1;
        
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // whether cycle exists
        // 0: not visited   1: no confliction  -1: confliction
        // A's dfs traverse will not meet A again.
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<int> visit(numCourses, 0);

        for (auto courses : prerequisites) {
            graph[courses[1]].push_back(courses[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!canFinishDFS(graph, visit, i))    return false;
        }

        return true;
    }
};
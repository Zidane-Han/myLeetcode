class Solution {
private:
    unordered_set<char> chars;  // all chars
    unordered_map<char, unordered_set<char>> g; // graph
    
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        // find all chars
        for (string word : words) {
            chars.insert(word.begin(), word.end());
        }
        
        // build graph
        for (int i = 0; i+1 < n; i++) {
            string currt = words[i];
            string next = words[i+1];
            int k;
            for (k = 0; k < currt.size(); k++) {
                if (currt[k] != next[k]) {
                    g[currt[k]].insert(next[k]);
                    break;
                }
            }
            
            if (k == min(currt.size(), next.size()) && currt.size() > next.size()) {
                return "";
            }
        }
        
        // calc degree
        vector<int> indegree(128, 0);
        for (auto ele : g) {
            for (char ch : ele.second) {
                indegree[ch]++;
            }
        }
        
        // find the char with 0 deg as start point
        queue<char> q;
        for (char ch : chars) {
            if (indegree[ch] == 0) {
                q.push(ch);
            }
        }
        
        // bfs
        string res = "";
        while (!q.empty()) {
            char currt = q.front(); q.pop();
            res += currt;
            for (auto node : g[currt]) {
                if (--indegree[node] == 0) {
                    q.push(node);
                }
            }
        }

        return (res.size() == chars.size()) ? res: "";
    }
};
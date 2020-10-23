class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        
        unordered_map<int, vector<int>> numtable;
        for (int i = 0; i < arr.size(); i++) {
            numtable[arr[i]].push_back(i);
        }
        
        vector<bool> visited(len, false);
        queue<int> q = {};  // index
        
        q.push(0);
        visited[0] = true;
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int currt = q.front();
                q.pop();

                if (currt == len -1) {
                    return res;
                }

                if (currt-1 >= 0 && !visited[currt-1]) {
                    q.push(currt-1);
                    visited[currt-1] = true;
                }

                if (currt+1 < len && !visited[currt+1]) {
                    q.push(currt+1);
                    visited[currt+1] = true;
                }
                
                //
                auto it = numtable.find(arr[currt]);
                if (it == numtable.end()) {
                    continue;
                }
                
                for (auto ele : numtable[arr[currt]]) {
                    if (visited[ele]) {
                        continue;
                    }
                    q.push(ele);
                    visited[ele] = true;
                }       
                
                numtable.erase(it);
            }
            
            res++;
        }
        
        return -1;
    }
};
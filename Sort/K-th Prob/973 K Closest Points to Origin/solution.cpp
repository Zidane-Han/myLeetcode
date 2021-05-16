class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<int>> m;  // dist, indexes
        for (int i = 0; i < points.size(); i++) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            m[dist].push_back(i);
        }
        
        vector<vector<int>> res = {};
        
        map<int, vector<int>>::iterator it = m.begin();
        
        while (k) {
            for (int ind : it->second) {
                res.push_back(points[ind]);
                k--;
            }
            it++;
        }
            
        return res;
    }
};
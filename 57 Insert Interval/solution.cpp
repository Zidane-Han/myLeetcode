class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
        newInterval = [a, b]; interval = [i0, i1];
        1) a > i1 or b < i0, next one;
        2) i0 <= a,b <= i1, update l&r 
        */
        vector<vector<int>> res = {};
        int a = newInterval[0];
        int b = newInterval[1];
        int n = intervals.size();
        int i = 0;
        while (i < n && a > intervals[i][1]) {
            res.push_back(intervals[i]);
            i++;
        }
        
        // processing
        int l = a;
        int r = b;
        while ((i < n) && !(a > intervals[i][1] || b < intervals[i][0])) {
            l = min(l, intervals[i][0]);
            r = max(r, intervals[i][1]);
            i++;
        }
        res.push_back({l, r});
        
        // elses
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};
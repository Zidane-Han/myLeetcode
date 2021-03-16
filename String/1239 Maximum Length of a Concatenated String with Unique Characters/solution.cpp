class Solution {
public:
    int maxLength(vector<string>& arr) {
        // brute force
        vector<string> v = {};
        
        for (string s : arr) {
            // check s is valid
            set<char> tmp(s.begin(), s.end());
            if (tmp.size() != s.size()) continue;
            int vsize = v.size();
            for (int i = 0; i < vsize; i++) {
                // combination == sum of individual
                set<char> cmb = {};
                cmb.insert(s.begin(), s.end());
                cmb.insert(v[i].begin(), v[i].end());
                if (cmb.size() == s.size() + v[i].size()) {
                    v.push_back(v[i]+s);
                }
            }
            v.push_back(s);
        }
        
        int res = 0;
        for (string s : v) {
            res = max(res, (int)s.size());
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s = {};
        s.insert(vector<int>());

        for (int num : nums) {
            set<vector<int>> tmp = {};
            // vector<int> vectmp = {};
            for (auto it = s.begin(); it != s.end(); it++) {
                vector<int> vectmp(*it);
                vectmp.push_back(num);
                tmp.insert(vectmp);
            }
            s.merge(tmp);
        }

        vector<vector<int>> res = {};
        for (auto it = s.begin(); it != s.end(); it++) {
            res.push_back(*it);
        }

        return res;
    }
};
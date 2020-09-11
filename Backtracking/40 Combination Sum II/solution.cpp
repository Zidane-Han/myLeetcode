class Solution {
public:
    void helper(vector<int>& cand, int target, vector<int>& comb, vector<vector<int>>& res, int pos) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        
        for (int i = pos; i < cand.size(); i++) {
            // to avoid duplicate
            if (i > pos && cand[i] == cand[i-1])    continue;
            comb.push_back(cand[i]);
            helper(cand, target-cand[i], comb, res, i+1);
            comb.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res = {};
        vector<int> comb = {};
        sort(candidates.begin(), candidates.end());
        
        helper(candidates, target, comb, res, 0);
        
        return res;
    }
};
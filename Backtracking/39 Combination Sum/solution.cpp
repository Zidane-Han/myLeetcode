class Solution {
private:
    void helper(vector<int>& cand, int target, vector<vector<int>>& res, vector<int>& comb, int pos) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        
        for (int i = pos; cand[i]<=target && i<cand.size(); i++) {
            comb.push_back(cand[i]);
            helper(cand, target-cand[i], res, comb, i);
            comb.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vec;
        vector<int> comb;
        
        helper(candidates, target, vec, comb, 0);
        
        return vec;
    }
};
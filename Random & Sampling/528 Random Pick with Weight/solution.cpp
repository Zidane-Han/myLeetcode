class Solution {
private:
    vector<int> sum;
    
public:
    Solution(vector<int>& w) {
        int temp = 0;
        for (int k = 0; k < w.size(); ++k) {
            temp += w[k];
            sum.push_back(temp);
        }
    }
    
    int pickIndex() {
        int k = rand() % sum.back();
        auto it = upper_bound(sum.begin(), sum.end(), k);
        return it - sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
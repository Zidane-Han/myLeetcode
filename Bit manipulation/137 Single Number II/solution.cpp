class Solution {
private:
    void AddNum(int num, vector<int>& sum) {
        for (int i = 0; i < 32; i++) {
            sum[i] += (num >> i) & 1;
        }
        
        return;
    }
    
    
public:
    int singleNumber(vector<int>& nums) {
        vector<int> sum(32, 0);
        for (int num : nums) {
            AddNum(num, sum);
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res |= (sum[i] % 3) << i;
        }
        
        return res;
    }
};
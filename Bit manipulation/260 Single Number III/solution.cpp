class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorsum = 0;
        for (int num : nums) {
            xorsum ^= num;
        }
        
        xorsum &= -xorsum;
        
        int type1 = 0;
        int type2 = 0;
        for (int num : nums) {
            if (num & xorsum) {
                type1 ^= num;
            } else {
                type2 ^= num;
            }
                
        }
        
        return {type1, type2};
    }
};
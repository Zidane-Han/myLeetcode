class Solution {
public:
    
    int SquareSum(int n) {
        int Sum = 0;
        int remaind = n;
        
        while (remaind != 0) {
            Sum += (remaind % 10) * (remaind % 10);
            remaind = remaind / 10;
        }
        
        return Sum;
    }
    
    bool isHappy(int n) {
        set<int> vals = {};
        int val = n;
        while (vals.find(val) == vals.end()){
            if (val == 1) return true;
            else {
                vals.insert(val);
                val = SquareSum(val);
            }
        }
        
        return false;
        
    }
};

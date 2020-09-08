class Solution {
public:
    bool isUgly(int num, set<int>& dp) {
        if (num%2 == 0 && count(dp.begin(), dp.end(), num/2) > 0)  return true;
        if (num%3 == 0 && count(dp.begin(), dp.end(), num/3) > 0)  return true;
        if (num%5 == 0 && count(dp.begin(), dp.end(), num/5) > 0)  return true;
        return false;
    }
    
    int nthUglyNumber(int n) {
        set<int> dp = {};
        
        int count = 1;  // number has been inserted
        int num = 1;
        dp.insert(num);
        
        while (count < n) {
            num++;
            if (isUgly(num, dp)) {
                dp.insert(num);
                count++;
            }
        }
        
        return num;
    }
};
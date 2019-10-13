class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        int remainder;
        
        for (long long i = 1; i <= n; i *= 10) {
            res += n/(10*i)*i;;
            
            remainder = (n%(10*i))/i;
            
            if (remainder == 0) { } 
            else if (remainder == 1) {
                res += n%i+1;    
            } else {
                res += i;
            }
            
        }
        
        return res;
    }
};
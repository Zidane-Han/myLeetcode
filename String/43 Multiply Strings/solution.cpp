/*
 *
 * [43] Multiply Strings
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")   return "0";
        
        int p1 = num1.size();
        int p2 = num2.size();
        
        vector<int> mul(p1+p2, 0);
        for (int i = p1-1; i >= 0; i--) {
            for (int j = p2-1; j >= 0; j--) {
                int val = (num1[i] - '0') * (num2[j] - '0');
                int sum = val + mul[i+j+1];
                mul[i+j+1] = sum % 10;
                mul[i+j] += sum / 10;
            }
        }
        
        string res = "";
        for (int k : mul) {
            if (res.empty() && k == 0) {
                continue;
            } else {
                res += to_string(k);
            }
        }
            
        return res;
    }
};
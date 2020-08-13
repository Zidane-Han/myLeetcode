/*
 *
 * [93] Restore IP Address
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res = {};
        
        restoreAddress(s, 0, "", res);
        
        return res;
    }
    
    void restoreAddress(string s, int nSeg, string tmp, vector<string>& res) {
        if (nSeg == 4) {
            if (s.empty()) res.push_back(tmp);
        } else {
            for (int k = 1; k <= 3; k++) {
                if (s.size() >= k && isValid(s.substr(0, k))) {
                    if (nSeg == 3) {
                        restoreAddress(s.substr(k), 4, tmp + s.substr(0,k), res);
                    } else {
                        restoreAddress(s.substr(k), nSeg+1, tmp + s.substr(0,k) + ".", res);
                    }
                }
            }    
        }
    }
    
    bool isValid(string substring) {
        int num = stoi(substring);
        return (num >= 0 && num <= 255 && (to_string(num).size()==substring.size()));
    }
};
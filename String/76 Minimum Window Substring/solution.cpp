class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        
        unordered_map<char, int> freq;
        for (char tt : t)   freq[tt]++;
        
        string res = "";
        int len = INT_MAX;
        int l = 0;
        int cnt = 0;    // how many of t have been matched
        for (int r = 0; r < s.size(); r++) {
            // right-expand
            if (freq.count(s[r]) > 0) {
                freq[s[r]]--;
                if (freq[s[r]] >= 0)    cnt++;
            } 
            while (cnt == t.size()) {
                if (len > r-l+1) {
                    //update
                    len = r-l+1;
                    res = s.substr(l, len);
                }
                // left-contract
                if (freq.count(s[l]) > 0) {
                    freq[s[l]]++;
                    if (freq[s[l]] > 0)    cnt--;
                }
                l++;
            }
        }
        
        return res;
    }
};
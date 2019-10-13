class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) {
            return "";
        }
        
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            int temp;
            temp = AroundLetter(s, i, i);
            // odd
            if (temp > end-start+1) {
                start = i - temp/2;
                end = i + temp/2;
            }
            
            temp = AroundLetter(s, i, i+1);
            // temp is even
            if (temp > end-start+1) {
                start = i - temp/2 + 1;
                end = i + temp/2;
            }
        }
        
        return s.substr(start, end-start+1);
    }
    
    int AroundLetter(string s, int head, int tail) {
        while (head >=0 && tail < s.length() && s[head] == s[tail]) {
            head--;
            tail++;
        }
        return tail-head-1;
    }
    
};
/*
 * [32] Longest Valid Parentheses
 */


class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        
        stack<int> st;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            
            if (s[i] == ')') {
                if (st.empty()) {
                    start = i + 1;
                } else {
                    st.pop();
                    if (st.empty()) {
                        res = max(res, i-start+1);    
                    } else {
                        res = max(res, i-st.top());
                    }
                    
                }
            }
        }
        
        return res;
    }
};
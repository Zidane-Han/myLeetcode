/*
 * [22] Generate Parentheses
 */


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = {};
        generateParenthesisHelper(n, n, "", res);
        return res;
    }
    
    // left & right for the number of paranthesis to be added
    void generateParenthesisHelper(int left, int right, string temp, vector<string>& res) {
        if (left > right)   return;
        if (left == 0 && right == 0) {
            res.push_back(temp);
        } else {
            if (left > 0) {
                generateParenthesisHelper(left-1, right, temp + '(', res);
            }
            
            if (right > 0) {
                generateParenthesisHelper(left, right-1, temp + ')', res);
            }
        }
    }
};
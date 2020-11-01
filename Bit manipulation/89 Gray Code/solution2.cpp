class Solution {
public:
    vector<int> grayCode(int n) {
        // iteration
        vector<int> res;
        int currt = 0;
        res.push_back(currt);
        unordered_set<int> s;
        s.insert(currt);
        
        while (res.size() != pow(2, n)) {
            for (int i = 0; i < n; i++) {
                int tmp = currt ^ (1 << i); // reverse of n-th bit from right
                if (s.count(tmp) == 0) {
                    s.insert(tmp);
                    res.push_back(tmp);
                    currt = tmp;
                    break;
                }
            }
        }
        
        return res;
    }
};
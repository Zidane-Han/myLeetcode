class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> s;
        s.insert(1);
        int count = 1;
        
        while (count < n) {
            auto it = s.begin();
            s.insert((*it)*2);
            s.insert((*it)*3);
            s.insert((*it)*5);
            s.erase(it);
            count++;
        }
        
        return *s.begin();
    }
};
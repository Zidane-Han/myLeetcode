class Solution {
public:
    string reorganizeString(string S) {
        int len = S.size();
        unordered_map<char, int> m;
        for (char ch : S) {
            m[ch]++;
        }
        
        priority_queue<pair<int, char> > pq; // (freq, char)
        for (auto mm : m) {
            if (mm.second > (len+1)/2)   return "";
            pq.push(make_pair(mm.second, mm.first));
        }
        
        string res = "";
        while (pq.size() > 1) {
            auto ele1 = pq.top(); pq.pop();
            auto ele2 = pq.top(); pq.pop();
            
            res += ele1.second;
            int freq1 = (--ele1.first);
            res += ele2.second;
            int freq2 = (--ele2.first);
            
            if (freq1)  pq.push(make_pair(freq1, ele1.second));
            if (freq2)  pq.push(make_pair(freq2, ele2.second));
        }
        
        if (!pq.empty()) {
            auto ele = pq.top();
            res += ele.second;
        }
            
        return res;
    }
};
class Solution {
public:
    struct myComp {
        bool operator() (const pair<int, string>& A, const pair<int, string>& B) {
            if (A.first != B.first) {
                return A.first > B.first;
            } else {
                return A.second < B.second;
            }
        }
    };
    

    vector<string> topKFrequent(vector<string>& words, int k) {
        // hash map
        unordered_map<string, int> freq;
        for (string word : words) freq[word]++;

        // heap
        priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;
        for (auto w : freq) {
            pq.push(make_pair(w.second, w.first));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> res;
        while (!pq.empty()) {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }
};


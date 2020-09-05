/*
 *
 * [692] Top K Frequent Words
 */

class Solution {
public:
    static bool Compare(pair<int, string> A, pair<int, string> B)
    {
        if (A.first != B.first) {
            return A.first > B.first;
        } else {
            return A.second < B.second;
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        // 1. sort by freq; 2. sort by char increasing
        unordered_map<string, int> freq;
        for (string word : words) freq[word]++;

        vector<pair<int, string>> vFreq;
        unordered_map<string, int>::iterator it;
        for (it = freq.begin(); it != freq.end(); it++) {
            vFreq.push_back({it->second, it->first});
        }

        // freq decreasing; alphabet increasing
        sort(vFreq.begin(), vFreq.end(), Compare);

        vector<string> res = {};
        for (int i = 0; i < k; i++) {
            auto tmp = vFreq[i];
            res.push_back(tmp.second);
        }
        
        return res;
    }
};


/*
 *
 * [30] Substring with Concatenation of All Words
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        
        int wordLen = words[0].size();
        int wordNum = words.size();

        unordered_map<string, int> wordCnt;
        for (auto word : words) {
            wordCnt[word]++;
        }

        vector<int> res = {};
        // the return type of vector.size() is unsigned int
        for (int i = 0; i <= (int)s.size() - wordLen * wordNum; i++) {
            unordered_map<string, int> strCnt;
            int j;
            for (j = 0; j < wordNum; j++) {
                string substring = s.substr(i+j*wordLen, wordLen);
                if (wordCnt.count(substring) == 0) break;
                strCnt[substring]++;
                if (strCnt[substring] > wordCnt[substring]) break;
            }

            if (j == wordNum) {
                res.push_back(i);
            }

        }

        return res;
    }
};
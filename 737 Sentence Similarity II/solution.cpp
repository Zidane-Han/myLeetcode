class Solution {
private:
    map<string, string> dict;

    void Union(string p, string q) {
        string pid = Find(p);
        string qid = Find(q);
        dict[pid] = qid;
        return;
    }
    
    string Find(string p) {
        // if not exist
        if (dict.find(p) == dict.end()) {
            dict[p] = p;
            return p;
        }
        
        while (p != dict[p]) {
            p = dict[p];
        }
        return p;
    }
    
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        for (auto p : pairs) {
            Union(p[0], p[1]);
        }
        
        for (int i = 0; i < words1.size(); i++) {
            if (Find(words1[i]) != Find(words2[i])) return false;
        }
        
        return true;
    }
};
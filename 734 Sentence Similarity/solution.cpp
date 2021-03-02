class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size())   return false;
        
        set<set<string>> sPair;
        for (auto p : similarPairs) {
            sPair.insert({p[0], p[1]});
        }
        
        for (int i = 0; i < sentence1.size(); i++) {
            set<string> s;
            s.insert({sentence1[i], sentence2[i]});
            
            if (sPair.count(s) || sentence1[i] == sentence2[i]) {
                continue;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
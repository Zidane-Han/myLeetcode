#include <map>
#include <set>

class Solution {
public:
    // Dynamic programming
    bool canCross(vector<int>& stones) {
        if(stones.size() <= 1) return false;
        if(stones[0] != 0 || stones[1] != 1) return false;
        
        map<int, set<int>> HashMap;
        for (int i = 1; i < stones.size(); i++) {
            HashMap[stones[i]] = {};
        }
        HashMap[1].insert(1);
        
        for (int j = 1; j < stones.size(); j++) {
            int index = stones[j];
            if (HashMap[index].size() == 0) {
                continue;
            }
            
            for (auto step : HashMap[index]) {
                for (int x = step-1; x <= step+1; x++) {
                    if (x < 0) {
                        continue;
                    }
                    
                    if (HashMap.find(index+x) != HashMap.end()) {
                        HashMap[index+x].insert(x);
                    }
                    
                }
            }
            
            
        }
        
        return (HashMap[stones.back()].size() != 0);
        
    }
};
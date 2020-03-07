class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        
        int res = 0;
        vector<int> monoq = {};
        for (int i = 0; i < heights.size(); i++) {
            if (monoq.empty() || heights[i] >= heights[monoq.back()]) {
                monoq.push_back(i);
            } else {
                // delete element to maintain monoq and update values
                int ele = monoq.back();
                monoq.pop_back();
                
                int len;
                if (monoq.empty()) {
                    len = i;
                } else {
                    len = i - monoq.back() - 1;
                }
                
                res = max(res, heights[ele]*len);
                i--;    // not move the position of the pointer
            }
        }
        
        return res;     
    }
};
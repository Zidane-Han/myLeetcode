class Solution {
public:
    unordered_set<int> st;
    bool canCross(vector<int>& stones) {
        if (stones[0] != 0 || stones[1] != 1) {
            return false;
        }
        st.insert(stones[0]);
        for (int i = 1; i < stones.size(); i++) {
            st.insert(stones[i]);
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }
        return can(1, 1, stones[stones.size() - 1]);
    }

    bool can(int pos, int k, int end) {
        if (pos + k <= end + 1 && pos + k >= end - 1) {
            return true;
        }
        if (st.find(pos + k + 1) != st.end() && can(pos + k + 1, k + 1, end)) {
            return true;
        }
        if (st.find(pos + k) != st.end() && can(pos + k, k, end)) {
            return true;
        }
        if (k > 1 && st.find(pos + k - 1) != st.end() && can(pos + k - 1, k - 1, end)) {
            return true;
        }

        return false;
    }
};
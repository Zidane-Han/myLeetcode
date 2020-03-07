// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int pt = 0;
        for (int i = 1; i<n; ++i){
            if (knows(pt, i)) pt = i;
        }

        for (int j = 0; j < n; ++j){
            if (pt == j) continue;

            if (knows(pt, j) || !knows(j, pt)){
                return -1;
            }
        }

        return pt;

    }
};
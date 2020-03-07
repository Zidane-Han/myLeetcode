class Solution {
public:
    int longestMountain(vector<int>& A) {
        // O(n)
        int res = 0;
        int len = A.size();

        if (len < 3) return res;

        int prev = 0;
        int ptr = 1;

        while(ptr < len) {
            // move ptr to second ladder
            while (ptr < len && A[ptr] <= A[ptr-1]) ptr++;

            prev = ptr-1;
            // uphill
            if (ptr < len && A[ptr] > A[ptr-1]) {
                while (ptr < len && A[ptr] > A[ptr-1]) ptr++; //ptr = peak+1

                // downhill
                if (ptr < len && A[ptr] < A[ptr-1]) {
                    while (ptr < len && A[ptr] < A[ptr-1]) ptr++;
                    res = max(res, ptr-prev);
                }

            }

        }

        return res;
    }
};
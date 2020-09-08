class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();
        
        int arr[lenA+1][lenB+1];
        // boundary condition
        for (int i = 0; i <= lenA; i++) arr[i][0] = 0;
        for (int j = 0; j <= lenB; j++) arr[0][j] = 0;
        // update
        for (int i = 1; i <= lenA; i++) {
            for (int j = 1; j <= lenB; j++) {
                if (A[i-1] == B[j-1]) {
                    arr[i][j] = arr[i-1][j-1] + 1; 
                } else {
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
                }
            }
        }
        return arr[lenA][lenB];
    }
};

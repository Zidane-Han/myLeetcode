class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<pair<int, int>>> mem(A.size(), vector<pair<int, int>>() );
        vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
        
        for (int m = 0; m < A.size(); m++) {
            for (int n = 0; n < A[0].size(); n++) {
                if (A[m][n] != 0) mem[m].push_back({n, A[m][n]});
            }
        }
        
        for (int m = 0; m < A.size(); m++) {
            for (int i = 0; i < mem[m].size(); i++) {
                int col = mem[m][i].first;
                int val = mem[m][i].second;
                
                for (int n = 0; n < B[0].size(); n++) {
                    result[m][n] += val * B[col][n];
                }
                
            }
        }
        
        return result;
    }
};

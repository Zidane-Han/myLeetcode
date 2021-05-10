class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // formula: Cnk = n!/(k!*(n-k)!)
        // C_n_(k-1) = n!/((k-1)!*(n-k+1)!)
        // so, Cnk / C_n_(k-1) = (n-k+1) / k
        vector<int> res(rowIndex+1, 1);
        for (int i = 1; i < rowIndex; i++) {
            res[i] = res[i-1] * (long long)(rowIndex-i+1) / i;
        }
        
        return res;
    }
};

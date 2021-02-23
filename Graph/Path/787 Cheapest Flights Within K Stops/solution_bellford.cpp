class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> prices(K+2, vector<int>(n, INT_MAX));
        
        for (int i = 0; i <= K+1; i++) {
            prices[i][src] = 0;
        }
        
        for (int i = 1; i <= K+1; i++) {
            for (auto flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                
                if (prices[i-1][u] != INT_MAX) {
                    // RELAX
                    prices[i][v] = min(prices[i][v], prices[i-1][u] + w);
                }
            }
        }
        
        return (prices[K+1][dst] == INT_MAX) ? -1 : prices[K+1][dst];
    }
};


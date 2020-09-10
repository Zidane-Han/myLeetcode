class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long> > pq;
        pq.push(1);
        
        for (int i = 1; i < n; i++) {
            long t = pq.top();
            pq.pop();
            while(!pq.empty() && pq.top() == t) {
                pq.pop();
            }
            
            for (int prime : primes) {
                pq.push(t * prime);
            }
        }
        
        return pq.top();
        
    }
};
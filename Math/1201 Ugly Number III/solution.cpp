class Solution {
private:
    long lcm_ab;
    long lcm_ac;
    long lcm_bc;
    long lcm_abc;
    
    // least common multiple
    long nUglyInRange(int x, int a, int b, int c) {
        return x/a + x/b + x/c - x/lcm_ab - x/lcm_ac - x/lcm_bc + x/lcm_abc;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        lcm_ab = lcm<long>(a, b);
        lcm_ac = lcm<long>(a, c);
        lcm_bc = lcm<long>(b, c);
        lcm_abc = lcm<long>(a, lcm_bc);
        
        int time = 1;
        while (true) {
            if (nUglyInRange(n*time, a, b, c) < n)  time++;
            else break;
        }

        // [(time-1)*n, time*n]
        long left = n * (time-1);
        long right = n * time;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (nUglyInRange(mid, a, b, c) < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;

    }
};
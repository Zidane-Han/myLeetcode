// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a; 
        int b;
        int x = 99;
        
        while (x > 40) {
            a = rand7();
            b = rand7();
            x = 7*(a-1) + b;
            
            if (x <= 40) {
                x = 1 + (x-1) % 10;
            }
        }
        
        return x;
        
    }
};
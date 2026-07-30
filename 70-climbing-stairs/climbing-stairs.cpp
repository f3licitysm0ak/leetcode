class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } 

        int one_before = 1;
        int two_before = 0;
        int sum = 0;

        for(int i = 1; i <= n; i++) {
            sum = one_before + two_before;
            two_before = one_before;
            one_before = sum;
        }

        return sum;
        
    }
};
class Solution {
public:
    int climbStairs(int n) {
        // base cases
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;


        int one_step_before = 2;    // it work as prev. ptr of curr ptr
        int two_step_before = 1;    // it work as prev. of prev. ptr of curr ptr
        int all_ways = 0;

        for(int i = 2; i < n; i++) {

            all_ways = one_step_before + two_step_before;
            two_step_before = one_step_before;
            one_step_before = all_ways;
        }

        return all_ways;
    }
};

// Q. is similiar to Fibonacci

// #LeetCode Easy Way
// T.C = O(N) , S.C = O(1)

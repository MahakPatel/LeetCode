class Solution {
public:
    // Recursive function with memoization to compute the number of ways to climb stairs
    int climbStairs(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] != -1) return memo[n];
        memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        return memo[n];
    }
    
    // Function to initiate the memoization approach
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1); // Initialize memoization array with -1
        return climbStairs(n, memo);
    }
};
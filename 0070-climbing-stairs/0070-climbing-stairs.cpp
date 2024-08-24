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


// ++++++++++++++++++ Bottom Up ++++++++++++++++++++++
    //     if (n <= 1) return 1;
        
    //     int prev2 = 1; // Number of ways to climb n-2 stairs
    //     int prev1 = 1; // Number of ways to climb n-1 stairs
        
    //     for (int i = 2; i <= n; ++i) {
    //         int current = prev1 + prev2; // Number of ways to climb i stairs
    //         prev2 = prev1; // Update prev2 to the previous step
    //         prev1 = current; // Update prev1 to the current step
    //     }
        
    //     return prev1;
    // }
    }
};
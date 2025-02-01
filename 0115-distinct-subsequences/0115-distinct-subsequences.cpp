class Solution {
public:
    // // ++++++++++++ Recursive Approach for Distinct Subsequences
    // ++++++++++++++
    // // Time Complexity: O(2^n) (Exponential)
    // // Space Complexity: O(n) (Recursive stack depth)

    // int f(int n, int m, string s, string t) {
    //     if (m == 0)
    //         return 1; // If t is completely matched, one valid subsequence is
    //                   // found
    //     if (n == 0)
    //         return 0; // If s is exhausted and t is not matched, no
    //         subsequence
    //                   // exists

    //     if (s[n - 1] == t[m - 1]) {
    //         // If characters match, we have two choices:
    //         // 1. Include the character in the match (move both indices back)
    //         // 2. Skip the character in 's' and try to match 't' elsewhere
    //         return f(n - 1, m - 1, s, t) + f(n - 1, m, s, t);
    //     }

    //     // If characters don't match, skip the current character of 's'
    //     return f(n - 1, m, s, t);
    // }

    // int numDistinct(string s, string t) {
    //     int n = s.length();
    //     int m = t.length();

    //     return f(n, m, s, t);
    // }

    // // ++++++++++++ Memoization Approach ++++++++++++++++
    // // Time Complexity: O(n *m)
    // // Space Complexity: O(n * m +(n+m)) (Recursive stack depth)
    // int f(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
    //     if (m == 0)
    //         return 1; // If t is fully matched, one valid subsequence is
    //         found
    //     if (n == 0)
    //         return 0; // If s is exhausted and t is not matched, return 0

    //     if (dp[n][m] != -1)
    //         return dp[n][m]; // Memoization check

    //     if (s[n - 1] == t[m - 1]) {
    //         return dp[n][m] = f(n - 1, m - 1, s, t, dp) + f(n - 1, m, s, t,
    //         dp);
    //     }

    //     return dp[n][m] = f(n - 1, m, s, t, dp);
    // }

    // int numDistinct(string s, string t) {
    //     int n = s.length(), m = t.length();
    //     vector<vector<int>> dp(n + 1,
    //                            vector<int>(m + 1, -1)); // Initialize DP
    //                            table
    //     return f(n, m, s, t, dp); // Start from n, m (1-based indexing)
    // }

    // // // ++++++++++++ Tabulation Approach ++++++++++++++++
    // // // Time Complexity: O(n *m)
    // // // Space Complexity: O(n * m))
    // int numDistinct(string s, string t) {
    //     int n = s.length(), m = t.length();
    //     vector<vector<int>> dp(n + 1,
    //                            vector<int>(m + 1, 0)); // Initialize DP table

    //     // Base case: An empty `s` can match an empty `t` in one way
    //     dp[0][0] = 1;

    //     // If `t` is empty, there's always one way to match (by deleting all
    //     // characters)
    //     for (int i = 1; i <= n; i++) {
    //         dp[i][0] = 1;
    //     }

    //     // If `s` is empty but `t` is not, it can't match (`dp[0][j]` remains
    //     0)

    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= m; j++) {
    //             if (s[i - 1] == t[j - 1]) {
    //                 // Either take the current character or skip it
    //                 dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    //             } else {
    //                 // Skip current character in `s`
    //                 dp[i][j] = dp[i - 1][j];
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<long long> prev(m + 1, 0),
            cur(m + 1, 0); // Use long long to prevent overflow

        // Base case: An empty `t` is always a subsequence of any prefix of `s`
        prev[0] = 1;

        // Compute DP table using space-optimized approach
        for (int i = 1; i <= n; i++) {
            cur[0] = 1; // Reset cur[0] for each new row

            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    cur[j] = prev[j - 1] +
                             prev[j]; // Use long long to avoid overflow
                } else {
                    cur[j] = prev[j];
                }
            }

            prev = cur; // Move current row to previous for the next iteration
        }

        return static_cast<int>(prev[m]); // Cast result back to int
    }
};
class Solution {
public:
    // // +++++++++++++++++ Recursive ++++++++++++++++++++++++
    // // TC : O(2^(n*m))
    // // SC : O(n*m)
    // bool f(int n, int m, string s, string p) {
    //     // If both strings are exhausted, return true (successful match)
    //     if (n < 0 && m < 0)
    //         return true;

    //     // If only pattern is left and s is exhausted, check if pattern
    //     consists
    //     // only of '*'
    //     if (n < 0) {
    //         for (int i = 0; i <= m; i++) {
    //             if (p[i] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }

    //     // If pattern is exhausted but s is not, return false
    //     if (m < 0)
    //         return false;

    //     // If current characters match or pattern has '?', move both pointers
    //     if (s[n] == p[m] || p[m] == '?')
    //         return f(n - 1, m - 1, s, p);

    //     // If pattern has '*', we have two choices:
    //     // 1. Ignore '*' and move to the next pattern character (m - 1)
    //     // 2. Consider '*' as a match for the current s character and move s
    //     // pointer (n - 1)
    //     if (p[m] == '*')
    //         return f(n - 1, m, s, p) || f(n, m - 1, s, p);

    //     // If no conditions match, return false
    //     return false;
    // }

    // bool isMatch(string s, string p) {
    //     int n = s.length();
    //     int m = p.length(); // Fixed this line

    //     return f(n - 1, m - 1, s, p);
    // }

    // +++++++++++++++++ Memoization ++++++++++++++++++++++++
    // TC : O(n*m)
    // SC : O(n*m + (n+m))
    // bool f(int n, int m, string& s, string& p, vector<vector<int>>& dp) {
    //     // Base case: If both strings are exhausted, return true (successful
    //     // match)
    //     if (n == 0 && m == 0)
    //         return true;

    //     // If pattern is left but string is exhausted, check if pattern
    //     consists
    //     // only of '*'
    //     if (n == 0) {
    //         for (int i = 1; i <= m; i++) {
    //             if (p[i - 1] != '*') // Adjusted indexing
    //                 return false;
    //         }
    //         return true;
    //     }

    //     // If string is left but pattern is exhausted, return false
    //     if (m == 0)
    //         return false;

    //     if (dp[n][m] != -1)
    //         return dp[n][m];

    //     // If current characters match or pattern has '?', move both pointers
    //     if (s[n - 1] == p[m - 1] || p[m - 1] == '?')
    //         return dp[n][m] = f(n - 1, m - 1, s, p, dp);

    //     // If pattern has '*', we have two choices:
    //     // 1. Ignore '*' and move to the next pattern character (m - 1)
    //     // 2. Consider '*' as a match for the current s character and move s
    //     // pointer (n - 1)
    //     if (p[m - 1] == '*')
    //         return dp[n][m] = f(n - 1, m, s, p, dp) || f(n, m - 1, s, p, dp);

    //     // If no conditions match, return false
    //     return dp[n][m] = false;
    // }

    // bool isMatch(string s, string p) {
    //     int n = s.length();
    //     int m = p.length();

    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    //     return f(n, m, s, p, dp); // Start from full length (1-based index)
    // }
    // ++++++++++++++++++ Tabulation ++++++++++++++++++++++++
    // TC O(n*m)
    // SC O(n*m)
    // bool isMatch(string s, string p) {
    //     int n = s.length();
    //     int m = p.length();

    //     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    //     // Base Case: Both strings are empty
    //     dp[0][0] = true;

    //     // If `s` is empty (`n == 0`), `p` should only contain '*' to be a
    //     valid
    //     // match
    //     for (int j = 1; j <= m; j++) {
    //         if (p[j - 1] == '*')
    //             dp[0][j] = dp[0][j - 1]; // '*' can match an empty string
    //     }

    //     // Filling the DP table
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= m; j++) {
    //             if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
    //                 dp[i][j] = dp[i - 1][j - 1]; // Character match or '?'
    //             } else if (p[j - 1] == '*') {
    //                 dp[i][j] =
    //                     dp[i - 1][j] ||
    //                     dp[i]
    //                       [j - 1]; // '*' acts as empty or matches one
    //                       character
    //             }
    //         }
    //     }

    //     return dp[n][m]; // Final result
    // }
    // ++++++++++++++++++ Space Optimization ++++++++++++++++++++++++
    // TC O(n*m)
    // SC O(n)
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<bool> prev(m + 1, false), cur(m + 1, false);

        // Base Case: Both strings are empty
        prev[0] = true;

        // If `s` is empty (`n == 0`), `p` should only contain '*' to be a valid
        // match
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1]; // '*' can match an empty string
        }

        // Filling the DP table
        for (int i = 1; i <= n; i++) {
            cur[0] =
                false; // If `s` is non-empty but `p` is empty, it can't match

            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    cur[j] = prev[j - 1]; // Character match or '?'
                } else if (p[j - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1]; // '*' acts as empty or
                                                    // matches one character
                } else {
                    cur[j] = false; // Mismatch
                }
            }

            prev = cur; // Move to the next row
        }

        return prev[m]; // Final result
    }
};
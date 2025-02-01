class Solution {
public:
    // // ++++++++++++++ Recursive ++++++++++++++++++++
    // // TC = O(3^n)
    // // SC = O(n+m)
    // int f(int n, int m, string s1, string s2) {
    //     if (n == 0)
    //         return m; // If s1 is empty, we need m insertions to match s2
    //     if (m == 0)
    //         return n; // If s2 is empty, we need n deletions to match s1

    //     if (s1[n - 1] == s2[m - 1])
    //         return f(n - 1, m - 1, s1,
    //                  s2); // No operation needed if the characters match

    //     // If characters do not match, we calculate the minimum of:
    //     // 1. Insertion (add character to s1)
    //     // 2. Deletion (remove character from s1)
    //     // 3. Replace (replace character in s1 to match s2)
    //     return 1 + min({f(n, m - 1, s1, s2),       // for insert
    //                     f(n - 1, m, s1, s2),       // for delete
    //                     f(n - 1, m - 1, s1, s2)}); // for replace
    // }

    // int minDistance(string word1, string word2) {
    //     int n = word1.length();
    //     int m = word2.length();

    //     return f(n, m, word1, word2);
    // }

    // ++++++++++++++ Memoization ++++++++++++++++++++
    // TC = O(n*m)
    // SC = O((n*m) + (n+m))

    // Helper function for Memoization approach
    // int f(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    //     // Base cases:
    //     // If s1 is empty, we need m insertions to make s1 equal to s2
    //     if (n == 0)
    //         return m;

    //     // If s2 is empty, we need n deletions to make s1 equal to s2
    //     if (m == 0)
    //         return n;

    //     // If the result has already been computed, return the stored value
    //     if (dp[n][m] != -1)
    //         return dp[n][m];

    //     // If characters at the current positions match, no operation is
    //     needed if (s1[n - 1] == s2[m - 1])
    //         return dp[n][m] =
    //                    f(n - 1, m - 1, s1, s2,
    //                      dp); // No operation needed if the characters match

    //     // If characters do not match, calculate the minimum operations for:
    //     // 1. Insertion (add character to s1)
    //     // 2. Deletion (remove character from s1)
    //     // 3. Replace (replace character in s1 to match s2)
    //     return dp[n][m] = 1 + min({f(n, m - 1, s1, s2, dp),       // for
    //     insert
    //                                f(n - 1, m, s1, s2, dp),       // for
    //                                delete f(n - 1, m - 1, s1, s2, dp)}); //
    //                                for replace
    // }

    // // Main function to calculate the minimum distance
    // int minDistance(string word1, string word2) {
    //     int n = word1.length();
    //     int m = word2.length();

    //     // Create the dp table and initialize with -1 (indicating uncomputed
    //     // states)
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    //     // Call the helper function with the full length of both words
    //     return f(n, m, word1, word2, dp);
    // }

    // // ++++++++++++++ Tabulation ++++++++++++++++++++
    // // TC = O(n*m)
    // // SC = O((n*m))
    // // Main function to calculate the minimum distance
    // int minDistance(string s1, string s2) {
    //     int n = s1.length(); // Length of the first string
    //     int m = s2.length(); // Length of the second string

    //     // Create the dp table and initialize with 0
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //     // Initialize the first column: if s2 is empty, we need i deletions
    //     for (int i = 0; i <= n; i++) { // Notice i <= n
    //         dp[i][0] = i;
    //     }

    //     // Initialize the first row: if s1 is empty, we need j insertions
    //     for (int j = 0; j <= m; j++) { // Notice j <= m
    //         dp[0][j] = j;
    //     }

    //     // Build the dp table starting from dp[1][1]
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= m; j++) {
    //             // If characters match, no operation is needed, so we carry
    //             the
    //             // previous value
    //             if (s1[i - 1] == s2[j - 1]) {
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             } else {
    //                 // If characters do not match, compute the minimum
    //                 // operations:
    //                 // 1. Insertion: Add a character from s2 into s1
    //                 // 2. Deletion: Remove a character from s1
    //                 // 3. Replace: Replace the current character of s1 with
    //                 that
    //                 // of s2
    //                 dp[i][j] = 1 + min({dp[i][j - 1],       // Insert
    //                 operation
    //                                     dp[i - 1][j],       // Delete
    //                                     operation dp[i - 1][j - 1]}); //
    //                                     Replace operation
    //             }
    //         }
    //     }

    //     // Return the minimum number of operations to convert the entire s1
    //     to
    //     // s2
    //     return dp[n][m];
    // }

    // ++++++++++++++ Space Optimization ++++++++++++++++++++
    // TC = O(n*m)
    // SC = O((n))
    // Main function to calculate the minimum distance
    int minDistance(string s1, string s2) {
        int n = s1.length(); // Length of the first string
        int m = s2.length(); // Length of the second string

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // Initialize the first row: if s1 is empty, we need j insertions
        for (int j = 0; j <= m; j++) {
            prev[j] = j; // Base case: s1 is empty, so we need j insertions to
                         // match s2
        }

        // Build the dp table starting from dp[1][1]
        for (int i = 1; i <= n; i++) { // Start from i = 1, not 0
            cur[0] =
                i; // Base case: s2 is empty, so we need i deletions to match s1

            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    cur[j] =
                        prev[j - 1]; // No operation needed if characters match
                } else {
                    // Compute minimum operations:
                    // 1. Insertion: cur[j - 1] + 1
                    // 2. Deletion: prev[j] + 1
                    // 3. Replace: prev[j - 1] + 1
                    cur[j] = 1 + min({cur[j - 1],    // Insert operation
                                      prev[j],       // Delete operation
                                      prev[j - 1]}); // Replace operation
                }
            }
            prev = cur; // Move current row to previous for the next iteration
        }

        // Return the minimum number of operations to convert the entire s1 to
        // s2
        return prev[m]; // The last element of prev contains the result
    }
};

class Solution {
public:
    // +++++++++++++ Space Optimization +++++++++++ TC O(n^2).  SC O(n)
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        // DP arrays to store previous and current row values
        vector<int> prev(m + 1, 0), cur(m + 1, 0); // Store only two rows

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    cur[j] = 1 + prev[j - 1]; // Move diagonally
                } else {
                    cur[j] =
                        max(prev[j],
                            cur[j - 1]); // Take max of excluding characters
                }
            }
            prev = cur; // Move current row to previous for the next iteration
        }

        return prev[m]; // The last element contains the answer
    }

    // // ++++++++++++ Tabulation ++++++++++++++ TC O(n*m)  SC O(n*m)
    // int longestCommonSubsequence(string text1, string text2) {
    //     int index1 = text1.size(), index2 = text2.size();
    //     vector<vector<int>> dp(index1 + 1,
    //                            vector<int>(index2 + 1, 0)); // Initialize with 0

    //         // Build the DP table iteratively
    //         for (int i = 1; i <= index1; i++) {
    //         for (int j = 1; j <= index2; j++) {
    //             if (text1[i - 1] == text2[j - 1]) {
    //                 // Characters match, move diagonally
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             } else {
    //                 // Characters don't match, take the max of excluding either
    //                     // character
    //                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }

    //     return dp[index1][index2]; // The last cell contains the answer
    // }
    int longestPalindromeSubseq(string s) {
        string s1 = s;

        reverse(s1.begin(),
                s1.end()); // Reverse the string to find LCS with itself

        return longestCommonSubsequence(
            s, s1); // LPS is the LCS of the string and its reverse
    }
};
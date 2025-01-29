class Solution {
public:
    // ++++++++++++++ Recursvive ++++++++++ TC O(2 ^ min(n,m)).  SC O(n*m)
    // int f(int index1, int index2, string& text1, string& text2) {
    //     // Base Case: If either string is exhausted, return 0
    //     if (index1 < 0 || index2 < 0) {
    //         return 0;
    //     }

    //     // If characters match, move diagonally and increase count
    //     if (text1[index1] == text2[index2]) {
    //         return 1 + f(index1 - 1, index2 - 1, text1, text2);
    //     }

    //     // If characters don't match, try both possibilities:
    //     // 1. Exclude the current character from text1
    //     // 2. Exclude the current character from text2
    //     return max(f(index1 - 1, index2, text1, text2),
    //                f(index1, index2 - 1, text1, text2)); // Fixed here
    // }

    // // Main function to compute LCS length
    // int longestCommonSubsequence(string text1, string text2) {
    //     int index1 = text1.size(), index2 = text2.size();
    //     return f(index1 - 1, index2 - 1, text1, text2);
    // }

    // ++++++++++++++ Memoization ++++++++++ TC O(n * m)).  SC O(n*m + n+m)
    // int f(int index1, int index2, string& text1, string& text2,
    //       vector<vector<int>>& dp) {
    //     // Base Case: If either index reaches 0, LCS length is 0
    //     if (index1 == 0 || index2 == 0) {
    //         return 0;
    //     }

    //     // If the result is already computed, return it
    //     if (dp[index1][index2] != -1)
    //         return dp[index1][index2];

    //     // If characters match, move diagonally and increase count
    //     if (text1[index1 - 1] ==
    //         text2[index2 - 1]) { // Adjust for 1-based indexing
    //         return dp[index1][index2] =
    //                    1 + f(index1 - 1, index2 - 1, text1, text2, dp);
    //     }

    //     // If characters don't match, take the maximum of excluding either
    //     // character
    //     return dp[index1][index2] =
    //                max(f(index1 - 1, index2, text1, text2, dp),
    //                    f(index1, index2 - 1, text1, text2, dp));
    // }

    // int longestCommonSubsequence(string text1, string text2) {
    //     int index1 = text1.size(), index2 = text2.size();

    //     // Fix: Use 1-based indexing (index1+1 and index2+1)
    //     vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, -1));

    //     return f(index1, index2, text1, text2, dp); // Start from 1-based
    //     index
    // }

    // ++++++++++++ Tabulation ++++++++++++++ TC O(n*m)  SC O(n*m)
    // int longestCommonSubsequence(string text1, string text2) {
    //     int index1 = text1.size(), index2 = text2.size();
    //     vector<vector<int>> dp(index1 + 1,
    //                            vector<int>(index2 + 1, 0)); // Initialize with 0

    //     // Build the DP table iteratively
    //     for (int i = 1; i <= index1; i++) {
    //         for (int j = 1; j <= index2; j++) {
    //             if (text1[i - 1] == text2[j - 1]) {
    //                 // Characters match, move diagonally
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             } else {
    //                 // Characters don't match, take the max of excluding either
    //                 // character
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }

    //     return dp[index1][index2]; // The last cell contains the answer
    // }
  // ++++++++++++ Space Optimization ++++++++++++++ TC O(n*m)  SC O(n)
    int longestCommonSubsequence(string text1, string text2) {
        int index1 = text1.size(), index2 = text2.size();
        vector<int> prev(index1+1,0),cur(index2+1,0); // create variable to store prev and cur value

        // Build the DP table iteratively
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // Characters match, move diagonally
                    cur[j] = 1 + prev[j - 1];
                } else {
                    // Characters don't match, take the max of excluding either
                    // character
                    cur[j] = max(prev[j], cur[j - 1]);
                }

                prev = cur; // make prev to cur
            }
        }

        return prev[index2]; // The last cell contains the answer
    }
};
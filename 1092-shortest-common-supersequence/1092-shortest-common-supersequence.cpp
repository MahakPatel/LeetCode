class Solution {
public:
    // ++++++++++++ Shortest Common Supersequence (SCS) ++++++++++++++
    // Time Complexity: O(n*m)
    // Space Complexity: O(n*m)

    string shortestCommonSupersequence(string s1, string s2) {
        int index1 = s1.size(), index2 = s2.size();

        // DP table to store LCS length
        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, 0));

        // Build the DP table for LCS
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] =
                        1 +
                        dp[i - 1][j - 1]; // Characters match, move diagonally
                } else {
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]); // Take max of excluding either character
                }
            }
        }

        // If only length of SCS is required:
        // return index1 + index2 - dp[index1][index2];

        string ans = ""; // Stores the final SCS

        int i = index1, j = index2;

        // Construct the Shortest Common Supersequence
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1]; // If characters match, add to result
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += s1[i - 1]; // If previous row has larger LCS, add s1[i-1]
                i--;
            } else {
                ans +=
                    s2[j - 1]; // If previous column has larger LCS, add s2[j-1]
                j--;
            }
        }

        // Add remaining characters from s1 (if any)
        while (i > 0) {
            ans += s1[i - 1];
            i--;
        }

        // Add remaining characters from s2 (if any)
        while (j > 0) {
            ans += s2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end()); // Reverse the result string

        return ans;
    }
};
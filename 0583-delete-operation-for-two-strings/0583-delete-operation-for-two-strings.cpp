class Solution {
public:
// ++++++++++++ Space Optimization ++++++++++++++ TC O(n*m)  SC O(m)
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0); // Store only two rows

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    cur[j] = 1 + prev[j - 1]; // Move diagonally
                } else {
                    cur[j] = max(prev[j],cur[j - 1]); // Take max of excluding characters
                }
            }
            prev = cur; // Move current row to previous for the next iteration
        }

        return prev[m]; // The last element contains the answer
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(); 
        int m = word2.length();

        // deletion = n - lcs(word1);
        // insertion = m - lcs(word2);

        // total = delection + insertion;

        return n + m - 2 * longestCommonSubsequence(word1,word2);
    }
};
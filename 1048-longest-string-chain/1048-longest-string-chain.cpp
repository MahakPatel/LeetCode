class Solution {
public:
    bool checkPossible(string s1, string s2) {
        // s1 should be exactly one character longer than s2 to be a valid
        // predecessor
        if (s1.size() != s2.size() + 1)
            return false;

        int first = 0;  // Pointer for s1
        int second = 0; // Pointer for s2

        // Traverse s1 and s2 to check if s2 is a predecessor of s1
        while (first < s1.size()) {
            // If characters match and second pointer is within bounds, move
            // both pointers
            if (s1[first] == s2[second] && second < s2.size()) {
                first++;
                second++;
            } else {
                // Otherwise, just move the first pointer (allowing one extra
                // character in s1)
                first++;
            }
        }

        // If we successfully matched all characters of s2 in s1, return true
        return second == s2.size();
    }
    // ++++++++++++ Using Longest Increasing Subsequence +++++++++++
    // TC O(n^2 * n + nlogn)
    // SC O(n)
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // Sort words based on their length using a lambda function
        // Sorting ensures that we always process shorter words before longer
        // ones
        sort(words.begin(), words.end(),
             [](string& s1, string& s2) { return s1.size() < s2.size(); });

        // dp[i] stores the longest chain ending at index i
        vector<int> dp(n, 1);
        int maxi = 1; // Stores the maximum chain length found

        // Iterate through each word to build the longest chain
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                // If words[prev] can be a predecessor of words[i], update dp[i]
                if (checkPossible(words[i], words[prev]) &&
                    1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            // Update the maximum chain length found so far
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
class Solution {
public:
    // ++++++++++++ Longest Increasing Subsequence ++++++++++++
    // TC O(n^2)
    // SC O(n)
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0; // Handle empty input case

        int maxi = 1; // Stores the maximum length of LIS

        // dp[i]: Length of LIS ending at index i
        // cnt[i]: Number of LIS ending at index i
        vector<int> dp(n, 1), cnt(n, 1);

        // Compute LIS for each index
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i]) {
                    // If taking arr[i] extends a longer LIS
                    if (dp[prev] + 1 > dp[i]) {
                        dp[i] = dp[prev] + 1;
                        cnt[i] = cnt[prev]; // Inherit count from prev
                    }
                    // If taking arr[i] forms another LIS of the same length
                    else if (dp[prev] + 1 == dp[i]) {
                        cnt[i] += cnt[prev]; // Add count from prev
                    }
                }
            }
            maxi = max(maxi, dp[i]); // Update max LIS length found
        }

        int countLIS = 0;
        // Count the number of subsequences with length `maxi`
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi)
                countLIS += cnt[i];
        }

        return countLIS;
    }
};
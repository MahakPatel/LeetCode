class Solution {
public:
    // ++++++++++++. Using LIS(Longest Increasing Subsequence) ++++++++++++++++
    // TC O(n^2)
    // SC O(n)
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        // dp[i] stores the length of the LIS ending at index i
        vector<int> dp(n, 1);
        // sort the array
        sort(arr.begin(), arr.end());

        // hash[i] helps track the previous index to reconstruct the LIS
        // sequence
        vector<int> hash(n);

        int maxi = 1;      // Maximum LIS length found
        int lastIndex = 0; // Last index of the LIS sequence

        // Iterate through the array to calculate dp[i] and track previous
        // indices
        for (int i = 0; i < n; i++) {
            hash[i] = i; // Initially, each element is its own predecessor
            for (int prev = 0; prev < i; prev++) {
                // If arr[prev] % arr[i] == 0, check if taking arr[i] extends a
                // longer LIS
                if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // Store previous index for sequence
                                    // reconstruction
                }
            }

            // Update the maximum LIS length and its ending index
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Construct the LIS sequence by backtracking using the hash array
        vector<int> temp;
        temp.push_back(arr[lastIndex]);

        while (hash[lastIndex] !=
               lastIndex) { // Until we reach the starting element
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }

        // Reverse the sequence to get the correct order
        reverse(temp.begin(), temp.end());

        return temp; // Return the LIS sequence
    }
};
class Solution {
public:
    // +++++++++++++++++ Brute Force ++++++++++++++
    // TC O(n^2)
    // SC O(1)
    //     int sumSubarrayMins(vector<int>& arr) {
    //     int n = arr.size();
    //     int sum = 0;
    //     int mod = (int)(1e9 + 7);

    //     // Iterate over each starting index of the subarray
    //     for (int i = 0; i < n; i++) {
    //         int mini = arr[i]; // Initialize the minimum for this subarray

    //         // Iterate over each ending index of the subarray
    //         for (int j = i; j < n; j++) {
    //             mini = min(arr[j], mini); // Update the minimum
    //             sum = (sum + mini) % mod; // Add the minimum to the sum
    //         }
    //     }

    //     return sum;
    // }


    // +++++++++++++++++ using Previous Smaller Element and Next Smaller Element ++++++++++++++
    // TC O(5n)
    // SC O(5n)
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = (int)(1e9 + 7); // Modulo to prevent integer overflow

        // Compute Next Smaller Element (NSE) and Previous Smaller Element (PSE)
        // for each element
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);

        long long sum = 0; // Using long long to prevent overflow

        // Iterate through each element to calculate its contribution
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];  // Distance from previous smaller element
            int right = nse[i] - i; // Distance to next smaller element

            // Contribution formula: (left * right * arr[i])
            sum = (sum + (1LL * left * right * arr[i]) % mod) % mod;
        }

        return (int)sum; // Convert back to int before returning
    }

    // Function to find Previous Smaller Element (PSE) indices
    vector<int> findPse(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n,
                        -1); // Default value of -1 (no smaller element found)
        stack<int> st;       // Stack to keep track of indices

        for (int i = 0; i < n; i++) {
            // Remove elements from stack that are greater than or equal to
            // arr[i]
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element exists; otherwise, store
            // the index
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i); // Push current index onto the stack
        }

        return pse;
    }

    // Function to find Next Smaller Element (NSE) indices
    vector<int> findNse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n); // Default value of n (no smaller element found)
        stack<int> st;         // Stack to keep track of indices

        for (int i = n - 1; i >= 0; i--) {
            // Remove elements from stack that are greater than arr[i]
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element exists; otherwise, store
            // the index
            nse[i] = st.empty() ? n : st.top();
            st.push(i); // Push current index onto the stack
        }

        return nse;
    }
};
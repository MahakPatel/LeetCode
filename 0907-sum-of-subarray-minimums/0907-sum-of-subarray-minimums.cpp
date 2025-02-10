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
        int mod = (int)(1e9 + 7);  // Define modulo to prevent overflow

        // Compute Previous Smaller Element (PSE) and Next Smaller Element (NSE)
        vector<int> pse = findPse(arr);  // Stores the previous smaller element index for each element
        vector<int> nse = findNse(arr);  // Stores the next smaller element index for each element

        long long sum = 0;  // Stores the final sum of all subarray minimums

        // Compute the sum of minimums using the contribution of each element
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];   // Number of subarrays ending at index i where arr[i] is the minimum
            int right = nse[i] - i;  // Number of subarrays starting at index i where arr[i] is the minimum

            // Contribution of arr[i] to the final sum
            sum = (sum + (1LL * left * right * arr[i]) % mod) % mod;
        }

        return (int)sum;  // Return final result
    }

    // Function to find Previous Smaller Element (PSE) for each index
    vector<int> findPse(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);  // Default value -1 for elements with no smaller previous element
        stack<int> st;  // Stack to keep track of indices

        for (int i = 0; i < n; i++) {
            // Pop elements from stack that are greater than or equal to arr[i]
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If stack is empty, there's no smaller element on the left, so keep -1
            // Otherwise, store the index of the nearest smaller element
            pse[i] = st.empty() ? -1 : st.top();
            
            // Push the current index onto the stack
            st.push(i);
        }

        return pse;
    }

    // Function to find Next Smaller Element (NSE) for each index
    vector<int> findNse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);  // Default value n (out of bounds) for elements with no smaller next element
        stack<int> st;  // Stack to keep track of indices

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack that are strictly greater than arr[i]
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If stack is empty, there's no smaller element on the right, so keep n
            // Otherwise, store the index of the nearest smaller element
            nse[i] = st.empty() ? n : st.top();
            
            // Push the current index onto the stack
            st.push(i);
        }

        return nse;
    }
};
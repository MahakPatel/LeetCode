class Solution {
public:
    // +++++++++++++ Brute Force +++++++++++++++
    // TC O(n^2)
    // SC O(n)
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> nge(n, -1); // Initialize result array with -1 (default
    //     for
    //                             // no greater element)

    //     // Iterate over the array
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < i + n; j++) { // Loop in a circular
    //         manner
    //             int index = j % n;                // Wrap around using modulo

    //             if (nums[index] > nums[i]) { // Find the next greater element
    //                 nge[i] = nums[index];
    //                 break; // Stop once we find the first greater element
    //             }
    //         }
    //     }

    //     return nge;
    // }
    // ++++++++++++ Using Stack ++++++++++++
    // TC O(4n)
    // SC O(2n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(
            n, -1);    // Initialize with -1 (default for no greater element)
        stack<int> st; // Stores indices of elements in decreasing order

        // Traverse the array twice to handle circular nature
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i % n]) {
                st.pop(); // Remove smaller elements
            }

            if (i < n) { // Assign result only for first n elements
                if (!st.empty())
                    nge[i] = nums[st.top()];
            }

            st.push(i % n); // Push current index for next iterations
        }

        return nge;
    }
};
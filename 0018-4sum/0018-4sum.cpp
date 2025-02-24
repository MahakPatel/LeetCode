class Solution {
public:
    // ++++++++++++++++ Brute Force +++++++++++++++
    // TC O(n^4)
    // TC O(2* number of quadruplets)
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     set<vector<int>> st; // Set to store unique quadruplets

    //     // Brute-force approach with 4 nested loops
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             for (int k = j + 1; k < n; k++) {
    //                 for (int m = k + 1; m < n; m++) {
    //                     long long sum =
    //                         (long long)nums[i] + nums[j] + nums[k] + nums[m];

    //                     if (sum == target) {
    //                         vector<int> temp = {nums[i], nums[j], nums[k],
    //                                             nums[m]};
    //                         sort(temp.begin(), temp.end()); // Ensure
    //                         uniqueness st.insert(temp);
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     // Convert set to vector
    //     return vector<vector<int>>(st.begin(), st.end());
    // }

    // ++++++++++++++++ Better Solution +++++++++++++++
    // TC O(n^3 + logn)
    // TC O(2* number of quadruplets + O(n))
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     set<vector<int>> st; // Set to store unique quadruplets

    //     // Iterate over the first element of the quadruplet
    //     for (int i = 0; i < n; i++) {
    //         // Iterate over the second element of the quadruplet
    //         for (int j = i + 1; j < n; j++) {
    //             set<long long> hashmap; // Hash set to store numbers for
    //                                     // checking the fourth element

    //             // Iterate over the third element of the quadruplet
    //             for (int k = j + 1; k < n; k++) {
    //                 long long nums4 =
    //                     target -
    //                     (nums[i] + nums[j] +
    //                      nums[k]); // Calculate the required fourth number

    //                 // If nums4 exists in the hash set, we found a valid
    //                 // quadruplet
    //                 if (hashmap.find(nums4) != hashmap.end()) {
    //                     vector<int> temp = {nums[i], nums[j], nums[k],
    //                                         (int)nums4};
    //                     sort(temp.begin(),
    //                          temp.end()); // Sort to maintain order and avoid
    //                                       // duplicate sets
    //                     st.insert(temp);  // Insert the quadruplet into the
    //                     set
    //                 }

    //                 hashmap.insert(nums[k]); // Store the third number in the
    //                                          // hash set for future lookups
    //             }
    //         }
    //     }

    //     // Convert set to vector and return
    //     return vector<vector<int>>(st.begin(), st.end());
    // }

    // ++++++++++++++++ Optimal Solution +++++++++++++++
    // TC O(n^3)
    // TC O(number of quadruplets)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans; // To store the final list of quadruplets

        sort(nums.begin(),
             nums.end()); // Sort the array to handle duplicates more easily

        // Outer loop for the first element of the quadruplet
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicates of the first element

            // Inner loop for the second element of the quadruplet
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // Skip duplicates of the second element

                int left = j + 1,
                    right = n - 1; // Two pointers for the remaining elements

                // While loop for checking the third and fourth elements using
                // two pointers
                while (left < right) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back(
                            {nums[i], nums[j], nums[left],
                             nums[right]}); // Found a valid quadruplet

                        // Skip duplicates for the left pointer
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        // Skip duplicates for the right pointer
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;  // Move the left pointer to the right
                        right--; // Move the right pointer to the left

                    } else if (sum < target) {
                        left++; // Increase the sum by moving the left pointer
                                // to the right
                    } else {
                        right--; // Decrease the sum by moving the right pointer
                                 // to the left
                    }
                }
            }
        }

        return ans; // Return the list of valid quadruplets
    }
};
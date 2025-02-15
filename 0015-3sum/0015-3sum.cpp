class Solution {
public:
    // +++++++++++++++ Brute Force +++++++++++++++++++
    // TC O(N^3logN)
    // SC O(2*n)
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();

    //     set<vector<int>> st; // Using a set to store unique triplets

    //     // Iterate over all triplets (brute-force approach)
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             for (int k = j + 1; k < n; k++) {
    //                 // Check if the sum of three numbers is zero
    //                 if (nums[i] + nums[j] + nums[k] == 0) {
    //                     vector<int> temp = {nums[i], nums[j], nums[k]};

    //                     // Sort the triplet to avoid duplicate variations
    //                     sort(temp.begin(), temp.end());

    //                     // Insert the triplet into the set (ensures
    //                     uniqueness) st.insert(temp);
    //                 }
    //             }
    //         }
    //     }

    //     // Convert the set into a vector for output
    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;
    // }

    // +++++++++++++++ better Solution +++++++++++++++++++
    // TC O(N^2logM)
    // SC O(2*n + n)
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     set<vector<int>> st; // Set to store unique triplets
    //     int n = nums.size();

    //     // Iterate through each number as a potential first element
    //     for (int i = 0; i < n; i++) {
    //         set<int> hashmap; // HashSet to store seen numbers for quick
    //         lookup

    //         // Iterate through the remaining elements as second and third
    //         // elements
    //         for (int j = i + 1; j < n; j++) {
    //             int third =
    //                 -(nums[i] + nums[j]); // Calculate the required third
    //                 number

    //             // Check if third number exists in the HashSet
    //             if (hashmap.find(third) != hashmap.end()) {
    //                 vector<int> temp = {nums[i], nums[j], third};

    //                 // Sort the triplet to avoid duplicate variations
    //                 sort(temp.begin(), temp.end());

    //                 // Insert the sorted triplet into the set (ensures
    //                 // uniqueness)
    //                 st.insert(temp);
    //             }

    //             // Insert the current number into the HashSet for future
    //             checks hashmap.insert(nums[j]);
    //         }
    //     }

    //     // Convert the set into a vector for output
    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;
    // }


    // +++++++++++++++ Optimal Solution +++++++++++++++++++
    // TC O(N^2logN)
    // SC O(2*n)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Stores the resulting triplets

        int n = nums.size();

        // Sort the array to use the two-pointer technique effectively
        sort(nums.begin(), nums.end());

        // Iterate through the array, treating nums[i] as the first element of
        // the triplet
        for (int i = 0; i < n; i++) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1; // Left pointer
            int k = n - 1; // Right pointer

            // Two-pointer approach to find the other two elements
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++; // If sum is too small, move left pointer to increase
                         // sum
                } else if (sum > 0) {
                    k--; // If sum is too large, move right pointer to decrease
                         // sum
                } else {
                    // Found a valid triplet
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    j++;
                    k--;

                    // Skip duplicate values for the second element
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // Skip duplicate values for the third element
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};
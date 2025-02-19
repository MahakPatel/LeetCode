class Solution {
public:
    // ++++++++++++++ Brute Force ++++++++++++
    // TC O(N^2)
    // SC O(1)
    // bool containsDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i] == nums[j]){
    //                 return true;
    //             }
    //         }
    //     }

    //     return false;
    // }
    // ++++++++++++++ Better Solution ++++++++++++
    // TC O(N^2)
    // SC O(1)
    // bool containsDuplicate(vector<int>& nums) {
    //     unordered_set<int> seen; // Set to store unique elements

    //     for (int num : nums) {
    //         if (seen.find(num) !=
    //             seen.end()) { // If num is already in the set, it's a duplicate
    //             return true;
    //         }
    //         seen.insert(num); // Insert num into the set
    //     }

    //     return false; // No duplicates found
    // }

    // ++++++++++++++ Optimal Solution ++++++++++++
    // TC O(N * nlogn)
    // SC O(1)
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Sort the array in-place (O(n log n) time complexity)
        sort(nums.begin(), nums.end());

        // Check for adjacent duplicates in the sorted array
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false; // No duplicates found
    }
};
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
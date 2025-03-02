class Solution {
public:
    // +++++++++++ Optimal Solution +++++++++++++
    // TC O(n! * n)
    // SC O(n) - but just to return the ans otherwise O(1)
    // Helper function to generate permutations using backtracking
    void permutations(int index, vector<int>& nums, vector<vector<int>>& ans) {
        // Base Case: If we reach the end of the array, store the current
        // permutation
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Recursive case: Try swapping each element from 'index' to the end
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]); // Swap to place element at 'index'
            permutations(index + 1, nums, ans); // Recur for the next index
            swap(nums[i], nums[index]); // Backtrack to restore original order
        }
    }

    // Main function to generate all permutations of the array
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;    // Stores all permutations
        permutations(0, nums, ans); // Start generating permutations
        return ans;
    }
};
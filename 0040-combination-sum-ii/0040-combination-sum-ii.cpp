class Solution {
public:
    // Recursive function to find unique combinations that sum to the target
    void findCombinationSum(int index, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if the target becomes zero, add the current combination to the answer
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Loop through the array starting from 'index'
        for (int i = index; i < arr.size(); i++) {
            // Skip duplicate elements to avoid duplicate combinations
            if (i > index && arr[i] == arr[i - 1]) continue;

            // If the current element is greater than the remaining target, stop further recursion
            if (arr[i] > target) break;

            // Include the current element in the combination
            ds.push_back(arr[i]);

            // Move to the next element (i + 1) to ensure each element is used at most once
            findCombinationSum(i + 1, arr, target - arr[i], ans, ds);

            // Backtrack: remove the last added element before the next iteration
            ds.pop_back();
        }
    }

    // TC O(2^n * nlogn * K) where k = avg length of Combination
    // SC O(k * x) where x = combination
    // Main function to find all unique combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the input array to easily handle duplicates
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans; // Stores all valid combinations
        vector<int> ds; // Temporary list to store the current combination

        // Call the recursive function
        findCombinationSum(0, candidates, target, ans, ds);

        return ans;
    }

};
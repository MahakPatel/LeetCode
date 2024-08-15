class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //+++++++++++++++++ Better Solution +++++++++++++++++++

    //     next_permutation(nums.begin(),nums.end());
    // }
        // ++++++++++++++ Optimal Solution +++++++++++++++++++
        int n = nums.size();
        int index = -1;

        // Step 1: Find the largest index i such that nums[i] < nums[i + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If no such index exists, the array is in descending order
        // Reverse the entire array to get the smallest permutation
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return; // No need to continue further
        }

        // Step 3: Find the largest index j greater than index such that nums[j]
        // > nums[index]
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 4: Reverse the subarray nums[index + 1:]
        reverse(nums.begin() + index + 1, nums.end());
    }
};
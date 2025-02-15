class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //++++++++++++++++ Optiomal Solution +++++++++++++++++++++
        // TC O(N)
        // SC O(1)
        // Initialize variables to track maximum sum found so far and current
        // sum
        int sum = 0;        // Current sum of subarray being considered
        int maxi = INT_MIN; // Maximum sum found so far, initialized to smallest
                            // possible integer

        // Traverse through each element in the array
        for (auto it : nums) {
            // Add the current element to the current sum
            sum += it;

            // Update maxi to be the maximum of current maxi and current sum
            maxi = max(sum, maxi);

            // If current sum is less than zero, reset current sum to zero
            // This effectively "resets" the subarray to start considering from
            // the next element
            if (sum < 0)
                sum = 0;
        }

        // Return the maximum sum found
        return maxi;
    }

    // int maxSubArray(vector<int>& nums) {
    //     //++++++++++++++++ Optiomal Solution +++++++++++++++++++++
    //     // IF ASK FOR PRINT THE SUBARRAY
    //     // TC O(N)
    //     // SC O(1)
    //     // Initialize variables to track maximum sum found so far and current
    //     // sum
    //     int sum = 0;        // Current sum of subarray being considered
    //     int maxi = INT_MIN; // Maximum sum found so far, initialized to smallest
    //                         // possible integer
    //     int ansStart = -1;
    //     int ansEnd = -1;

    //     // Traverse through each element in the array
    //     for (auto it : nums) {
    //         if(sum == 0) start = i;
    //         // Add the current element to the current sum
    //         sum += it;

    //         if(sum > max){
    //             max = sum;
    //             ansStart = start;
    //             andEnd = i;
    //         }

    //         // If current sum is less than zero, reset current sum to zero
    //         // This effectively "resets" the subarray to start considering from
    //         // the next element
    //         if (sum < 0)
    //             sum = 0;
    //     }

    //     // Return the maximum sum found
    //     return maxi;
    // }

    // +++++++++++++++ Better Solution ++++++++++++++
    // TC O(N^2)
    // SC O(1)
    //     int n = nums.size();
    //     int maxi = INT_MIN;

    //     for (int i = 0; i < n; i++) {
    //         int sum = 0;
    //         for (int j = i; j < n; j++) {
    //             sum += nums[j];

    //             maxi = max(maxi, sum);
    //         }
    //     }

    //     return maxi;
    // }

    // ++++++++++++++ Brute Force +++++++++++++++
    // TC O(N^3)
    // SC O(1)
    //     int n = nums.size();
    //     int maxi = INT_MIN;

    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             int sum =0;
    //             for(int k=i;k<=j;k++){
    //                 sum += nums[k];

    //                 maxi = max(sum,maxi);
    //             }
    //         }
    //     }

    //     return maxi;
    // }
};
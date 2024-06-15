class Solution {
public:
    int numsOfSubArray(vector<int>& nums, int sum) {

        // Binary Search
        int numsOfSubArray = 1;
        int sumOfSubArr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sumOfSubArr + nums[i] <= sum) { // check if the sum of subarray and the sum of current element if less then the sum then sum them
                sumOfSubArr = sumOfSubArr + nums[i];
            } else {
                numsOfSubArray += 1; // or else increase thge subarray and put the sum in sumOfSubArr
                sumOfSubArr = nums[i];
            }
        }

        return numsOfSubArray;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

// range is between max to sum of the given elements
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0); // find the sum of given array

        while (low <= high) {
            int mid = (low + high) / 2;

            if (numsOfSubArray(nums, mid) <= k) { // check if numsOfSubArray is less the. the given array then
                high = mid - 1; // remove right portion of array
            } else {
                low = mid + 1; // remove left portion of array
            }
        }

        return low;
    }
// +++++++++++++++ Brute Force Approch +++++++++++
//     int countPartitions(vector<int> &a, int maxSum) {
//     int n = a.size(); //size of array.
//     int partitions = 1;
//     long long subarraySum = 0;
//     for (int i = 0; i < n; i++) {
//         if (subarraySum + a[i] <= maxSum) {
//             //insert element to current subarray
//             subarraySum += a[i];
//         }
//         else {
//             //insert element to next subarray
//             partitions++;
//             subarraySum = a[i];
//         }
//     }
//     return partitions;
// }

// int largestSubarraySumMinimized(vector<int> &a, int k) {
//     int low = *max_element(a.begin(), a.end());
//     int high = accumulate(a.begin(), a.end(), 0);

//     for (int maxSum = low; maxSum <= high; maxSum++) {
//         if (countPartitions(a, maxSum) == k)
//             return maxSum;
//     }
//     return low;
// }
};

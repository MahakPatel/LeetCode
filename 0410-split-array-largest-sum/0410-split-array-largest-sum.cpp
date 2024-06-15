class Solution {
public:
    int numsOfSubArray(vector<int>& nums, int sum) {
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

            if (numsOfSubArray(nums, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

// solve this using lower bound
        int n = nums.size();
        int ans = n; // size of array

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2; // find mid

            if (nums[mid] >= target) { // if v[mid] is >= then ans may be mid and now
                               // you can search in first half of array
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1; // else search in second half of array
            }
        }
        return ans;
    }
};
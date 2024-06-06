class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            // if mid points the target
            if (nums[mid] == target)
                return true;

            if (nums[low] == nums[mid] &&
                nums[mid] == nums[high]) { // if arr [ 3,2,1,3,4,5,3] then we
                                           // can't compare low, mid and high
                                           // because it same so we will compare
                                           // low+1 and high-1 elemet with mid
                low = low + 1;
                high = high - 1;
                continue; // continue till this condition false
            }

            // if left part is sorted:
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    // element exists:
                    high = mid - 1;
                } else {
                    // element does not exist:
                    low = mid + 1;
                }
            } else { // if right part is sorted:
                if (nums[mid] <= target && target <= nums[high]) {
                    // element exists:
                    low = mid + 1;
                } else {
                    // element does not exist:
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
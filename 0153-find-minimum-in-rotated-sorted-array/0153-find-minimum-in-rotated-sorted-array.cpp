class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int ans = INT_MAX; // take min value as max

        while (low <= high) {
            int mid = (low + high) / 2;

            // if left part is sorted:
            if (nums[low] <= nums[mid]) {
                // keep the minimum:
                ans = min(ans, nums[low]);

                // Eliminate left half:
                low = mid + 1;
            } else { // if right part is sorted:

                // keep the minimum:
                ans = min(ans, nums[mid]);

                // Eliminate right half:
                high = mid - 1;
            }

        }
                    return ans;
    }
};
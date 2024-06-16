class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Using XOR :- TC O(n)
        // int xor1 = 0;
        // for(int i=0;i<nums.size();i++){
        //     xor1=xor1 ^ nums[i];
        //         }

        //         return xor1;

        int low = 1; // we will start with 1st index because first index doesn't
                     // have left index
        int n = nums.size();
        int high = n - 2; // we will start with n-1th index because first index
                          // doesn't have right index

        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1]) // check for first index
            return nums[0];

        if (nums[n - 1] != nums[n - 2]) // check for last index
            return nums[n - 1];

        while (low <= high) {
            int mid = (low + high) / 2;

            // if arr[mid] is the single element:
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // we are in the left:
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // eliminate the left half:
                low = mid + 1;
            }
            // we are in the right:
            else {
                // eliminate the right half:
                high = mid - 1;
            }
        }

        return -1;
    }
};
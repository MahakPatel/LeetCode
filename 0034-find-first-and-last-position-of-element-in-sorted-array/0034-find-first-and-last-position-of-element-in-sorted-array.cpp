class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> temp;

        int lb = lowerBound(nums, nums.size(), target); // find lowerbound

        // this block is for if the value is not present in array then retun -1
        if (lb == nums.size() || nums[lb] != target) {
            temp.push_back(-1);
            temp.push_back(-1);
            return temp;
        }

        temp.push_back(lb);
        int ub = upperBound(nums, nums.size(), target) -
                 1; // so upperbound is always grtaer than the valu so we need
                    // last accurance so the last accurance is always less the
                    // the upperbound index
        temp.push_back(ub);

        return temp;
    }

    int lowerBound(vector<int>& nums, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n; // size of array

        while (low <= high) {
            int mid = (low + high) / 2; // find mid

            if (nums[mid] >= x) { // if v[mid] is >= then ans may be mid and now
                                  // you can search in first half of array
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1; // else search in second half of array
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n; // size of array

        while (low <= high) {
            int mid = (low + high) / 2; // find mid

            if (nums[mid] > x) { // if v[mid] is >= then ans may be mid and now
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
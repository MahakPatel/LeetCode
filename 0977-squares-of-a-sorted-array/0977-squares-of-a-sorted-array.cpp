class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // ++++++++++++++ Brute Force +++++++++++
        // TC O(nlogn)
        // SC O(1)
        // int n = nums.size();
        // vector<int> res(n,0);

        // for(int i=0;i<n;i++){
        //     res[i] = abs(nums[i]) * abs(nums[i]);
        // }

        // sort(res.begin(),res.end());

        // return res;

        // ++++++++++++++ Optimal Solution +++++++++++
        // TC O(n)
        // SC O(1)
        int n = nums.size();
        vector<int> res(n, 0);

        int left = 0;
        int right = n - 1;

        for (int i = n-1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }

        return res;
    }
};
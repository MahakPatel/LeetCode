class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int num = 0; num < (1 << n); num++) { // num < (1 << n) is just a (2^n -1)
            ans.push_back({}); // for empty []
            for (int i = 0; i < n; i++) {
                // check if the ith bit is set or not
                if (num & (1 << i)) {
                    ans.back().push_back({nums[i]});
                }
            }
        }
        return ans;
    }
};
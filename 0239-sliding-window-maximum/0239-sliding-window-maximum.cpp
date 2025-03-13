class Solution {
public:
    // ++++++++++++++ Brute Force +++++++++++
    // TC O(n-k)*k
    // SC O(n-k)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;

    //     int n = nums.size();

    //     for(int i=0;i<=n-k;i++){
    //         int maxi = nums[i];

    //         for(int j = i;j<=i+k-1;j++){
    //             maxi = max(maxi,nums[j]);
    //         }

    //         ans.push_back(maxi);
    //     }

    //     return ans;
    // }
    // +++++++++++ Optimal Solution +++++++++++++++++
    // TC O(2n)
    // SC O(k) + O(n-k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // Stores indices of useful elements

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements out of the window (leftmost)
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from back that are smaller than current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current element index
            dq.push_back(i);

            // The front element is the max for the current window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
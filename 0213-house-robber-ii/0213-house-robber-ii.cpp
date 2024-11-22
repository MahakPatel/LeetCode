class Solution {
public:
    int maxMoney(const std::vector<int>& nums) {
        int n = nums.size();

        // Edge case: no houses
        if (n == 0)
            return 0;

        // Edge case: only one house
        if (n == 1)
            return nums[0];

        int prev2 = 0;      // Maximum amount robbed two houses before
        int prev = nums[0]; // Maximum amount robbed one house before

        // Iterate through the houses starting from the second house
        for (int i = 1; i < n; ++i) {
            // Option 1: Pick the current house
            int picked = nums[i];
            if (i > 1) {
                picked += prev2;
            }

            // Option 2: Skip the current house
            int notPicked = prev;

            // Update current max amount
            int current = std::max(picked, notPicked);

            // Update prev2 and prev for the next iteration
            prev2 = prev;
            prev = current;
        }

        // The maximum amount of money that can be robbed
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;

        int n = nums.size();

        if (n == 1)
            return nums[0];

        for (int i = 0; i < n; i++) {
            // Case 1: Exclude the last house
            if (i != 0)
                temp1.push_back(nums[i]);
            // Case 2: Exclude the first house
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        return max(maxMoney(temp1), maxMoney(temp2));
    }
};
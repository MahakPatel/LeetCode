class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0; // Edge case: If no bars, no water can be trapped

        vector<int> prefixMax(n), suffixMax(n);

        // Compute prefix max heights (max height to the left of each bar)
        // TC O(n) 
        // SC O(n)
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        // Compute suffix max heights (max height to the right of each bar)
        // TC O(n) 
        // SC O(n)
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        int total = 0;

        // Compute trapped water at each index
        // TC O(n) 
        for (int i = 0; i < n; i++) {
            int waterLevel =
                min(prefixMax[i], suffixMax[i]); // Min height of the two walls
            if (waterLevel > height[i]) {
                total += waterLevel - height[i]; // Water trapped at this index
            }
        }

        return total;
    }
};
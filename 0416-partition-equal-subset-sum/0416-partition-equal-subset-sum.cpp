class Solution {
public:
 bool isSubsetSum(vector<int>& arr, int target) {
            int n = arr.size();
            
            // Two arrays: 'prev' stores the previous row, 'cur' stores the current row
            vector<bool> prev(target + 1, 0), cur(target + 1, 0);
            
            prev[0] = cur[0] = true;  // Base case: subset sum of 0 is always possible (empty subset)
        
            // If arr[0] is less than or equal to target, mark it as possible in prev
            if (arr[0] <= target) {
                prev[arr[0]] = true;
            }
        
            // Iterate through all elements of the array starting from index 1
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= target; j++) {
                    // Option 1: Do not take the current element
                    bool notTake = prev[j];
                    
                    // Option 2: Take the current element, but only if j >= arr[i]
                    bool take = false;
                    if (j >= arr[i]) {
                        take = prev[j - arr[i]];  // Look at the previous row for the remaining sum
                    }
        
                    // Current value of dp[j] is the union of the two choices (take or not take)
                    cur[j] = take || notTake;
                }
                
                // Move to the next row by copying current results into prev
                prev = cur;
            }
            
            // The answer will be stored in prev[target], as it holds the final row after all iterations
            return prev[target];
        }


    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum =0;

        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        if(totalSum % 2) return false;

        return isSubsetSum(nums,totalSum/2);
    }
};
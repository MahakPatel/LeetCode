class Solution {
public:
    // +++++++++++++ Brute Force ++++++++++++++
    // TC O(n^2)
    // SC O(1)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();

    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i] == nums[j]){
    //                 return nums[i];
    //             }
    //         }
    //     }

    //     return -1;
    // }

    // ++++++++++++++ Better Solution ++++++++++
    // TC O(nlogn + n)
    // SC o(1)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();

    //     sort(nums.begin(),nums.end());

    //     for(int i=0;i<n;i++){
    //         if(nums[i] == nums[i+1]){
    //             return nums[i];
    //         }
    //     }

    //     return -1;
    // }

    // +++++++++++++ Optimal Solution ++++++++++++++++
    // ++++++++++ Floyd’s Cycle Detection Algorithm (Tortoise and Hare) +++++++++++
    // TC O(N)
    // SC O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; // Slow pointer starts from first element
        int fast = nums[0]; // Fast pointer starts from first element

        // Phase 1: Detect Cycle
        do {
            slow = nums[slow];       // Moves one step
            fast = nums[nums[fast]]; // Moves two steps
        } while (slow != fast); // Loop until cycle is detected

        // Phase 2: Find the Entry Point of the Cycle (Duplicate Number)
        fast = nums[0]; // Reset fast pointer to start

        while (slow != fast) {
            slow = nums[slow]; // Moves one step
            fast = nums[fast]; // Moves one step
        }

        return slow; // This is the duplicate number
    }
};
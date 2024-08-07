class Solution {
public:
    int jump(vector<int>& nums) { 

       //++++++++++++++++ for recursion ++++++++++++++
        // vector<int> memo(nums.size(), -1);
        // return recursion(nums, 0,memo); 
        // }

        // ++++++++++++ Ierative code+++++++++++++
        int jumps = 0; // to count the number of jumps
        int l = 0; // start of the range
        int r = 0; // end of the range

        while (r < nums.size() - 1) {
            int far = 0; // to store where you reached
            for (int i = l; i <= r; ++i) {
                far = max(far, i + nums[i]); // far will be maximum where you can reach with that jump
            }
            l = r + 1; // l will next of r
            r = far; // r will the far where you can maximum reach
            jumps++; // increase the jump
        }

        return jumps;
    }
// ++++++++++++++++++Recursive Code+++++++++++++++
//     int recursion(vector<int>& nums, int index, vector<int>& memo) {
//     if (index >= nums.size() - 1)
//         return 0;
    
//     if (memo[index] != -1)
//         return memo[index];

//     int minJumps = INT_MAX;
//     for (int i = 1; i <= nums[index] && index + i < nums.size(); i++) {
//         int jumpsFromNextIndex = recursion(nums, index + i, memo);
//         if (jumpsFromNextIndex != INT_MAX) { // Ensure we do not add to INT_MAX
//             int currentJump = 1 + jumpsFromNextIndex;
//             minJumps = min(minJumps, currentJump);
//         }
//     }

//     memo[index] = minJumps;
//     return memo[index];
// }
};
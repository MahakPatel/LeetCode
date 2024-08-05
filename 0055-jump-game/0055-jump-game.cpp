class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0; // start with 0
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxLen) // if index is greater then maxLen then return false
                return false;
            maxLen = max(maxLen, i + nums[i]); // maxLen is max of maxLen and index + value of index

            // this if condition is just for optimize code 
            // if maxLen is greater then size of array then no need to check u easly reach to end of array
            if(maxLen > nums.size()){
                return true;
            }
        }

        return true;
    }
};
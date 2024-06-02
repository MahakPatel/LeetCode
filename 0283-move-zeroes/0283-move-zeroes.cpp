class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // Optimal Approch

        int j = 0;

        for(int i =0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j++;
            }
        }


        // // Brute Fore Approch
        // int k = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] != 0) {    // check for 0
        //         nums[k] = nums[i]; // if 0 is not found then replace that
        //                            // element 0's place
        //         k++;
        //     }
        // }
        // for (int i = k; i < nums.size(); i++) {
        //     nums[i] = 0; // at the end of array rest of place filled with 0
        // }
    }
};
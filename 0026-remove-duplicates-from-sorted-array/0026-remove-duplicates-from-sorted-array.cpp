class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){ // check for not equal value 
                nums[j]=nums[i]; // if found than place to next index
                j++;
            }
        }

        return j;
    }
};
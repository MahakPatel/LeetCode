class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // +++++++++++ Optimal Solution ( only if we need to return 'Yes' Or
        // 'No') ++++++++
        //     int n = nums.size();;

        //     sort(nums.begin(),nums.end());

        //     int left =0;
        //     int right = n-1;

        //     while(left < right){
        //         if(nums[left] + nums[right] == target){
        //             return true;
        //         }else if(nums[left] + nums[right] > target){
        //             right--;
        //         }else{
        //             left++;
        //         }
        //     }

        //     return false;
        // }

        // ++++++++++ Better Solution (optimal solution if we need to return
        // index like this question) ++++++++++++++++++++++
        int n = nums.size();
        map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int require = target - num;

            if (mpp.find(require) != mpp.end()) {
                return {mpp[require], i};
            }

            mpp[num] = i;
        }

        return {};
    }

    // ++++++++++++ Brute Force +++++++++++++
    //  int n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             if (nums[i] + nums[j] == target) {
    //                 return {i, j};
    //             }
    //         }
    //     }
    //     return {};
    // }
};
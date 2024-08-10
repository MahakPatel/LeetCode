class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // +++++++++++ Optimal Solution - 2 pointer Approach ( only if we need to return 'Yes' Or
        // 'No') ++++++++
        //     int n = nums.size();;

        //     sort(nums.begin(),nums.end()); // sort the array

        //     int left =0; // first pointer at 0th index
        //     int right = n-1; // second pointer at last index

        //     while(left < right){
        //         if(nums[left] + nums[right] == target){ // if sum is equal to target return true
        //             return true;
        //         }else if(nums[left] + nums[right] > target){ // if sum is greater then target
        //             right--; // decrease right by 1
        //         }else{ // if sum is less then target
        //             left++; // increase left by 1
        //         }
        //     }

        //     return false;
        // }

        // ++++++++++ Better Solution (optimal solution if we need to return
        // index like this question) ++++++++++++++++++++++
        int n = nums.size();
        map<int, int> mpp; // create a map

        for (int i = 0; i < n; i++) {
            int num = nums[i]; // get current value
            int require = target - num; // find the require value by minus current value from target value

            if (mpp.find(require) != mpp.end()) { // check of required value already present of not
                return {mpp[require], i}; // if present the return that index with current value index
            }

            mpp[num] = i; // put the index into map
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
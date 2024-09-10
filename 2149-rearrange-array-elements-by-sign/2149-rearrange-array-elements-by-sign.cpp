class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // +++++++++++++++++++++++ Better Solution +++++++++++++++
    //     int n = nums.size();

    //     // Vectors to store positive and negative numbers.
    //     // Size of each should be at most n/2.
    //     vector<int> positive;
    //     vector<int> negative;

    //     // Separate positive and negative numbers.
    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] < 0) {
    //             negative.push_back(nums[i]);
    //         } else {
    //             positive.push_back(nums[i]);
    //         }
    //     }

    //     // Check if the number of positive and negative numbers are valid.
    //     if (positive.size() != negative.size()) {
    //         // Invalid case if counts don't match; returning empty vector or
    //         // handle as needed
    //         return {}; // or some other indication of invalid input
    //     }

    //     // Rearrange elements into the original array with alternating positive
    //     // and negative numbers.
    //     for (int i = 0; i < positive.size(); i++) {
    //         nums[2 * i] = positive[i]; // Place positive number at even index.
    //         nums[2 * i + 1] =
    //             negative[i]; // Place negative number at odd index.
    //     }

    //     return nums; 
    // }
    // +++++++++++++++++++ Optimal Solution ++++++++++++++++++
        int n = nums.size();
        vector<int> ans(n,0);

        int positiveIndex =0;
        int negativeIndex = 1;

        for(int i=0;i<n;i++){
            if(nums[i] < 0){
                ans[negativeIndex] = nums[i];
                negativeIndex +=2;
            }else{
                ans[positiveIndex] = nums[i];
                positiveIndex +=2;
            }
        }

        return ans;
    }
};

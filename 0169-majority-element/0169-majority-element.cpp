class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // +++++++++++++++ Optimal Solution +++++++++++++
        // +++++++++++++++ Moore's Voting Algorithm ++++++++++++++++++++++

        int n = nums.size();

        // First pass: Find the candidate for majority element.
        int count = 0;
        int element;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                // Start a new candidate if count is zero.
                element = nums[i];
                count = 1;
            } else if (nums[i] == element) {
                // Increment count if the current element matches the candidate.
                count++;
            } else {
                // Decrement count if the current element does not match the
                // candidate.
                count--;
            }
        }

        // Second pass: Verify if the candidate is indeed the majority element.
        int count1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == element) {
                count1++;
            }
        }

        // Check if the candidate appears more than n/2 times.
        if (count1 > (n / 2)) {
            return element; // Return the majority element.
        }

        // Return -1 if no majority element exists.
        return -1;
    }

    // +++++++++++++++++ Brute Force +++++++++++++++
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         int count = 0;
    //         for (int j = 0; j < n; j++) {
    //             if (nums[i] == nums[j]) {
    //                 count++;
    //             }
    //         }

    //         if (count > (n / 2)) {
    //             return nums[i];
    //         }
    //     }

    //     return -1;
    // }

    // +++++++++++++++ Better Solution+++++++++++++++++++
    //     map<int,int> mpp;

    //     for(int i=0;i<nums.size();i++){
    //         mpp[nums[i]]++;
    //     }

    //     for(auto it:mpp){
    //         if(it.second > (nums.size()/2)){
    //             return it.first;
    //         }
    //     }

    //     return -1;
    // }
};
class Solution {
public:
    void sortColors(vector<int>& nums){
    // ++++++++++++++ Optimal Solution +++++++++++++++
        // Dutch National Flag Algorithm
        // This algorithm sorts an array containing only 0s, 1s, and 2s.
        // The goal is to partition the array into three sections:
        // 1. All 0s on the left
        // 2. All 1s in the middle
        // 3. All 2s on the right

    int n = nums.size(); // Get the size of the array
    int mid = 0;      // Pointer to traverse the array, initially at the start
    int low = 0;      // Pointer for the boundary of 0s, initially at the start
    int high = n - 1; // Pointer for the boundary of 2s, initially at the end

    // Traverse the array with the mid pointer until it surpasses the high
    // pointer
    while (mid <= high) {
        if (nums[mid] == 0) { // If the current element is 0
            // Swap the current element with the element at the low pointer
            swap(nums[low], nums[mid]);
            low++;                   // Move the low pointer to the right
            mid++;                   // Move the mid pointer to the right
        } else if (nums[mid] == 1) { // If the current element is 1
            mid++; // Simply move the mid pointer to the right, as 1s are in the
                   // middle section
        } else {   // If the current element is 2
            // Swap the current element with the element at the high pointer
            swap(nums[mid], nums[high]);
            high--; // Move the high pointer to the left
            // Note: Do not move the mid pointer here because we need to check
            // the new element at mid
        }
    }
}

// +++++++++++++ better Solution++++++++++++
//     int n= nums.size();
//     int count0=0;
//     int count1=0;
//     int count2=0;

//     for(int i=0;i<n;i++){
//         if(nums[i] == 0) count0++;
//         else if(nums[i] == 1) count1++;
//         else count2++;
//     }

//     for(int i=0;i<count0;i++) nums[i] = 0;
//     for(int i=count0;i<count0+count1;i++) nums[i] = 1;
//     for(int i=count0+count1;i<n;i++) nums[i] = 2;
// }
}
;
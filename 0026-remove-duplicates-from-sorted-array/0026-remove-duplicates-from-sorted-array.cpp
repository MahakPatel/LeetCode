class Solution {
public:
    // +++++++++++++ Optimal Solution +++++++++++++++
    // TC O(n)
    // SC O(1)
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // check for not equal value
                nums[j] = nums[i];        // if found than place to next
                j++;
            }
        }

        return j;
    }
    // +++++++++++++ Brute Force +++++++++++++++
    // TC O(n + nlogn)
    // SC O(n)
    // int removeDuplicates(vector<int>& nums) {
    //     int n = nums.size();

    //     set<int>
    //         st; // Using a set to store unique elements (automatically sorted)

    //     // Insert all elements into the set (O(N log N) due to set insertions)
    //     for (int i = 0; i < n; i++) {
    //         st.insert(nums[i]);
    //     }

    //     int index = 0;

    //     // Copy unique elements back to the original array (O(N))
    //     for (auto it : st) {
    //         nums[index] = it;
    //         index++;
    //     }

    //     return index; // Return the number of unique elements
    // }
};
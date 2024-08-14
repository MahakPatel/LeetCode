class Solution {
public:
    // bool linearSearch(vector<int>& a, int num) {
    //     int n = a.size();
    //     for (int i = 0; i < n; i++) {
    //         if (a[i] == num)
    //             return true;
    //     }
    //     return false;
    // }
    int longestConsecutive(vector<int>& nums) {
        // +++++++++++ Brute Force +++++++++++++++++
        //     int n = nums.size();
        //     int longest = 1;
        //     for (int i = 0; i < n; i++) {
        //         int count = 1;
        //         int x = nums[i];
        //         while (linearSearch(nums, x + 1) == true) {
        //             count = count + 1;
        //             x = x + 1;
        //         }

        //         longest = max(longest, count);
        //     }

        //     return longest;
        // }
        // ++++++++++++++++++ optimal solution +++++++++++++
        int n = nums.size();

        // Edge case: If the array is empty, there are no consecutive sequences
        if (n == 0)
            return 0;

        // Initialize variables
        int longest = 1; // Variable to store the length of the longest
                         // consecutive sequence
        int count = 1;   // Variable to count the length of the current
                         // consecutive sequence

        // Create a hash set to store unique elements from the array
        unordered_set<int> s;

        // Insert all elements of the array into the hash set
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        // Iterate over each element in the hash set
        for (auto it : s) {
            // Check if it is the start of a new sequence
            if (s.find(it - 1) == s.end()) {
                count = 1;  // Start a new sequence with length 1
                int x = it; // Initialize the current number in the sequence

                // Extend the sequence by checking for consecutive numbers
                while (s.find(x + 1) != s.end()) {
                    x = x + 1; // Move to the next number in the sequence
                    count++;   // Increment the count of the current sequence
                               // length
                }

                // Update the longest sequence length if the current sequence is
                // longer
                longest = max(longest, count);
            }
        }

        return longest; // Return the length of the longest consecutive sequence
    }

    // +++++++++++++ Better Solution ++++++++++++++++++++++++
    //     int n = nums.size();

    //     // Edge case: If the array is empty, there are no consecutive
    //     sequences if (n == 0)
    //         return 0;

    //     // Sort the array to bring consecutive numbers together
    //     sort(nums.begin(), nums.end());

    //     int longest = 1; // Variable to store the length of the longest
    //                      // consecutive sequence
    //     int count = 1;   // Variable to count the length of the current
    //                      // consecutive sequence
    //     int lastSmallest =
    //         nums[0]; // Initialize with the first element in the sorted array

    //     // Traverse the sorted array to find the longest consecutive sequence
    //     for (int i = 1; i < n; i++) {
    //         // Check if the current number is consecutive to the last number
    //         if (nums[i] == lastSmallest + 1) {
    //             count++; // Increase the count of the current sequence length
    //             lastSmallest =
    //                 nums[i]; // Update the last smallest number in the
    //                 sequence
    //         }
    //         // Check if the current number is not the same as the last
    //         smallest
    //         // number
    //         else if (nums[i] != lastSmallest) {
    //             count = 1; // Reset the count to 1 for a new sequence
    //             lastSmallest = nums[i]; // Update the last smallest number to
    //                                     // the current number
    //         }

    //         // Update the longest sequence length if the current sequence is
    //         // longer
    //         longest = max(longest, count);
    //     }

    //     return longest; // Return the length of the longest consecutive
    //     sequence
    // }
};
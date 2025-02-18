class Solution {
public:
    // +++++++++++++++++ Better Solution +++++++++++++++++++++
    // TC O(n * logn)
    // SC O(n)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ls;   // Stores elements that appear more than n/3 times
    //     map<int, int> mp; // Frequency map to count occurrences of each
    //     number int mini =
    //         (int)(n / 3) +
    //         1; // Minimum count required for a majority element (> n/3 times)

    //     // Iterate through the array and count occurrences of each number
    //     for (int i = 0; i < n; i++) {
    //         mp[nums[i]]++; // Increase the count of the current number

    //         // If a number reaches the required frequency, add it to the list
    //         if (mp[nums[i]] == mini) {
    //             ls.push_back(nums[i]);
    //         }

    //         // Since there can be at most two elements that appear more than
    //         n/3
    //         // times, we stop early if we already have two elements in the
    //         // result list.
    //         if (ls.size() == 2)
    //             break;
    //     }

    //     // Sort the result before returning
    //     sort(ls.begin(), ls.end());

    //     return ls; // Return the list of elements that appear more than n/3
    //                // times
    // }
    // +++++++++++++++++ Brute Force  +++++++++++++++++++++
    // TC O(n^2)
    // SC O(1)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ls; // Stores elements appearing more than n/3 times

    //     // Iterate through each element in the array
    //     for (int i = 0; i < n; i++) {
    //         // If the list is empty or the current element is not already in
    //         the
    //         // list
    //         if (ls.size() == 0 || ls[0] != nums[i]) {
    //             int count = 0; // Counter to track occurrences of nums[i]

    //             // Count occurrences of nums[i] in the entire array
    //             for (int j = 0; j < n; j++) {
    //                 if (nums[j] == nums[i]) {
    //                     count++;
    //                 }

    //                 // If nums[i] appears more than n/3 times, add it to the
    //                 // result list
    //                 if (count > n / 3) {
    //                     ls.push_back(nums[i]);
    //                     break; // Break to avoid adding duplicate elements
    //                 }
    //             }

    //             // Since there can be at most two majority elements (> n/3),
    //             // stop early
    //             if (ls.size() == 2)
    //                 break;
    //         }
    //     }

    //     return ls; // Return the list of majority elements
    // }

    // +++++++++++++++++ Optimal Solution  +++++++++++++++++++++
    // TC O(n)
    // SC O(1)
    vector<int> majorityElement(vector<int> v) {
        int n = v.size(); // size of the array

        int cnt1 = 0, cnt2 = 0; // counts for the potential majority elements
        int el1 = INT_MIN;      // first potential majority element
        int el2 = INT_MIN;      // second potential majority element

        // Applying the Extended Boyer-Moore's Voting Algorithm:
        for (int i = 0; i < n; i++) {
            // When cnt1 is 0, assign current element as el1
            // but only if it's not equal to el2
            if (cnt1 == 0 && el2 != v[i]) {
                cnt1 = 1;
                el1 = v[i];
            }
            // Similarly, when cnt2 is 0, assign current element as el2
            // but only if it's not equal to el1
            else if (cnt2 == 0 && el1 != v[i]) {
                cnt2 = 1;
                el2 = v[i];
            }
            // If current element is equal to el1, increment cnt1
            else if (v[i] == el1)
                cnt1++;
            // If current element is equal to el2, increment cnt2
            else if (v[i] == el2)
                cnt2++;
            // If current element is different from both el1 and el2,
            // decrement both cnt1 and cnt2
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ls; // list to store majority elements

        // Manually check if the elements el1 and el2 appear enough times
        // in the original array to be considered majority elements:
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el1)
                cnt1++; // count occurrences of el1
            if (v[i] == el2)
                cnt2++; // count occurrences of el2
        }

        int mini =
            int(n / 3) +
            1; // calculate the minimum number of occurrences to be a majority
        if (cnt1 >= mini) // if el1 appears more than or equal to n/3 times
            ls.push_back(el1);
        if (cnt2 >= mini) // if el2 appears more than or equal to n/3 times
            ls.push_back(el2);

        // Uncomment the following line if sorting of the result is required:
        // sort(ls.begin(), ls.end()); // TC --> O(2*log2) ~ O(1); for sorting
        // two elements, it's negligible

        return ls; // return the list of majority elements
    }
};
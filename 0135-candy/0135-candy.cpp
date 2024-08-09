class Solution {
public:
    int candy(vector<int>& ratings) {

        // ++++++++++++++ Optimal Solution ++++++++++++++
        int n = ratings.size(); // Size of the given vector

        int sum = 1; // Initialize sum with 1 candy for the first child
        int i = 1;   // Start from the second child

        while (i < n) {
            // Case where the current child's rating is the same as the previous
            // child's rating
            if (ratings[i] == ratings[i - 1]) {
                sum += 1; // Give 1 candy to the current child
                i++;
                continue; // Move to the next child
            }

            int peak = 1; // Peak candy count for increasing sequence

            // Traverse while the current child's rating is greater than the
            // previous child's rating
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1;        // Increment peak candies
                sum = sum + peak; // Add candies for the peak child
                i++;
            }

            int down = 1; // Initial candies count for decreasing sequence

            // Traverse while the current child's rating is less than the
            // previous child's rating
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down; // Add candies for the current child
                i++;
                down++; // Increment candies for the next child in the
                        // decreasing sequence
            }

            // If the downward sequence required more candies than the peak,
            // adjust the total sum
            if (down > peak) {
                sum += down - peak; // Add the difference to the sum
            }
        }

        return sum; // Return the total number of candies required
    }

        //+++++++++++++ Better Solution +++++++++++++++
        //     int n = ratings.size(); // Size of the given vector

        //     // Arrays to store candies given to left and right neighbors
        //     int left[n];  // Array to store candies given to left neighbors
        //     int right[n]; // Array to store candies given to right neighbors

        //     left[0] = 1;      // The first child gets 1 candy by default
        //     right[n - 1] = 1; // The last child gets 1 candy by default

        //     // Traverse from left to right to assign candies based on ratings
        //     for (int i = 1; i < n; i++) {
        //         if (ratings[i] > ratings[i - 1]) {
        //             left[i] = left[i - 1] + 1; // Give more candies if rating
        //             is
        //                                        // higher than the left
        //                                        neighbor
        //         } else {
        //             left[i] = 1; // Otherwise, give 1 candy
        //         }
        //     }

        //     int sum = max(
        //         1, left[n - 1]); // Initialize sum with candies for the last
        //         child

        //     int current = 1; // Current candies count for the right pass
        //     int r = 1; // Variable to store the maximum candies for the right
        //     pass

        //     // Traverse from right to left to assign candies based on ratings
        //     for (int i = n - 2; i >= 0; i--) {
        //         if (ratings[i] > ratings[i + 1]) {
        //             current = current + 1; // if condition satisfied increase
        //             the current r = current; // and assign current to right
        //         } else {
        //             current = 1;
        //         }

        //         sum = sum +
        //               max(left[i],
        //                   current); // Accumulate the maximum candies for
        //                   each child
        //     }

        //     return sum; // Return the total number of candies required
        // }
        // +++++++++++++ Brute Force ++++++++++++++
        //     int n = ratings.size(); // Size of the given vector

        //     int left[n];  // Array to store candies given to left neighbors
        //     int right[n]; // Array to store candies given to right neighbors

        //     left[0] = 1;      // The first child gets 1 candy by default
        //     right[n - 1] = 1; // The last child gets 1 candy by default

        //     // Traverse from left to right to assign candies based on ratings
        //     for (int i = 1; i < n; i++) {
        //         if (ratings[i] > ratings[i - 1]) {
        //             left[i] = left[i - 1] + 1; // Give more candies if rating
        //             is
        //                                        // higher than the left
        //                                        neighbor
        //         } else {
        //             left[i] = 1; // Otherwise, give 1 candy
        //         }
        //     }

        //     // Traverse from right to left to assign candies based on ratings
        //     for (int i = n - 2; i >= 0; i--) {
        //         if (ratings[i] > ratings[i + 1]) {
        //             right[i] = right[i + 1] + 1; // Give more candies if
        //             rating is
        //                                          // higher than the right
        //                                          neighbor
        //         } else {
        //             right[i] = 1; // Otherwise, give 1 candy
        //         }
        //     }

        //     int sum = 0;

        //     // Calculate the total number of candies required
        //     for (int i = 0; i < n; i++) {
        //         sum = sum +
        //               max(left[i],
        //                   right[i]); // Add the maximum candies given to each
        //                   child
        //     }

        //     return sum; // Return the total number of candies required
        // }
    };
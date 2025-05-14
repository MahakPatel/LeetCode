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
};
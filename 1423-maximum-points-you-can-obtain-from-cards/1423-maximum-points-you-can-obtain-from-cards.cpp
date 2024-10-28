class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); // Size of the card points array
        int lsum = 0; // Left sum
        int rsum = 0; // Right sum
        int totalSum = 0; // Variable to store the maximum score

        // Calculate the initial left sum for the first 'k' cards
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i]; // Add the first 'k' elements to lsum
        }

        totalSum = lsum; // Set totalSum to the initial left sum

        // Iterate to calculate the right sum by moving cards from the right end
        for (int i = 0; i < k; i++) {
            // Update the left sum by removing the last card picked from the left
            lsum -= cardPoints[k - 1 - i]; // Remove the (k-1-i)th card from the left
            // Update the right sum by adding the (n-1-i)th card from the right
            rsum += cardPoints[n - 1 - i]; // Add the (n-1-i)th card from the right

            // Update the total sum to the maximum of current total or the new configuration
            totalSum = max(totalSum, lsum + rsum);
        }

        return totalSum; // Return the maximum score achievable
    }
};

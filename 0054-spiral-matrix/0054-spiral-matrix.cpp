class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();    // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix

        vector<int> ans; // Vector to store the spiral order of elements

        // Define the boundaries for traversal
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;

        // Continue until all boundaries converge
        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down

            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left

            // Ensure there are still rows left to process
            if (top <= bottom) {
                // Traverse from right to left along the bottom boundary
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }

            // Ensure there are still columns left to process
            if (left <= right) {
                // Traverse from bottom to top along the left boundary
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }

        return ans; // Return the vector containing elements in spiral order
    }
};
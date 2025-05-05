class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Binary Serach - Optimal Solution
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int column = m - 1;

        while (row < n && column >= 0) {
            if (matrix[row][column] == target)
                return true;
            if (matrix[row][column] < target) {
                row++;
            } else {
                column--;
            }
        }

        return false;
    }
};
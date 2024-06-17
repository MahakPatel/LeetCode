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

    // ++++++++++ Brute Force Approch +++++++++++
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (matrix[i][j] == target) {
    //                 return true;
    //             }
    //         }
    //     }

    //     return false;
    // }

    // +++++++++++++ Better Solution +++++++++++++++

    //   bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n = matrix.size();

    //     for (int i = 0; i < n; i++) {
    //         bool flag = binarySearch(matrix[i], target);
    //         if (flag)
    //             return true;
    //     }
    //     return false;
    // }

    // bool binarySearch(vector<int>& nums, int target) {
    //     int n = nums.size(); // size of the array
    //     int low = 0, high = n - 1;

    //     // Perform the steps:
    //     while (low <= high) {
    //         int mid = (low + high) / 2;
    //         if (nums[mid] == target)
    //             return true;
    //         else if (target > nums[mid])
    //             low = mid + 1;
    //         else
    //             high = mid - 1;
    //     }
    //     return false;
    // }
};
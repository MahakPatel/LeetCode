class Solution {
public:

//++++++++++++ Optimal Solution - Binary Search +++++++++
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        int high =(n*m -1);

        while(low <= high){
            int mid = (low+high)/2;

            int row = mid/m;
            int column = mid%m;

            if(matrix[row][column] == target){
                return true;
            }

            if(matrix[row][column] <= target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return false;
    }


//++++++++++++++++= Brute Force Approch ++++++++++++++
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int n = matrix.size(), m = matrix[0].size();

//     //traverse the matrix:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == target)
//                 return true;
//         }
//     }
//     return false;
// }


// +++++++++++ Better Solution ++++++++++++

// bool binarySearch(vector<int>& nums, int target) {
//     int n = nums.size(); //size of the array
//     int low = 0, high = n - 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }
};
class Solution {
public:
    // void markRow(vector<vector<int>>& matrix, int i, int m) {
    //     // Mark the entire row i as needing to be zeroed
    //     for (int j = 0; j < m; j++) {
    //         if (matrix[i][j] != 0) {
    //             matrix[i][j] = -1; // Use -1 as a marker to indicate the cell
    //                                // needs to be zeroed
    //         }
    //     }
    // }

    // void markColumn(vector<vector<int>>& matrix, int j, int n) {
    //     // Mark the entire column j as needing to be zeroed
    //     for (int i = 0; i < n; i++) {
    //         if (matrix[i][j] != 0) {
    //             matrix[i][j] = -1; // Use -1 as a marker to indicate the cell
    //                                // needs to be zeroed
    //         }
    //     }
    // }
    void setZeroes(vector<vector<int>>& matrix) {

        // +++++++++++++++++++ Optimal Solution ++++++++++++++++++++
        int n = matrix.size();    // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix

        int col0 = 1; // Flag to track if the first column should be zeroed

        // First pass: Mark rows and columns that need to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the first cell of the row

                    // If the zero is in the first column, set col0 flag to 0
                    if (j != 0) {
                        matrix[0][j] = 0; // Mark the first cell of the column
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        // Second pass: Set cells to zero based on markers
        for (int i = 1; i < n; i++) { // Start from 1 to avoid the first row
            for (int j = 1; j < m;
                 j++) { // Start from 1 to avoid the first column
                if (matrix[i][j] != 0) {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0; // Set the cell to zero if its row or
                                          // column is marked
                    }
                }
            }
        }

        // Zero out the first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0; // Set all cells in the first row to zero
            }
        }

        // Zero out the first column if needed
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0; // Set all cells in the first column to zero
            }
        }
    }

    // +++++++++++++++++ Better Solution ++++++++++++++++++++++

    //     // Create vectors to track which rows and columns need to be
    //     zeroed vector<int> row(n,0); // Vector to mark rows with zeros;
    //     initialized to 0 vector<int> col(m, 0); // Vector to mark columns
    //     with zeros; initialized to 0

    //     // Traverse the matrix to identify rows and columns that contain
    //     zeros for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (matrix[i][j] == 0) {
    //                 row[i] = 1; // Mark the row index i as needing to be
    //                 zeroed col[j] = 1; // Mark the column index j as
    //                 needing to be zeroed
    //             }
    //         }
    //     }

    //     // Traverse the matrix again to set the appropriate cells to zero
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (row[i] || col[j]) { // Check if either the row or
    //             column is marked
    //                 matrix[i][j] = 0; // Set the cell to zero
    //             }
    //         }
    //     }
    // }

    // ++++++++++++++++ Brute Force +++++++++++++++++

    //     // First pass: Mark rows and columns that need to be zeroed
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (matrix[i][j] == 0) {
    //                 markRow(matrix, i, m);    // Mark the entire row i
    //                 markColumn(matrix, j, n); // Mark the entire column j
    //             }
    //         }
    //     }

    //     // Second pass: Set the marked cells to zero
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (matrix[i][j] == -1) {
    //                 matrix[i][j] = 0; // Set the marked cells to zero
    //             }
    //         }
    //     }
    // }
};
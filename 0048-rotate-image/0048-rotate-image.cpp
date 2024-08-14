class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Get the size of the matrix (n x n)

    // Step 1: Transpose the matrix (convert rows to columns)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap elements at (i, j) and (j, i) to transpose the matrix
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row to achieve the 90-degree rotation
    for (int i = 0; i < n; i++) {
        // Reverse the elements in the current row
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

};
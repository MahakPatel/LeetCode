class Solution {
public:
    // Function to generate a specific row of Pascal's Triangle
    vector<int> generateRow(int row) {
        long long ans = 1; // Initialize to 1 (C(row, 0))
        vector<int> ansRow;
        ansRow.push_back(1); // The first element of every row is 1

        // Compute the rest of the elements in the row using binomial
        // coefficients
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }

        return ansRow;
    }

    // Function to generate the first numRows of Pascal's Triangle
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        // Generate each row and add it to the answer
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};
class Solution {
private:
    // Depth-first search to fill the pixels
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int originalColor, int newColor, int delRow[], int delCol[]) {
        // Fill the current pixel with the new color
        ans[row][col] = newColor;
        
        int n = image.size();       // Number of rows in the image
        int m = image[0].size();    // Number of columns in the image

        // Explore all four possible directions (up, right, down, left)
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i]; // New row index
            int nCol = col + delCol[i]; // New column index

            // Check if the new position is valid and has the original color
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                image[nRow][nCol] == originalColor && 
                ans[nRow][nCol] != newColor) {
                // Recursively call dfs for the adjacent pixel
                dfs(nRow, nCol, ans, image, originalColor, newColor, delRow, delCol);
            }
        }
    }

public:
    // Main function to perform flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Get the original color of the pixel at (sr, sc)
        int originalColor = image[sr][sc];

        // If the new color is the same as the original color, no need to fill
        if (originalColor == color) return image;

        // Create a copy of the image to store the result
        vector<vector<int>> ans = image;

        // Directions for adjacent cells (up, right, down, left)
        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};

        // Start DFS from the starting pixel
        dfs(sr, sc, ans, image, originalColor, color, dRow, dCol);

        return ans; // Return the modified image
    }
};
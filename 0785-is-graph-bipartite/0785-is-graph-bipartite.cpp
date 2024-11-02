class Solution {
private:
    // DFS function to color the graph
    bool dfs(int node, int col, vector<int>& color, const vector<vector<int>>& graph) {
        color[node] = col; // Color the current node with the given color

        // Iterate through all adjacent nodes
        for (auto it : graph[node]) {
            // If the adjacent node has not been colored
            if (color[it] == -1) {
                // Recursively call dfs for the adjacent node with the alternate color
                if (!dfs(it, !col, color, graph)) return false; // If coloring fails, return false
            } 
            // If the adjacent node is already colored with the same color, the graph is not bipartite
            else if (color[it] == col) return false;
        }

        return true; // Return true if the coloring is successful
    }

public:
    // Function to check if the graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size(); // Get the number of vertices in the graph
        vector<int> color(v, -1); // Array to store colors of vertices, initialized to -1 (uncolored)

        // Iterate through each vertex
        for (int i = 0; i < v; i++) {
            // If the vertex is not colored
            if (color[i] == -1) {
                // Call dfs to color the connected component
                if (!dfs(i, 0, color, graph)) return false; // If dfs returns false, graph is not bipartite
            }
        }

        return true; // If all components are successfully colored, return true
    }
};

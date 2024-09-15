class Solution {
private:
    // Recursive DFS function
    void dfs(int node, vector<int> adjList[], vector<int>& vis) {
        // Mark the current node as visited
        vis[node] = 1;
        // Visit all adjacent nodes
        for (auto it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }

public:
    // Function to find the number of connected components in the graph
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size(); // Number of vertices

        // Initialize adjacency list for the graph
        vector<int> adjList[v];

        // Build the adjacency list from the isConnected matrix
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Initialize visited array
        vector<int> vis(v, 0);
        int count = 0;

        // Perform DFS for each unvisited node
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                count++; // Increment count for each connected component
                dfs(i, adjList, vis);
            }
        }

        return count; // Return the number of connected components
    }
};

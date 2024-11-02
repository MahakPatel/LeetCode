class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size(); // Get the number of vertices
        vector<vector<int>> adjRev(V); // Adjacency list for the reversed graph
        vector<int> indegree(V, 0); // Initialize indegree array to 0 for all vertices
        
        // Build the reversed graph and calculate indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) { // Use the correct reference to graph
                adjRev[it].push_back(i); // Reverse the edge
                indegree[i]++; // Increment the indegree of the original node
            }
        }
        
        queue<int> q; // Queue to process nodes with indegree 0
        vector<int> safeNode; // Vector to store safe nodes

        // Push all nodes with indegree 0 into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the nodes in the queue
        while (!q.empty()) {
            int node = q.front(); // Get the front node
            q.pop(); // Remove the front node

            safeNode.push_back(node); // Add the node to the list of safe nodes

            // Decrease the indegree of adjacent nodes in the reversed graph
            for (auto it : adjRev[node]) {
                indegree[it]--; // Decrease the indegree by 1

                // If indegree becomes 0, push it into the queue
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Sort the list of safe nodes before returning
        sort(safeNode.begin(), safeNode.end());

        return safeNode; // Return the list of safe nodes
    }
};


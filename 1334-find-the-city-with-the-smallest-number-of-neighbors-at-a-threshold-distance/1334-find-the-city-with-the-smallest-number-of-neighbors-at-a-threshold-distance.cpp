class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(
            n, vector<int>(n, 1e9)); // Initialize the distance matrix with
                                     // large values (infinity)

        // Set the distance from a city to itself as 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0; // The distance from a city to itself is always 0
        }

        // Fill the distance matrix with the direct distances from the edges
        for (auto it : edges) {
            int u = it[0];               // City u
            int v = it[1];               // City v
            int w = it[2];               // Distance between u and v
            dist[u][v] = dist[v][u] = w; // Since it's an undirected graph
        }

        // Apply Floyd-Warshall algorithm to find the shortest paths between all
        // pairs of cities
        for (int k = 0; k < n; k++) { // For each possible intermediate city k
            for (int i = 0; i < n; i++) {     // For each start city i
                for (int j = 0; j < n; j++) { // For each destination city j
                    if (dist[i][k] != 1e9 &&
                        dist[k][j] !=
                            1e9) { // If both i -> k and k -> j are reachable
                        dist[i][j] = min(
                            dist[i][j],
                            (dist[i][k] + dist[k][j])); // Update the shortest
                                                        // path from i to j
                    }
                }
            }
        }

        int res = -1;       // Initialize the result variable
        int mini = INT_MAX; // To store the minimum number of reachable cities

        // Find the city with the smallest number of cities reachable within the
        // distance threshold
        for (int i = 0; i < n; i++) {
            int city = 0; // Count of cities reachable from city i

            // Count the number of cities reachable from city i within the
            // distance threshold
            for (int j = 0; j < n; j++) {
                if (i != j &&
                    dist[i][j] <= distanceThreshold) { // Check if city j is
                                                       // reachable from city i
                    city++; // Increment the reachable cities counter
                }
            }

            // If this city has fewer reachable cities, update the result
            if (city <= mini) {
                mini = city;
                res = i;
            }
        }

        return res; // Return the city with the smallest number of reachable
                    // cities
    }
};
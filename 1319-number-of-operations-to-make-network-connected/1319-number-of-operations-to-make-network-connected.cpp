class DisjointSet {
public:
    vector<int> rank, parent, size;

    // Constructor to initialize parent and size
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Initially, each node is its own parent
        }
    }

    // Find operation with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node; // Return node if it is its own parent
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    // Union operation by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); // Ultimate parent of u
        int ulp_v = findUPar(v); // Ultimate parent of v
        if (ulp_u == ulp_v)
            return; // Already in the same set, no need to union

        // Union the smaller set into the larger set
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int countExtra = 0;

        // Process each edge
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            // If u and v already have the same parent, it's an extra edge
            if (ds.findUPar(u) == ds.findUPar(v)) {
                countExtra++;
            } else {
                ds.unionBySize(u, v); // Union the sets
            }
        }

        int countC = 0;
        // Count the number of connected components
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                countC++;
            }
        }

        int ans = countC - 1;

        // If the number of extra edges equals the number of required edges to
        // connect components, return the answer
        if (ans <= countExtra)
            return ans;

        // Return -1 if it's not possible to connect all components
        return -1;
    }
};
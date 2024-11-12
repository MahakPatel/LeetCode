class DisjointSet {
    vector<int> rank, parent, size;  // Vectors for rank, parent, and size of each node in the disjoint set
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);  // Initialize rank of all nodes to 0
        parent.resize(n + 1);    // Initialize parent of each node
        size.resize(n + 1);      // Initialize size of each set to 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Each node is initially its own parent
            size[i] = 1;    // Each set initially contains one element
        }
    }

    // Function to find the ultimate parent of a node (with path compression)
    int findUPar(int node) {
        if (node == parent[node])  // If the node is its own parent, return it
            return node;
        return parent[node] = findUPar(parent[node]);  // Path compression
    }

    // Union by rank (attach smaller rank tree to the larger rank tree)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);  // Find ultimate parent of u
        int ulp_v = findUPar(v);  // Find ultimate parent of v
        if (ulp_u == ulp_v) return;  // If both have the same parent, no need to unite

        // Attach the tree with the smaller rank to the tree with larger rank
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;  // If both trees have the same rank, increment the rank of the root
        }
    }

    // Union by size (attach smaller size tree to the larger size tree)
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);  // Find ultimate parent of u
        int ulp_v = findUPar(v);  // Find ultimate parent of v
        if (ulp_u == ulp_v) return;  // If both have the same parent, no need to unite

        // Attach the tree with the smaller size to the tree with larger size
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Update the size of the root
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  // Update the size of the root
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        // Find the maximum row and column values from the stones list
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Initialize disjoint set with a size large enough to accommodate all rows and columns
        DisjointSet ds(maxCol + maxRow + 1);

        unordered_map<int, int> stoneNodes;
        // Union the rows and columns for each stone
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;  // Offset column index to avoid overlap with rows

            ds.unionBySize(nodeRow, nodeCol);  // Union the row and column
            stoneNodes[nodeRow] = 1;  // Mark the row as a stone node
            stoneNodes[nodeCol] = 1;  // Mark the column as a stone node
        }

        int count = 0;

        // Count how many distinct connected components there are by checking the ultimate parent of each stone
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                count++;  // Count distinct components
            }
        }

        // The result is the total number of stones minus the number of distinct components
        return n - count;
    
    }
};
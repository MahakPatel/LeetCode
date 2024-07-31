class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(); // size pf greed
        int m = s.size(); // size of cookies

        // Sort the greed factors in ascending
        // order to try and satisfy the
        // least greedy children first
        sort(g.begin(), g.end());
        // Sort the cookie sizes in ascending
        // order to use the smallest cookies first
        sort(g.begin(), g.end());

        // Initialize a pointer for the
        // cookieSize array, starting
        // from the first cookie
        int l = 0;

        // Initialize a pointer for the
        // greed array, starting from
        // the first child
        int r = 0;

        while (l < m && r < n) {
            // If the current cookie can
            // satisfy the current child's greed
            if (g[r] <= s[l]) {
                // Move to the next child,
                // as the current child is satisfied
                r = r + 1;
            }
            // Always move to the next cookie
            // whether the current child
            // was satisfied or not
            l = l + 1;
        }
        // The value of r at the end of
        // the loop represents the number
        // of children that were satisfied
        return r;
    }
};
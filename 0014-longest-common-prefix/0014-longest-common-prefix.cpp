class Solution {
public:
    // ++++++++++++++ Optimal Solution +++++++++++++++
    // TC O(nlogn + m) m = length of prefix
    // SC O(1)
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        // Sort the strings lexicographically
        sort(strs.begin(), strs.end());

        int n = strs.size();

        // First and last strings in sorted order
        string first = strs[0], last = strs[n - 1];

        // Compare characters of first and last string
        for (int i = 0; i < last.size(); i++) {
            if (first[i] != last[i]) {
                return ans; // Return common prefix found so far
            }
            ans += first[i]; // Append matching character to result
        }

        return ans; // Return the longest common prefix
    }
};
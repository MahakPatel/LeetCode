class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string s, int start, int end) {
        // Compare characters from both ends moving towards the center
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false; // Return false if characters don't match
            }
        }
        return true; // Return true if the substring is a palindrome
    }

    // Recursive function to find all possible palindrome partitions
    void func(int index, string s, vector<vector<string>>& ans,
              vector<string>& path) {
        // Base case: if index reaches the end of the string, add the current
        // partition to the result
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        // Loop through the string from the current index to the end
        for (int i = index; i < s.size(); i++) {
            // Check if the substring from index to i is a palindrome
            if (isPalindrome(s, index, i)) {
                // If palindrome, add the substring to the current partition
                // (path)
                path.push_back(s.substr(index, i - index + 1));

                // Recursively call the function for the remaining string
                // starting from index i+1
                func(i + 1, s, ans, path);

                // Backtrack by removing the last added palindrome substring
                path.pop_back();
            }
        }
    }
    // Function to find all palindrome partitions of the given string
    vector<vector<string>> partition(string s) {
        vector<vector<string>>
            ans;             // To store the result (all palindrome partitions)
        vector<string> path; // To store the current partition being formed

        // Call the recursive function to find all palindrome partitions
        // starting from index 0
        func(0, s, ans, path);

        return ans; // Return the list of all palindrome partitions
    }
};
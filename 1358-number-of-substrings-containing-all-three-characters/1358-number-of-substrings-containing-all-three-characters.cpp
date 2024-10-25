class Solution {
public:
    // ++++++++++++++++++++++ Brute Force ++++++++++++++++++++
    // int numberOfSubstrings(string s) {
    //     int n = s.length(); // Length of the input string
    //     int count = 0; // Variable to store the count of valid substrings

    //     // Iterate through each character in the string
    //     for (int i = 0; i < n; i++) {
    //         map<char, int> mp; // Map to count occurrences of characters
    //         // Iterate through the substring starting from index i
    //         for (int j = i; j < n; j++) {
    //             mp[s[j]] = 1; // Mark the presence of the character s[j]

    //             // Check if all three characters 'a', 'b', and 'c' are
    //             present if (mp['a'] + mp['b'] + mp['c'] == 3) {
    //                 count = count + 1; // Increment the count of valid
    //                 substrings
    //             }
    //         }
    //     }

    //     return count; // Return the total count of valid substrings
    // }
    int numberOfSubstrings(string s) {
        int n = s.length(); // Length of the input string
        int lastSeen[3] = {-1, -1, -1}; // Array to store the last seen indices of 'a', 'b', and 'c'
        int count = 0; // Variable to store the count of valid substrings

        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            // Update the last seen index for the current character
            lastSeen[s[i] - 'a'] = i; // Convert character to index (0 for 'a', 1 for 'b', 2 for 'c')

            // Calculate the minimum last seen index of 'a', 'b', and 'c'
            int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]}); // Using initializer list for min with three values
            
            // If all characters have been seen at least once, add valid substrings to count
            if (minIndex != -1) { // Check if all characters have been seen
                count += minIndex + 1; // Add the number of valid substrings ending at index 'i'
            }
        }

        return count; // Return the total count of valid substrings
    }
};


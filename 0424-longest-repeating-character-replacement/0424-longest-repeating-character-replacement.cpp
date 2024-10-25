class Solution {
public:

// +++++++++++++++++++ Brute Force ++++++++++++++++++++++++++++
    // int characterReplacement(string s, int k) {
    //     int n = s.length(); // Length of the input string
    //     int maxLen = 0;     // Variable to store the maximum length of the
    //     substring

    //     for (int i = 0; i < n; i++) {
    //         // Initialize the frequency map for the current starting point
    //         map<char, int> mp; // Use char as the key for character counts
    //         int maxFrequency = 0; // Track the maximum frequency of any
    //         character

    //         for (int j = i; j < n; j++) {
    //             // Increment the count for the current character
    //             mp[s[j]]++;
    //             maxFrequency = max(maxFrequency, mp[s[j]]); // Update the max
    //             frequency

    //             // Calculate the number of changes needed
    //             int changes = (j - i + 1) - maxFrequency;

    //             // If changes needed are within the allowed limit
    //             if (changes <= k) {
    //                 maxLen = max(maxLen, (j - i + 1)); // Update the maximum
    //                 length
    //             } else {
    //                 break; // If changes exceed k, exit the loop
    //             }
    //         }
    //     }

    //     return maxLen; // Return the maximum length found
    // }

// +++++++++++++++++++ Better Solution ++++++++++++++++++++++++++++
//     int characterReplacement(string s, int k) {
//         int n = s.length(); // Length of the input string
//         int left = 0; // Left pointer for the sliding window
//         int right = 0; // Right pointer for the sliding window
//         map<char, int> mp; // Map to count occurrences of each character
//         int maxLen = 0; // Variable to store the maximum length of the substring
//         int maxFre = 0; // Variable to store the maximum frequency of any character in the current window

//         // Iterate through the string with the right pointer
//         while (right < n) {
//             // Increment the count for the current character
//             mp[s[right]]++;
//             // Update the maximum frequency of any character in the current window
//             maxFre = max(maxFre, mp[s[right]]);

//             // Check if the number of characters that need to be changed exceeds k
//             while ((right - left + 1) - maxFre > k) {
//                 // Decrease the count of the character at the left pointer
//                 mp[s[left]]--;
//                 // Reset maxFre to 0 and find the new maximum frequency
//                 maxFre = 0;
//                 for (int i = 0; i < 26; i++) { // Corrected range to 26 for uppercase letters
//                     maxFre = max(maxFre, mp[i]); // Update maxFre based on current frequencies
//                 }
//                 left++; // Move the left pointer to the right
//             }

//             // Calculate the length of the current valid window and update maxLen
//             if ((right - left + 1) - maxFre <= k) {
//                 maxLen = max(maxLen, right - left + 1); // Update the maximum length found
//             }

//             // Move the right pointer to the right
//             right++;
//         }

//         return maxLen; // Return the maximum length found
//     }
// };
// +++++++++++++++++++  Optimal Solution  ++++++++++++++++++++++++++++
    int characterReplacement(string s, int k) {
        int n = s.length(); // Length of the input string
        int left = 0;       // Left pointer for the sliding window
        int right = 0;      // Right pointer for the sliding window
        map<char, int> mp;  // Map to count the frequency of characters
        int maxLen = 0;     // Maximum length of the substring found
        int maxFre =
            0; // Maximum frequency of any character in the current window

        while (right < n) { // Iterate until the right pointer reaches the end
                            // of the string
            mp[s[right]]++; // Increment the count of the current character in
                            // the map
            maxFre = max(
                maxFre,
                mp[s[right]]); // Update the maximum frequency of any character

            // If the number of characters that need to be changed exceeds k
            if ((right - left + 1) - maxFre > k) {
                mp[s[left]]--; // Decrease the count of the character at the
                               // left pointer
                left++; // Move the left pointer to the right to shrink the
                        // window
            }

            // Update the maximum length of the valid substring
            if ((right - left + 1) - maxFre <= k) {
                maxLen = max(maxLen,
                             right - left + 1); // Calculate the current window
                                                // size and update maxLen
            }

            right++; // Move the right pointer to the right to expand the window
        }

        return maxLen; // Return the maximum length of the substring found
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        //     int flag = 0;
        //     if (s == " ") {
        //         return true;
        //     }

        //     transform(s.begin(), s.end(), s.begin(), ::tolower);

        //    // s.erase(remove(s.begin(), s.end(), ' '), s.end());
        //     s.erase(remove(s.begin(), s.end(), ','), s.end());
        //     s.erase(remove(s.begin(), s.end(), ':'), s.end());

        //     for (int i = 0; i < s.length() / 2; i++) {
        //         if (s[i] != s[s.length() - i - 1]) {
        //             flag = 1;
        //         }
        //     }

        //     cout<<s;

        //     flag = 0;

        //     if (flag)
        //         return true;
        //     return false;

        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(s[right])) {
                right--;
            }
            // If characters don't match (ignoring case), it's not a palindrome
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            // If they match, move both pointers inward
            else {
                left++;
                right--;
            }
        }

        return true; // If loop completes, it's a palindrome
    }
};
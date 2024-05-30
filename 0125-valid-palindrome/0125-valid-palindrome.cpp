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
        if(!isalnum(s[left])){
                left++;
        }
        else if (!isalnum(s[right])){
                right--;
        }        
        else if( tolower(s[left]) != tolower(s[right]) ){
                return false;
        }
        else{
                ++left;
                --right;
        }
    }
        return true;
    }
};
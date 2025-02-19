class Solution {
public:
    // ++++++++++++ Brute Force +++++++++++++++++++
    // TC O(nlogn + mlogm)
    // SC O(1)
    // bool isAnagram(string s, string t) {
    //     // if length is not same then it is not an Anagram
    //     if(s.length() != t.length()){
    //         return false;
    //     }

    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     // after sorting if it is same then it is Anagram
    //     return s==t;
    // }


    // ++++++++++++ Brute Force +++++++++++++++++++
    // TC O(n)
    // SC O(1)
    bool isAnagram(string s, string t) {
        // if length is not same then it is not an Anagram
        if(s.length() != t.length()){
            return false;
        }


        unordered_map<char,int> stringS; // create unordered map for s and add character and count
        unordered_map<char,int> stringT;// create unordered map for t and add character and count
        int n = s.length();
        for(int i=0;i<n;i++){
            stringS[s[i]]++; // add s character in map
            stringT[t[i]]++; // add t character in map
        }

        return stringS == stringT; // if both same return true
    }
};
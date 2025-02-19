class Solution {
public:
    // +++++++++++++ Optimal Solution +++++++++++++
    // TC O(n)
    // SC O(1)
    void reverseString(vector<char>& s) {
        int a=0,e=s.size()-1;
        while(a<e){
            swap(s[a],s[e]);
            a++;
            e--;
        }
        
    }
};
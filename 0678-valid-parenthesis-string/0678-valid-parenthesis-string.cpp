class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0; // for to maintain range
 
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') { // if '('
                min += 1; // increase min range by 1
                max += 1; // increase max range by 1
            } else if (s[i] == ')') {// if ')'
                min -= 1;// descrease min range by 1
                max -= 1; // descrease max range by 1

            } else { // if '*' then
                min -= 1; // here we are descring range of min by 1
                max += 1; // here we are increasing range of max by 1
            }

            if(min < 0) min =0; // if any time range of min is less then 0 then assign min = 0

            if(max < 0) return false; // max range can never be a less then zero
        }

        return (min ==0); // if min value is 0 then return true
    }
};
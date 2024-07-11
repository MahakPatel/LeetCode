class Solution {
public:
    bool isValid(string s) {
        int n = s.length();

        stack<int> st;

        for (int i = 0; i < n; i++) {
            if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) { // if opening bracket push into stack
                st.push(s[i]);
            } else {
                if (st.empty()) { // if stack is empty return false
                    return false; 
                } 
                char c = st.top();// store the top element of stack into c  
                st.pop();

                if ((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') ||
                    (s[i] == ']' && c == '[')) { // now check current closing breacket is same with the top of the stackl element 
                    continue;
                } else {
                    return false; // otgerwise return false
                }
            }
        }

        if (st.empty()) { // after interation if stack is empty then return true
            return true;
        }

        return false;
    }
};
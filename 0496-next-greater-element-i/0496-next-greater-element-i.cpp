class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nge(n2, -1);
        unordered_map<int, int> nge_map;
        stack<int> st;

        for (int i = n2 - 1; i >= 0; i--) { // start with back side of array
            while (!st.empty() && st.top() <= nums2[i]) { // pop the element untill top value of stack is less then number
                st.pop();
            }

            if (!st.empty()) {
                nge_map[nums2[i]] = st.top(); // if stack is not empty put the top value in to the nge
            } else {
                nge_map[nums2[i]] = -1; // other wise put -1 in nge
            }

            st.push(nums2[i]); // push element in stack
        }

        vector<int> result(n1);
        for (int i = 0; i < n1; i++) {
            result[i] = nge_map[nums1[i]];
        }

        return result;
    }
};

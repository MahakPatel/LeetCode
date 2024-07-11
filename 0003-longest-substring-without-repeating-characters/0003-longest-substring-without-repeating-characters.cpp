class Solution {
public:
    int lengthOfLongestSubstring(string str) {

        // ++++++++++= Without two pointer ++++++++++
        //     if (str.size() == 0)
        //         return 0;
        //     int maxans = INT_MIN;
        //     for (int i = 0; i < str.length();i++) // outer loop for
        //     traversing the string
        //     {
        //         unordered_set<int> set;
        //         for (int j = i; j < str.length();
        //              j++) // nested loop for getting different string
        //              starting with
        //                   // str[i]
        //         {
        //             if (set.find(str[j]) !=
        //                 set.end()) // if element if found so mark it as ans
        //                 and
        //                            // break from the loop
        //             {
        //                 maxans = max(maxans, j - i);
        //                 break;
        //             }
        //             set.insert(str[j]);
        //         }
        //     }
        //     return maxans;
        // }

        //  +++++++++++++++++++ Using two index +++++++++++++++++

        vector<int> mpp(256, -1); // create one map(hashmap)

        int left = 0, right = 0; // take left and right index at 0th index
        int n =  str.size();
        int len = 0;
        while (right < n) {          // run till right is less then n
            if (mpp[str[right]] != -1) // if string present in the map then
                left = max(mpp[str[right]] + 1, left); // place left index at current index

                mpp[str[right]] = right; // put the right index into the map

            len = max(len, right - left + 1); // find the max length of the substring 
            right++;                // increase the right index
        }
        return len;
    }
};
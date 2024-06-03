class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;

        for (int i = 0; i < nums.size(); i++) {
            xorr = xorr ^
                   nums[i]; // xor with same value return 0 , 2^ 2 =0, 0^ 2 = 2
        }

        return xorr;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // XOR Approch

        int xor1 = 0, xor2 = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            xor2 = xor2 ^ nums[i]; // first do xor with given element
            xor1 = xor1 ^ i;       // then do xor with 0 to N element
        }

        xor1 = xor1 ^ n; // do xor with the n(above loop is for n-1 element only
                         // that why this step require)

        return xor1 ^ xor2; // finally do xor1 with xor2

        // ++++++++++++++++++++++++++++++++++++++++++++++

        // solved using sum of n natural number - sum of given element of
        // array int n = nums.size();

        // // sum of n natural number
        // int sum1 = (n * (n + 1)) / 2;
        // int sum2 = 0;

        // for (int i = 0; i < n; i++) {
        //     sum2 = sum2 + nums[i];
        // }

        // return sum1 - sum2;
    }
};
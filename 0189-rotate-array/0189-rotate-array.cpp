class Solution {
public:
    void rotate(vector<int>& nums, int k) { // right rotate
        // optimal approch
        int n = nums.size();
        k = k % n;
        reverse(nums.begin() + (n - k),
                nums.begin() + n); // stepn 1 :first reverse k element
        reverse(
            nums.begin(),
            (nums.begin() + (n - k))); // sterp 2 :reverse rest of the elements
        reverse(
            nums.begin(),
            (nums.begin() + n)); // after step 1 and step 2 reverse entire array
    }

    // left rotate

    // // optimal approch

    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     reverse(nums.begin(),nums.begin()+k); // stepn 1 :first reverse k
    //     element reverse(nums.begin()+k,nums.begin()+n); // sterp 2 :reverse
    //     rest of the elements reverse(nums.begin(),nums.begin()+n); // after
    //     step 1 and step 2 reverse entire array

    // }

    // Brute - Force Approch

    //         void rotate(vector<int>& nums, int k) {
    //             int n= nums.size();
    //         k = k%n; // this is because it say array size is 7 and d  is also
    //         7
    //         //so there is no need of rotate because after 7 rotation array
    //         will be same so just we need to rorate % part

    //             vector<int> temp;

    //             for(int i=0;i<k;i++){
    //                 temp.push_back(nums[i]);
    //             }

    //             for(int i=k;i<n;i++){
    //                 nums[i-k]=nums[i];
    //             }

    //             for(int i=n-k;i<n;i++){
    //                 nums[i]=temp[i-(n-k)];
    //             }

    // }
};
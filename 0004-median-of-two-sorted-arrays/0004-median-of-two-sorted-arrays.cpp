class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());

        int totalLen = n+m;

        if(totalLen % 2 == 0){
            return ((nums1[totalLen/2 - 1] + nums1[totalLen/2])/2.0); 
        }else{
            return nums1[totalLen/2];
        }
    }
};
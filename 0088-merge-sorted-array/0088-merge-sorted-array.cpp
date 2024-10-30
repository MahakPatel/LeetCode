class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1,k=m+n-1;
        while ( i>=0 && j>=0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
                k--;
            }else {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            // } else {
            //     mergeArr.push_back(nums2[j]);
            //     j++;
            
        }

        while (j>=0) {
                nums1[k] = nums2[j];
            j--;
            k--;
        }

        // while (j < n) {

        // }

        // int s=m+n;
        // int nums3[s];
        // for(int i=0;i<s;i++){
        //     for(int j=0;j<m;j++){
        //         for(int k=0;k<n;k++){
        //             if(nums1[j]<nums2[k]){
        //                 nums3[i]=nums1[j];
        //             }else{
        //                 nums3[i]=nums2[k];
        //             }
        //         }
        //     }

        // }
    }
};
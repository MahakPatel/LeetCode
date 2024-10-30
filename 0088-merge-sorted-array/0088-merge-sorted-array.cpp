class Solution {
public:
    /// ++++++++++++++++++ Brute Force +++++++++++++++++
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
        }

        while (j>=0) {
                nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

    /// ++++++++++++++++ Optimal Solution ++++++++++++++++++++
//     void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
//         if (arr1[ind1] > arr2[ind2]) {
//             swap(arr1[ind1], arr2[ind2]);
//         }
//     }

//     void merge(long long arr1[], long long arr2[], int n, int m) {
//  // len of the imaginary single array:
//     int len = n + m;

//     // Initial gap:
//     int gap = (len / 2) + (len % 2);

//     while (gap > 0) {
//         // Place 2 pointers:
//         int left = 0;
//         int right = left + gap;
//         while (right < len) {
//             // case 1: left in arr1[]
//             //and right in arr2[]:
//             if (left < n && right >= n) {
//                 swapIfGreater(arr1, arr2, left, right - n);
//             }
//             // case 2: both pointers in arr2[]:
//             else if (left >= n) {
//                 swapIfGreater(arr2, arr2, left - n, right - n);
//             }
//             // case 3: both pointers in arr1[]:
//             else {
//                 swapIfGreater(arr1, arr1, left, right);
//             }
//             left++, right++;
//         }
//         // break if iteration gap=1 is completed:
//         if (gap == 1) break;

//         // Otherwise, calculate new gap:
//         gap = (gap / 2) + (gap % 2);
//     }
//     }
// };

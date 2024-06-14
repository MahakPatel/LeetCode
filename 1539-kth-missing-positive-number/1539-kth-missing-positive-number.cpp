class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1); // find the missing number

            if (missing < k) // if misssing number is less then the given number then
                low = mid + 1; // remove left half
            else
                high = mid - 1; // remove  right half
        }

        return low + k; // low = high+1
    }

    // +++++++++++++++ Brute Force ++++++++++++++++
    //     for(int i=0;i<arr.size();i++){
    //         if(arr[i] <= k){
    //             k++;
    //         }else{
    //             break;
    //         }
    //     }

    //     return k;
    // }
};
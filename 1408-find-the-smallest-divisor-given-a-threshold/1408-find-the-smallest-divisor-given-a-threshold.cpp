class Solution {
public:

// func help to find the sum of element/Divsior 
int sumOfDivisor(vector<int>& nums,int Divisor){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum = sum + ceil(((double)(nums[i])/(double)(Divisor)));
    }

    return sum;
} 
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low= 1;
        int high=*max_element(nums.begin(),nums.end());
        int ans = -1;

        while(low<=high){
            int mid=(low+high)/2;

            if(sumOfDivisor(nums,mid) <= threshold){ // if sumOfDivisor is less then or equl to given threshold then replace ans with mid  
                ans = mid;
                high = mid-1; // and remove right side of the array
            }
            else {
                low = mid+1; // or else remove left side of array
            }
        }

        return ans; // you can return low as well because low is always thge ans if we want minimum value
    }


    // ++++++++++++ Brute - Force Approch +++++++++++++

//     int smallestDivisor(vector<int>& arr, int limit) {
//     int n = arr.size(); //size of array.
//     //Find the maximum element:
//     int maxi = *max_element(arr.begin(), arr.end());

//     //Find the smallest divisor:
//     for (int d = 1; d <= maxi; d++) {
//         //Find the summation result:
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             sum += ceil((double)(arr[i]) / (double)(d));
//         }
//         if (sum <= limit)
//             return d;
//     }
//     return -1;
// }
};
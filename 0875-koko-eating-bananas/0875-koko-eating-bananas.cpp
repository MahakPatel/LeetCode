class Solution {
public:

// // find max value of an given array
// int findMax(vector<int>& piles){ 
//     int maxi = INT_MIN;
//     int n=piles.size();

//     for(int i=0;i<n;i++){
//         maxi = max(maxi,piles[i]);
//     }

//     return maxi;
// }


// calculate total hours that require for eating
double calculateHours(vector<int>& piles,int hourly){
    int n= piles.size();
    double totalH = 0;
    for(int i=0;i<n;i++){
        totalH = totalH + ceil((double)piles[i]/(double)hourly);
    }

    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid = (low+high)/2;

            double totalH = calculateHours(piles,mid);  // to find total hours 

            if(totalH <= h){
                 high = mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
    }

// +++++++++++++++ Brute Force Approch ++++++++++++++++
// int minimumRateToEatBananas(vector<int> v, int h) {
//       //Find the maximum number:
//     int maxi = findMax(v);

//     //Find the minimum value of k:
//     for (int i = 1; i <= maxi; i++) {
//         int reqTime = calculateTotalHours(v, i);
//         if (reqTime <= h) {
//             return i;
//         }
//     }

//     //dummy return statement
//     return maxi;
// }
};
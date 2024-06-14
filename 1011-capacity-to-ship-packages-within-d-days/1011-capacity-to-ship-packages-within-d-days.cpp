class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int sum = 0;

        for (int i = 0; i < weights.size(); i++) {
            sum = sum + weights[i];
        }

        int low = *max_element(
            weights.begin(),
            weights.end()); // minimum days require is max element of array
        int high = sum;     // maximum days require is sum of the array

        while (low <= high) {
            int mid = (low + high) / 2;

            if (daysRequired(weights, mid) <=
                days) {         // check for the number of days require
                high = mid - 1; // trim right side of array
            } else {
                low = mid + 1; // trim left side of array
            }
        }

        return low;

        //++++++++++++++++ Brute Force Approch++++++++

        // int max = *max_element(weights.begin(),weights.end());
        //  for(int i=max;i<sum;i++){
        //      int daysRequire = daysRequired(weights,i);

        //     if(daysRequire<=days){
        //         return daysRequire;
        //     }
        // }

        // return -1;
    }

    int daysRequired(vector<int>& weights, int capacity) {
        int day = 1;  // start with day 1
        int load = 0; // starting load = 0

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] >
                capacity) { // if the sum of load and the current weiught is
                            // greater then the capacity then increase the day
                            // and put load in new day
                day = day + 1;
                load = weights[i];
            } else { // or else the put the load in same day
                load = load + weights[i];
            }
        }

        return day;
    }
};
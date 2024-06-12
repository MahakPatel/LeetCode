class Solution {
public:
    bool possible(vector<int>& v, int day, int m, int k) {
        int count = 0;
        int numsOfBouquet = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= day) { // if blooming day is less the the mid(given day)
                               // then increase the count
                count++;
                // if blooming day is greater then given day -m means flower is not bloom
            } else { // otherwise chcek the number of Bouquet and make the count
                     // = 0 again
                numsOfBouquet = numsOfBouquet + (count / k);
                count = 0;
            }
        }
        numsOfBouquet += (count / k); // this is chcek for last remain count

        return numsOfBouquet >= m; // if numsOfBouquet is greater than or equal
                                   // to require Bouquet then return true
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL; // convert int int long long type
        int n = bloomDay.size();

        if (val > n) {
            return -1;
        }

        // to Find the minimum and maximum value from the array
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            // for binary search range
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1; // remove right port of the given array
            } else {
                low = mid + 1; // remove left port of the given array
            }
        }

        return ans; // you can retunn low as well because low is always a answer
    }
};
class Solution {
public:
    double myPow(double x, int n) {

        // ++++++++++++ Brute force +++++++++++

        // int nn = n;

        // if(nn<0) nn = -1 * nn;

        // double ans = 1.0;
        // for (int i = 0; i < nn; i++) {
        //     ans = ans * x;
        // }

        // if (n < 0) {
        //     ans = (double)(1.0) / (double)(ans);
        // }

        // return ans;


        // ++++++++++++++++ Optimal Solution +++++++++++
            double ans = 1.0;
            long long nn = n;
            if (nn < 0) // is n value is negative then convert into positive
                nn = -1 * nn;
            while (nn) { // run till nn value become invalid(0)
                if (nn % 2) { // if (modulo 2 is 0)
                    ans = ans * x; // mul ans with value
                    nn = nn - 1; // ans reduce power by 1
                } else { // otherwise
                    x = x * x; // mul value with itself
                    nn = nn / 2; // and divide power by 2
                }
            }
            if (n < 0) // if n value is negative then ans should be 1/ans;
                ans = (double)(1.0) / (double)(ans);
            return ans;
    }
};
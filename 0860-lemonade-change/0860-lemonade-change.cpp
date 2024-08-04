class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0; // for storing billes

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) // if bill is 5 
                five += 1; // then increase five
            else if (bills[i] == 10) { // if bills is 10
                if (five) { // check if 5 is availble
                    five -= 1; // if yes then decrease five by 1
                    ten += 1; // and increase ten by 1
                } else {
                    return false; // elae return false
                }
            } else { // if bill is 20
                if (ten && five) {  // if both availble
                    five -= 1; // descrease five by 1
                    ten -= 1; // descrease ten by 1
                } else if (five >= 3) { // if five is more then 3 
                    five -= 3; // then decresae five count by 3 (5+5+5 = 15)
                } else {
                    return false;
                }
            }
        }

        return true; // if entire loop is done return true
    }
};
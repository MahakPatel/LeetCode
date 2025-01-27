class Solution {
public:
    // +++++++++++++++++++ Recursive. +++++++++++++++ TC O(2^n). SC O(amount)
    // int f(int index, vector<int>& coins, int amount) {
    //     // Base case: If we are at the first coin
    //     if (index == 0) {
    //         // Check if the amount can be formed using the first coin
    //         if (amount % coins[index] == 0) {
    //             return (amount /
    //                     coins[index]); // Return the number of coins needed
    //         } else {
    //             return -1; // Return -1 if the amount cannot be formed
    //         }
    //     }

    //     // Recursive case 1: Do not take the current coin
    //     int notTake = f(index - 1, coins, amount);

    //     // Recursive case 2: Take the current coin, if possible
    //     int take = INT_MAX;
    //     if (coins[index] <= amount) {
    //         int res =f(index, coins,amount - coins[index]); // Recursive call for remaining amount
    //         if (res !=-1) { // Check if it's possible to form the remaining amount
    //             take = 1 + res; // Add 1 to account for the current coin
    //         }
    //     }

    //     // Return the minimum of the two cases
    //     if (take == INT_MAX) return notTake; // If taking the coin is not possible
    //     if (notTake == -1) return take;     // If not taking the coin is not possible
    //     return min(take, notTake);          // Return the minimum of the two cases  
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();

    //     // Start the recursion from the last index of the coins array
    //     return f(n - 1, coins, amount);
    // }


        int f(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
    // Base case: if we only have one type of coin
    if (index == 0) {
        return (amount % coins[index] == 0) ? (amount / coins[index]) : INT_MAX;
    }

    // Check if the result is already computed
    if (dp[index][amount] != -1) {
        return dp[index][amount];
    }

    // Option 1: Do not take the current coin
    int notTake = f(index - 1, coins, amount, dp);

    // Option 2: Take the current coin, if possible
    int take = INT_MAX;
    if (coins[index] <= amount) {
        int res = f(index, coins, amount - coins[index], dp);
        if (res != INT_MAX) {
            take = 1 + res;
        }
    }

    // Store the result and return
    return dp[index][amount] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int result = f(n - 1, coins, amount, dp);

    return (result == INT_MAX) ? -1 : result;
}
};
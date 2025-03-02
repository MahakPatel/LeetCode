class Solution {
public:
    // +++++++++++++ Brute force ++++++++++++++++++++++
    // TC O(n * n! + n!logn!)
        // generate all the permutataion and then sort and return the kth permutation
    // ++++++++++++ Optimal Solution ++++++++++++++++
    // TC O(n^2)
    // SC O(n)
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;

        // Compute (n-1)! and store numbers from 1 to n
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n); // Add the last number

        string ans = "";
        k = k - 1; // Convert to 0-based index

        while (!numbers.empty()) {
            int index = k / fact;
            ans += to_string(numbers[index]);       // Pick the k-th number
            numbers.erase(numbers.begin() + index); // Remove used number

            if (numbers.empty())
                break; // Break when no numbers left

            k %= fact;              // Update k for the next position
            fact /= numbers.size(); // Update factorial
        }

        return ans;
    }
};
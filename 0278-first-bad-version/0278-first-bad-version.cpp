// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // +++++++++++++ Optimal Solution ++++++++++++
    // TC O(logn)
    // SC O(1)
    int firstBadVersion(int n) {
        long long low = 1, high = n,
                  mid; // Use 1-based indexing (versions start from 1)

        while (low <= high) {
            mid = low + (high - low) / 2; // Prevent integer overflow

            if (isBadVersion(mid)) {
                high =
                    mid - 1; // Search in the left half for earlier bad version
            } else {
                low = mid + 1; // Search in the right half
            }
        }

        return low; // `low` will point to the first bad version
    }
};
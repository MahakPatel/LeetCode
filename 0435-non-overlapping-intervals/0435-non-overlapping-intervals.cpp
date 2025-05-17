class Solution {
public:
 // Static comparator function to compare intervals by their end times
    static bool comparator(const vector<int>& value1,
                           const vector<int>& value2) {
        return value1[1] < value2[1]; // Compare end times of the intervals
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(); // Get the number of intervals

        // Sort intervals based on their end times using the comparator function
        sort(intervals.begin(), intervals.end(), comparator);

        int count = 1; // Start with the first interval (it's always included)
        int lastEndTime = intervals[0][1]; // End time of the first interval

        // Iterate through the remaining intervals
        for (int i = 1; i < n; i++) {
            // If the start time of the current interval is greater than or
            // equal to the end time of the last included interval
            if (intervals[i][0] >= lastEndTime) {
                count++; // Increment the count of non-overlapping intervals
                lastEndTime = intervals[i][1]; // Update the end time to the
                                               // current interval's end time
            }
        }

        // The minimum number of intervals to remove is the total number of
        // intervals minus the count of non-overlapping intervals
        return n - count;
    }
};
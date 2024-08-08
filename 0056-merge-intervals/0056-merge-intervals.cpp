class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeIntervals;
        // if size of intervals is 0 return empty vector
        if (intervals.size() == 0) {
            return mergeIntervals;
        }

        sort(intervals.begin(),intervals.end()); // sort the interval according to time

        vector<int> tempInterval = intervals[0]; //store first value of interval into tempInterval 

        for (auto it : intervals) { // iterate from given intervals
            if (it[0] <= tempInterval[1]) { // if start of interval is less then equal to tempinterval end
                tempInterval[1] = max(tempInterval[1], it[1]); // store max of the end interval into tempInterval
            } else {
                mergeIntervals.push_back(tempInterval); // else push into mergeIntervals
                tempInterval = it;
            }
        }
        mergeIntervals.push_back(tempInterval);
        return mergeIntervals;
    }
};
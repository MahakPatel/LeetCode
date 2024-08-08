class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;

        int n= intervals.size();
        int i=0;

        // for left side array - intervals end will  always  be less then newInterval starting
        while(i< n && intervals[i][1] < newInterval[0]){
            answer.push_back(intervals[i]); // push interval value in answer
            i++;
        }
        // for overlapping condition - interval starting will always be less then or equal to newInterval end
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[i][0]); // newInterval start is minimum of intervals start andnewInterval start
            newInterval[1] = max(newInterval[1],intervals[i][1]);// newInterval end is maximum of intervals end andnewInterval end
            i++;
        }

        answer.push_back(newInterval); // push newInterval into answer

        while(i<n){ // for write hand side push same to same into answer
            answer.push_back(intervals[i]);
            i++;
        }

        return answer; // return answer

    }
};
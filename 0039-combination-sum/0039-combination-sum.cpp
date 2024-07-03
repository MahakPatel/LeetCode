class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // for final ans
        vector<int> ds; // for resulting
        findCombination(0,target,candidates,ans,ds); // call function with starting index
        return ans;
    }

    void findCombination(int index,int target,vector<int> &arr,vector<vector<int>> &ans, vector<int>&ds){
        if(index == arr.size()){ // if index == n
            if(target == 0){ // and if target reach to 0
                ans.push_back(ds); // return the ans 
            }

            return; // else return empty
        }

        if(arr[index] <= target){ // if value is less then or equal to target
            ds.push_back(arr[index]); // push the value to ds
            findCombination(index,target - arr[index],arr,ans,ds); // call function it self with target - current value
            ds.pop_back(); // after call remove last element
        }

        findCombination(index + 1,target,arr,ans,ds); // else call function with index + 1(next index)
    }
};
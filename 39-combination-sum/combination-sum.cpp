class Solution {
public:

    void findCombination(int ind,int sum, int target, vector<int> &arr,vector<vector<int>> &ans, vector<int>&ds){
        if(ind == arr.size()){
            if(target==sum){
                ans.push_back(ds);
            }
            return;
        }

        if(sum+arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind,sum +arr[ind],target,arr,ans,ds);
            ds.pop_back();

        }
        findCombination(ind+1,sum,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum =0;
        findCombination(0,sum,target,candidates,ans,ds);
        return ans;        
        
    }
};
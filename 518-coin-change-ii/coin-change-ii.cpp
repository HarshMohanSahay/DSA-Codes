class Solution {
public:
    int solve(int ind,int target,vector<int>& nums,vector<vector<int>> &dp ){
        if(ind==0){
            
            if(target%nums[ind]==0) return 1;
            else return 0;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = solve(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target) take = solve(ind,target-nums[ind],nums,dp);
        return dp[ind][target] = take +nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int target = amount;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans = solve(n-1,target,coins,dp);
        return ans;
    }
};
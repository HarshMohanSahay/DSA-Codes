class Solution {
public:
    int solve(int ind,int target,vector<int>& nums,vector<vector<int>> &dp ){
        if(ind==0){
            if(nums[ind]==target && target ==0)return 2;
            if(nums[ind]==target|| target==0) return 1;
            else return 0;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = solve(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target) take = solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = take +nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum =0;
        int n = nums.size();
        
        for(int i =0;i<n;i++){
            totalsum+=nums[i];
        }
        target = target+totalsum;
        if(target%2!=0 || target<0) return 0;
        target=target/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans = solve(n-1,target,nums,dp);
        return ans;
    }
};
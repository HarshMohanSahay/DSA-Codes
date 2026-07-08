class Solution {
public:
    int solve(int ind,int target, vector<int>& nums ,vector<vector<int>> &dp){
        if(target==0) return 1;
        if(ind ==0 ) return  target==nums[0] ;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notpick = solve(ind-1,target,nums,dp);
        int pick = 0;
        if(nums[ind]<=target) pick = solve(ind-1,target-nums[ind],nums,dp);

        return dp[ind][target] = pick||notpick;


    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int target = 0;
        for(int i = 0;i<nums.size();i++){
            target += nums[i];
        }
        if(target%2==1) return false;
        vector<vector<int>> dp(n,vector<int>((target/2)+1,-1));

        int ans = solve(n-1,target/2,nums,dp);

        return ans ==1;

        
    }
};
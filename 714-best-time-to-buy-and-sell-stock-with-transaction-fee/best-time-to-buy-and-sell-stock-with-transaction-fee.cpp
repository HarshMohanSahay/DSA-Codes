class Solution {
    int solve(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp,int fee) {
        int n = prices.size();
        if(ind==n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==1){
        int takeit = -prices[ind]+solve(ind+1,0,prices,dp,fee);
        int nottakeit = 0+solve(ind+1,1,prices,dp,fee);
        return dp[ind][buy]=max(takeit,nottakeit);
        }
        else{
           int takeitsell = prices[ind]-fee+solve(ind+1,1,prices,dp,fee);
            int nottakeitsell = 0+solve(ind+1,0,prices,dp,fee);
            return dp[ind][buy]=max(takeitsell,nottakeitsell);
        }


    }
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        int buy = 1;

        vector<vector<int>>dp(n,vector<int>(2,-1));


        int ans = solve(0,buy,prices,dp,fee);
        return ans;
        
    }
};
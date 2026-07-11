
class Solution {
    int solve(int ind,int buy,vector<int>& prices,vector<vector<vector<int>>>&dp,int cap) {
        int n = prices.size();
        if(cap==0) return 0;
        if(ind==n) return 0;

        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        if(buy==1){
        int takeit = -prices[ind]+solve(ind+1,0,prices,dp,cap);
        int nottakeit = 0+solve(ind+1,1,prices,dp,cap);
        return dp[ind][buy][cap]=max(takeit,nottakeit);
        }
        else{
           int takeitsell = prices[ind]+solve(ind+1,1,prices,dp,cap-1);
            int nottakeitsell = 0+solve(ind+1,0,prices,dp,cap);
            return dp[ind][buy][cap]=max(takeitsell,nottakeitsell);
        }


    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));


        int ans = solve(0,buy,prices,dp,k);
        return ans;
        
    }
};
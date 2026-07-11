class Solution {

public:
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2,vector<int>(k+1, 0)));
        for (int ind = n - 1; ind >=0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                for(int cap = k;cap>0;cap--){
                if (buy == 1) {
                    int takeit = -prices[ind] + dp[ind + 1][0][cap];
                    int nottakeit = 0 + dp[ind + 1][1][cap];
                     dp[ind][buy][cap] = max(takeit, nottakeit);
                } else {
                    int takeitsell = prices[ind] + dp[ind + 1][ 1][cap-1];
                    int nottakeitsell = 0 + dp[ind + 1][0][cap];
                     dp[ind][buy][cap] = max(takeitsell, nottakeitsell);
                }
                }
            }
            
        }
        return dp[0][1][k];

    }
    };
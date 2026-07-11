class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int ind = n - 1; ind >=0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                if (buy == 1) {
                    int takeit = -prices[ind] + dp[ind + 1][0];
                    int nottakeit = 0 + dp[ind + 1][1];
                     dp[ind][buy] = max(takeit, nottakeit);
                } else {
                    int takeitsell = prices[ind] + dp[ind + 1][ 1];
                    int nottakeitsell = 0 + dp[ind + 1][0];
                     dp[ind][buy] = max(takeitsell, nottakeitsell);
                }
            }
            
        }
        return dp[0][1];

    }
    };
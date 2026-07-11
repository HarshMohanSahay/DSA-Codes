class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;

        //vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> prev(2,0);
         vector<int>curr(2, 0);

        for (int ind = n - 1; ind >=0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                if (buy == 1) {
                    int takeit = -prices[ind] + prev[0];
                    int nottakeit = 0 + prev[1];
                     curr[buy] = max(takeit, nottakeit);
                } else {
                    int takeitsell = prices[ind] + prev[ 1];
                    int nottakeitsell = 0 + prev[0];
                     curr[buy] = max(takeitsell, nottakeitsell);
                }
            }
            prev = curr;
            
        }
        return prev[1];

    }
    };
class Solution {

public:
    int maxProfit(int k ,vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int cap = 2;

        vector<vector<int>>ahead(2,vector<int>(k+1, 0));
        vector<vector<int>>curr(2,vector<int>(k+1, 0));
        for (int ind = n - 1; ind >=0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                for(int cap = k;cap>0;cap--){
                if (buy == 1) {
                    int takeit = -prices[ind] + ahead[0][cap];
                    int nottakeit = 0 + ahead[1][cap];
                     curr[buy][cap] = max(takeit, nottakeit);
                } else {
                    int takeitsell = prices[ind] + ahead[ 1][cap-1];
                    int nottakeitsell = 0 + ahead[0][cap];
                    curr[buy][cap] = max(takeitsell, nottakeitsell);
                }
                }
            }
            ahead = curr;
            
        }
        return ahead[1][k];

    }
    };
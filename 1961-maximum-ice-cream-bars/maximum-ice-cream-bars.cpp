class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        vector<int> freq(100001, 0);

        // Count frequency of each cost
        for(int cost : costs) {
            freq[cost]++;
        }

        int ans = 0;

        // Start from cheapest ice cream
        for(int cost = 1; cost <= 100000; cost++) {

            if(freq[cost] == 0)
                continue;

            // How many of this cost can we buy?
            int canBuy = min(freq[cost], coins / cost);

            ans += canBuy;
            coins -= canBuy * cost;

            if(coins < cost)
                break;
        }

        return ans;
    }
};

class Solution {
#define ll long long
    int mod = 1e9 + 7;

public:
    ll solvepower(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b % 2 != 0) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b = b / 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {

        ll noofoddindex = n / 2;
        ll noofevenindex = (n + 1) / 2;

        return (solvepower(5 ,noofevenindex) * solvepower(4 , noofoddindex)) %
               mod;
    }
};
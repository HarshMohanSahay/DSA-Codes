class Solution {
public:
    int M = 1e9 + 7;
    typedef long long ll;

    int maximumXorProduct(long long a, long long b, int n) {
        ll xXora = 0;
        ll xXorb = 0;

        // 49th bit to nth bit
        for (int i = 49; i >= n; i--) {

            bool a_ith_bit = (a &(1ll<<i)) > 0;
            bool b_ith_bit = (b &(1ll<<i)) > 0;

            if (a_ith_bit == true) {
                xXora = (xXora | (1LL << i));
            }

            if (b_ith_bit == true) {
                xXorb = (xXorb | (1LL << i));
            }
        }

        for (int i = n - 1; i >= 0; i--) {

            bool a_ith_bit = (a &(1ll<<i)) > 0;
            bool b_ith_bit = (b &(1ll<<i)) > 0;

            if (a_ith_bit == b_ith_bit) {
                xXora = (xXora | (1LL << i));
                xXorb = (xXorb | (1LL << i));
            }

            if (xXora > xXorb) {
                xXorb = (xXorb | (1LL << i));
            }
            else {
                xXora = (xXora | (1LL << i));
            }
        }

        xXora = (xXora % M);
        xXorb = (xXorb % M);

        return (xXora * xXorb) % M;
    }
};
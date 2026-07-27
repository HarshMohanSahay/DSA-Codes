class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0;
        int r = minutes - 1;
        int sum = 0;

        for (int i = 0; i <= r; i++) {
            if (grumpy[i] == 1)
                sum += customers[i];
        }
        int maxi = sum;
        int firstindex = 0;
        int lastindex = r;
        r++;

        while (r < customers.size()) {
            if (grumpy[r] == 1)
                sum = sum + customers[r];
            if (grumpy[l] == 1)
                sum = sum - customers[l];
            if (maxi < sum) {
                maxi = sum;
                firstindex = l + 1;
                lastindex = r;
            }
            r++;
            l++;
        }
        int basesum =0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                basesum += customers[i];
            }
        }
        return basesum + maxi ;
    }
};
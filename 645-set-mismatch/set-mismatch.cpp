class Solution {
public:
typedef long long ll;
    vector<int> findErrorNums(vector<int>& nums) {
        long long  n = nums.size();
        long long S1 = (n*(n+1))/2;
        long long S2 = (n*(n+1)*(2*n+1))/6;
        long long sum1 = 0;
        long long sum2 = 0;

        for(int i =0;i<n;i++){
            sum1+=nums[i];
            sum2+=nums[i]*nums[i];
        }
        ll val1 = sum1-S1;
        ll val2 = (sum2-S2)/val1;
        ll x = (val1+val2)/2;
        ll y = x-val1;

        return {int(x),int(y)};
    }
};
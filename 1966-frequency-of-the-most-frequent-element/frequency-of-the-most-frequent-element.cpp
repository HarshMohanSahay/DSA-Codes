class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxlength = 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        long long sum =0;
        while(r<n){
           sum +=nums[r];
            if((long long) (r-l+1)*nums[r]-sum >k){
                sum -= nums[l];
                l++;
            }
            maxlength = max(maxlength,r-l+1);
            r++;

        }
        return maxlength;
    }
};
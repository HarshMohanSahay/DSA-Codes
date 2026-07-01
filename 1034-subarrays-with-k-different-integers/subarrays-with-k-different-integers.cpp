class Solution {
    int solve(vector<int>& nums,int k,map<int,int>freq){
        if(k<0) return 0;
        int l = 0;
        int r =0;
        int cnt = 0;
        int n = nums.size();
    
        while(r<n){
            freq[nums[r]]++;
            while(freq.size()>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            if(freq.size()<=k){
                cnt = cnt + (r-l+1);
            }
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int, int> freq;
        int ans = solve(nums,k,freq) - solve(nums,k-1,freq);
        return ans;
    }
};
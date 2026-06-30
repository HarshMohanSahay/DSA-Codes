class Solution {
      
    int solve(vector<int>& nums, int goal){
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;
        if(goal<0) return 0;

        while(r<nums.size()){
            sum = sum+(nums[r]%2);
            while(sum>goal){
                sum = sum -(nums[l]%2);
                l++;
            }
            cnt = cnt + r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        int ans = solve(nums,goal)-solve(nums,goal-1);
        return ans;
    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n =nums.size();
        vector<int>ans(n);
        int r=0;
        int fi=0;
        int li=n-1;

        while(r<n){
            if(nums[r]%2==0){
                ans[fi]=nums[r];
                fi++;
            }
            else{
                ans[li]=nums[r];
                li--;
            }
            r++;
        }
        return ans;

        
    }
};
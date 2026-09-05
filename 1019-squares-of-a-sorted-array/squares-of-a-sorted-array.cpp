class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int i = 0;
        int j = n-1;
      

        for(int pos = n-1;pos>=0;pos--){
           
            if((nums[i]*nums[i])<(nums[j]*nums[j])){
                ans[pos] = nums[j]*nums[j];
                j--;
            }
            else{
                ans[pos]= nums[i]*nums[i];
                i++;
            }
        }
        return ans ;
    }
};
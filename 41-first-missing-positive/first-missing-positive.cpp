class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //clean the array 
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=n+1;
            }
        }

        // put negative value of the n-1 index
        for(int i =0;i<n;i++){
            int x = abs(nums[i]);
            if(x<=n){
                nums[x-1] = -abs(nums[x-1]);
            }
        }
        //if nonnegative value and less then array size then that index+1 value is the ans
        for(int i =0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};
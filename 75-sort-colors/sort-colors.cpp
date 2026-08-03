class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int lw = 0;
        int rw = n-1;

        while(r<=rw){
            if(nums[r]==0){
                swap(nums[r],nums[lw]);
                r++;
                lw++;
            }
            else if(nums[r]==2){
                swap(nums[r],nums[rw]);
                rw--;
            }
            else{
                r++;
            }
        }
    }
};
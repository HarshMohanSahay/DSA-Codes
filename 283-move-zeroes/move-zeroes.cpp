class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 1;
        while(i<nums.size()){
            j=i+1;
           while(j<nums.size() && nums[j]==0)j++;
            if(j<nums.size() && nums[i]==0)swap(nums[i],nums[j]);
            i++;
        }
    }
};
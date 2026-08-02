class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 1;
        for (int read= 1;read<=nums.size()-1;read++)
        {
            if(nums[read]!=nums[read-1]){
                nums[write]=nums[read];
                write++;
            }
           
        }
        return write;
    }
};
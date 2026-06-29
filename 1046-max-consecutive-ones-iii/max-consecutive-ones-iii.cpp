class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n = nums.size();
       int start = 0;
       int zerocount = 0;
       int maxcount = 0;

       for(int end = 0;end<nums.size();end++){
        if(nums[end]==0){
            zerocount++;
        }

        if(zerocount>k){
            if(nums[start]==0){
                zerocount--;
            }
            start++;
        }
        if(zerocount<=k)
        maxcount = max(maxcount,end-start+1);
       }
       return maxcount;

    }
};
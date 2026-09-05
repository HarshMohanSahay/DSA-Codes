class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        int closest = nums[0]+nums[1]+nums[2];
        for(int i =0;i<n;i++){
            
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<abs(target-closest)){
                    closest = sum;
                }
              
                if(sum<target)j++;
                else k--;
                
            }
        }
        return closest;
    }
};
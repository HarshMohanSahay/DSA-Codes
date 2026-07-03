class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       mp[0]=1;
       int sum = 0;
       int result = 0;
       int need = 0;

       for(int i = 0; i<nums.size();i++){
            sum += nums[i];
            need = sum-k;
            result += mp[sum-k];
            mp[sum]+=1;
       }
       return result;
    }
};
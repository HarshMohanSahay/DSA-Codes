class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>result;
        int mask = (1<<maximumBit) - 1;
        int xornum = 0;
        for(int i =0;i<n;i++){
            xornum ^= nums[i];
        }
        
        for(int i=n-1;i>=0;i--){
            result.push_back(xornum ^ mask);
            xornum ^= nums[i];
        }
        return result;
    }
};
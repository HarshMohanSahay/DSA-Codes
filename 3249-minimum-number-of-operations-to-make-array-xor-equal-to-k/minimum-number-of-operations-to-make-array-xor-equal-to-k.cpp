class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalxor = 0;
        for(int i = 0;i<nums.size();i++){
            totalxor ^= nums[i];

        }
        int diff = totalxor^k;
        return __builtin_popcount(diff);
    }
};
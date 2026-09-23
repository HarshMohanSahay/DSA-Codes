class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        // Need to remove everything
        if(target == 0)
            return n;

        int i = 0;
        int sum = 0;
        int maxLen = -1;

        for(int j = 0; j < n; j++) {

            sum += nums[j];

            while(i <= j && sum > target) {
                sum -= nums[i];
                i++;
            }

            if(sum == target) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        if(maxLen == -1)
            return -1;

        return n - maxLen;
    }
};
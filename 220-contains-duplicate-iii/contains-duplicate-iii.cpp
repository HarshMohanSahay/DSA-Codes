class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                        int indexDiff,
                                        int valueDiff) {

        set<long long> window;

        for(int i = 0; i < nums.size(); i++) {

            // Remove element outside the index window
            if(i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }

            // Find first value >= nums[i] - valueDiff
            auto it = window.lower_bound(
                (long long)nums[i] - valueDiff
            );

            // Check if that value is also <= nums[i] + valueDiff
            if(it != window.end() &&
               *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};
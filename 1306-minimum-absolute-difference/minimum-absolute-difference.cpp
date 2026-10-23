
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        int n = arr.size();

        // Find the minimum difference between adjacent elements
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> ans;

        // Collect every pair with the minimum difference
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};

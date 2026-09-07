class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n = intervals.size();
        int u = newInterval[0];
        int v = newInterval[1];
        int i =0;
        while(i<n && intervals[i][1]<u){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=v){
            u = min(u,intervals[i][0]);
            v = max(v,intervals[i][1]);
            i++;
        }
        ans.push_back({u,v});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
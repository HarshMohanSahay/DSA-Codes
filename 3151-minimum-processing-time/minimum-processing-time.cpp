class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(),tasks.end());
        int n = tasks.size();
        int j = 0;
        int ans = 0;
        for(int i =n-1;i>=0;i-=4){
            ans = max(ans,tasks[i]+processorTime[j]);
            j++;
        }
        return ans ;
    }
};
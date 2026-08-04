class Solution {
public:
    int n;
    int getnextindex(vector<vector<int>>&arr,int l ,int r,int currentend){
        int result=n;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid][0]>=currentend){
                result = mid;
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>&arr,int i,vector<int>&dp){
        if(i>=n)return dp[i] = 0;
        if(dp[i]!=-1)return dp[i];
        int nextindex = getnextindex(arr,i,n-1,arr[i][1]);

        int take = arr[i][2]+solve(arr,nextindex,dp);
        int nottake = solve(arr,i+1,dp);

        return dp[i] = max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>>array(n,vector<int>(3,0));
        vector<int>dp(n+1,-1);
        for(int i =0;i<n;i++){
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        auto comp = [&](const auto& v1,auto &v2){
            return v1[0]<v2[0];
        };

        sort(array.begin(),array.end(),comp);

         solve(array,0,dp);
        return dp[0];
    }
};
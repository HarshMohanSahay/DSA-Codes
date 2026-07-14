class Solution {
public:
    int solve(int i ,vector<int>&arr,int n , vector<int>&dp,int k){
        if(i==n) return 0;

        if(dp[i]!=-1)return dp[i];

        int maxi = INT_MIN;
        int maxians = INT_MIN;

        for(int ind=i;ind<min(n,i+k);ind++){
            maxi = max(maxi,arr[ind]);
            int len = ind-i+1;
            int sum = len*maxi + solve(ind+1,arr,n,dp,k);
            maxians = max(maxians,sum);

        }
        return dp[i]=maxians;


    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int>dp(n,-1);
        return solve(0,arr,n,dp,k);
        
    }
};
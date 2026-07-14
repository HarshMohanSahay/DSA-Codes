class Solution {
public:

    bool ispalindrom(int i ,int j,string &s){
        int n = s.size();
        
        while(i<j){
           if(s[i]!=s[j]){
            return false;
           }
           i++;
           j--;

        }
        return true;
    }
    int solve(int i,string &s ,int n ,vector<int>&dp){
        int mini = INT_MAX;
        if(i==n)return 0;

        if(dp[i]!=-1)return dp[i];
        
        for(int j = i;j<n;j++){
            if(ispalindrom(i,j,s)){
                int cost = 1+solve(j+1,s,n,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i]=mini;

    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        int ans = solve(0,s,n,dp);
        return ans-1;
        
    }
};
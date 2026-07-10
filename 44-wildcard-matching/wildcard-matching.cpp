class Solution {

public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0&&j<0)return 1;
        if(i<0&&j>=0)return 0;
        if(j<0 && i>=0){
            for(int ind=0;ind<=i;ind++){
                if(s[ind]!='*')return 0;
                
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j] || s[i]=='?') return dp[i][j]=solve(i-1,j-1,s,t,dp);
        else if(s[i]=='*') return dp[i][j]=solve(i-1,j,s,t,dp)||solve(i,j-1,s,t,dp);
        else return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = solve(n-1,m-1,p,s,dp);
        return ans==1;
    }
};
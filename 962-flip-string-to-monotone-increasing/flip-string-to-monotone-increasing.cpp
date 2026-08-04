class Solution {
public:
    int n;
   
    int solve(string& s, int currindex, char prev,vector<vector<int>>&dp) {
         int flip = INT_MAX;
         int notflip = INT_MAX;

         
        if (currindex >= n)
            return 0;
        if(dp[currindex][prev-'0']!=-1) return dp[currindex][prev-'0'];
        if (s[currindex] == '0') {
            if (prev == '0') {
                 flip = 1 + solve(s, currindex + 1, '1',dp);
                 notflip = solve(s, currindex + 1, '0',dp);
            } else {
                 flip = 1 + solve(s, currindex + 1, '1',dp);
            }
        } else {
            if (prev == '0') {
                 flip = 1 + solve(s, currindex + 1, '0',dp);
                 notflip = solve(s, currindex + 1, '1',dp);
            } else {
                 notflip = solve(s, currindex + 1, '1',dp);
            }
        }
        return dp[currindex][prev-'0']=min(flip, notflip);
    }
    int minFlipsMonoIncr(string s) {
        n = s.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        solve(s, 0, '0',dp);
        return dp[0][0];
    }
};
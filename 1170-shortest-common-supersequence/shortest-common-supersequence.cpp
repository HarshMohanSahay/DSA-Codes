class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int len = n+m-dp[n][m];
        string ans(len,' ');
        int ind = len-1;
        int i = n;
        int j = m;

        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans[ind] = str1[i-1];
                ind--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans[ind]=str1[i-1];
                ind--;
                i--;
            }
            else{
                ans[ind]=str2[j-1];
                ind--;
                j--;
            }
        }
        while(i>0){
            ans[ind]=str1[i-1];
            ind--;
            i--;
        }
        while(j>0){
            ans[ind]= str2[j-1];
            ind--;
            j--;
        }
        return ans;

    }
};
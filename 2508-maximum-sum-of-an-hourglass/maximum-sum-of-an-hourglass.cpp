class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int maxi =0;
       int sum =0;

       for(int i = 0;i<=m-3;i++){
        for(int j = 0;j<=n-3;j++){
         sum = 0;
            for(int k = i ;k<i+3;k++){
                for(int l = j;l<j+3;l++){
                    sum += grid[k][l];
                }
            }
            sum -= grid[i+1][j];
            sum -= grid[i+1][j+2];

            maxi = max(maxi,sum);
        }
       } 
       return maxi ;
    }
};
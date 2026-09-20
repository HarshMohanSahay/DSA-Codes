class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int score = pow(2,n-0-1)*m;

        for(int j =1;j<n;j++){
            int countones = 0;
            for(int i =0;i<m;i++){
                if(grid[i][0]==grid[i][j]){
                    countones++;
                }
            }
            int countzeros = m-countones;
            int ones = 0;
            if(countones>countzeros){
                 ones = countones;
            }
            else{
                 ones = countzeros;
            }
            score += (pow(2,n-j-1)*ones);
        }
        return score;
    }
};
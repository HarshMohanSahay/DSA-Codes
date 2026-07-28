class Solution {
public:
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};
    int n ;
    int m ;

    bool dfs (int i ,int j,int parent_i ,int parent_j,vector<vector<int>>&visited,vector<vector<char>>& grid){
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int newi = i+row[k];
            int newj = j+col[k];

            if(newi<m && newj<n && newi>=0 && newj>=0 && grid[newi][newj]==grid[i][j] && (newi!=parent_i || newj != parent_j)){
                if(visited[newi][newj]==1)return true;
                else if(dfs(newi,newj,i,j,visited,grid)==true){
                    return true;
                }
            }
        }
        return false;
        
    }
    bool containsCycle(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();
       
        vector<vector<int>>visited(m,vector<int>(n,0));
        for( int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,visited,grid)==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
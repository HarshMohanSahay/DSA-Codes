class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int n = grid.size();

        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        if (grid[0][0] == 1 || grid[n - 1][n - 1]) {
            return -1;
        }
        q.push({0, 0});
        grid[0][0]=1;
        int len = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x==n-1 && y==n-1){
                    return len;
                }

                for (int i = 0; i < 8; i++) {
                    int newx = x+drow[i];
                    int newy = y+dcol[i];

                    if (newx >= 0 && newy >= 0 && newx <= n - 1 &&
                        newy <= n - 1 && grid[newx][newy] == 0) {
                            grid[newx][newy]=1;
                        q.push({newx, newy});
                    }
                }
                
            }
            len++;
        }
        return -1;
    }
};
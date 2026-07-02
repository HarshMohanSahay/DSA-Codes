class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        queue<pair<int,int>> q;
        q.push({0,0});
        best[0][0] = startHealth;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            if (r == m-1 && c == n-1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newHealth = best[r][c] - grid[nr][nc];

                    if (newHealth > 0 && newHealth > best[nr][nc]) {
                        best[nr][nc] = newHealth;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return false;
    }
};
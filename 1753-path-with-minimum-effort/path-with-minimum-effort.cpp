class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        result[0][0] = 0;

        int row[] = {0, -1, 0, 1};
        int col[] = {-1, 0, 1, 0};

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (x == n - 1 && y == m - 1)
                return diff;

            for (int i = 0; i < 4; i++) {
                int x_ = x + row[i];
                int y_ = y + col[i];
                

                if (x_ >= 0 && y_ >= 0 && x_ < n && y_ < m) {
                    int neweffort = max(diff,abs(heights[x_][y_]- heights[x][y]));
                    if (neweffort<result[x_][y_]) {
                        result[x_][y_] = neweffort;
                       
                    pq.push({neweffort,{x_,y_}});
                    }
                }
            }
        }
    return result[n-1][m-1];
    }
};
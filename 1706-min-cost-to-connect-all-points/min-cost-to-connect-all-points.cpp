class Solution {
public:
    typedef pair<int, int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        int sum = 0;

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> visited(n, 0);
        pq.push({0, 0});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node] == 1)
                continue;
            sum += wt;
            visited[node] = 1;

            for (auto& v : adj[node]) {
                int newnode = v.first;
                int w = v.second;

                pq.push({w, newnode});
            }
        }
        return sum;
    }
};
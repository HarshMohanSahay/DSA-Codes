class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& result) {
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v, adj, result);
        }
        result.push_back(u);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;
        for (auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        int start = pairs[0][0];
        for (auto& it : outdegree) {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1) {
                start = node;
                break;
            }
        }
        vector<int> result;

        dfs(start, adj, result);
        reverse(result.begin(), result.end());
        vector<vector<int>> ans;
        for (int i = 0; i < result.size() - 1; i++) {
            ans.push_back({result[i], result[i + 1]});
        }
        return ans;
    }
};
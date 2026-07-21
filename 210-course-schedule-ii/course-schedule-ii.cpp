// using DFS

class Solution {
public:
    bool iscycle(unordered_map<int, vector<int>>& adj, int u,
                 vector<int>& visited, vector<int>& inrecursion,
                 stack<int>& st) {
        visited[u] = 1;
        inrecursion[u] = 1;

        for (auto& v : adj[u]) {
            if (!visited[v] && iscycle(adj, v, visited, inrecursion, st)) {
                return true;
            } else if (inrecursion[v] == 1)
                return true;
        }
        st.push(u);
        inrecursion[u] = 0;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
        }

        vector<int> visited(n, 0);
        vector<int> inrecursion(n, 0);
        stack<int> st;
        bool iscylepresent=false;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                iscylepresent = iscycle(adj, i, visited, inrecursion, st);
                if(iscylepresent==true){
                    return {};
                }

            }
        }

        vector<int> result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

       
        return result;
    }
};
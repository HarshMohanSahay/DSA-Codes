class Solution {
public:
    pair<int,int> BFS(unordered_map<int,vector<int>>adj,int u){
        queue<int>q;
        q.push(u);
        int furthest = u;
        int count = 0;
        unordered_map<int,int>visited;
        visited[u]=1;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                int element = q.front();
                q.pop();
                for(auto &v : adj[element]){
                    if(visited[v]==0){
                        q.push(v);
                        visited[v]=1;
                        furthest = v;

                    }
                }
            }
            if(q.empty()==0){
                count++;
            }
        }
        return {furthest,count};

    }

    int finddiameter(unordered_map<int,vector<int>>adj){
        auto[furthestnode,dist]=BFS(adj,0);
        auto[endnode,diameter] = BFS(adj,furthestnode);

        return diameter;
    }
    unordered_map<int,vector<int>> makeadj(vector<vector<int>> edges){
        unordered_map<int,vector<int>>adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;

    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1 = makeadj(edges1);
        unordered_map<int,vector<int>>adj2 = makeadj(edges2);

        int d1 = finddiameter(adj1);
        int d2 = finddiameter(adj2);

        int combined = (d1+1)/2 + (d2+1)/2 + 1;
        return max(d1,max(d2,combined));
    }
};
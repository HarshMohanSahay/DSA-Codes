// using DFS 

class Solution {
public:
    bool iscycle(unordered_map<int,vector<int>> &adj,int u,vector<int> &visited, vector<int> &inrecursion){
        visited[u]=1;
        inrecursion[u]=1;

        for(auto &v:adj[u]){
            if(!visited[v] && iscycle(adj,v,visited,inrecursion)==true){
                return true;
            }
            else if(inrecursion[v]==1) return true;
        }
        inrecursion[u] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;

        for(auto &edges : prerequisites){
            int u=edges[1];
            int v = edges[0];

            adj[u].push_back(v);
        }

        vector<int> visited(numCourses,0);
        vector<int> inrecursion(numCourses,0);

        for(int i =0;i<numCourses;i++){
            if(!visited[i] && iscycle(adj,i,visited,inrecursion)==true){
                return false;
            }
        }
        return true;
    }
};
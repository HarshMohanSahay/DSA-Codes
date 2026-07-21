class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;

        for(auto &edge:prerequisites){
            int u=edge[1];
            int v = edge[0];

            adj[u].push_back(v);

        }

        vector<int>indegree(numCourses,0);
        for(int u=0;u<numCourses;u++){
            for(auto &v:adj[u]){
                indegree[v]++;
            }
        }
        queue<int>q;
        int count =0;
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0){
                count++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
        
            for(auto v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }
        }
        if(count==numCourses){
            return true;
        }
        return false;
    }
};
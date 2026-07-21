class Solution {
public:
    bool DFS(vector<vector<int>>& graph,int u , vector<int>&color,int currcolor){
        color[u]=currcolor;

        for(auto &v:graph[u]){
            if(color[v]==color[u]){
                return false;
            }
            else if(color[v]==-1){
                
                if(DFS(graph,v,color,!currcolor)==false){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        int currcolor =-1;
        

        for(int i =0;i<n;i++){
            if(color[i]==-1){
                if(DFS(graph,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
};
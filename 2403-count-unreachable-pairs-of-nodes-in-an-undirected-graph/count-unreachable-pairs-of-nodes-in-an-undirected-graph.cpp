class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unioun(int x, int y) {
        int xparent = find(x);
        int yparent = find(y);

        if(xparent==yparent){
            return;
        }
        if (rank[xparent] > rank[yparent]) {
            parent[yparent] = xparent;
        } else if (rank[yparent] > rank[xparent]) {
            parent[xparent] = yparent;
        } else {
            parent[yparent] = xparent;
            rank[xparent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for (int i =0;i<n;i++){
            parent[i]=i;
        }

        for( auto &edge : edges){
            int x = edge[0];
            int y = edge[1];

            unioun(x,y);
        }
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            int parent = find(i);
            mp[parent]++;
        }
        long long  result = 0;
        long long remaing = n;

        for( auto &v : mp){
            long long size = v.second;
            result += size * (remaing-size);
            remaing -=size;
        }
        return result;
    }
};
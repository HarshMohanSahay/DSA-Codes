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

        if (rank[xparent] > rank[yparent]) {
            parent[yparent] = xparent;
        } else if (rank[yparent] > rank[xparent]) {
            parent[xparent] = yparent;
        } else {
            parent[yparent] = xparent;
            rank[xparent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int noOfComponent = n;
        if (noOfComponent - 1 > connections.size()) {
            return -1;
        }
        for (auto& edge : connections) {
            int x = edge[0];
            int y = edge[1];

            int parentx = find(x);
            int parenty = find(y);

            if (parentx == parenty) {
                continue;
            } else {
                unioun( x, y);
                noOfComponent--;
            }
        }
        return noOfComponent - 1;
    }
};
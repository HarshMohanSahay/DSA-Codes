class Solution {
public:
    vector<char> parent;
    vector<int> rank;

    char find(char x) {
        if (parent[x - 'a'] == x) {
            return x;
        }
        return parent[x - 'a'] = find(parent[x - 'a']);
    }

    void unioun(char x, char y) {
        char x_parent = find(x);
        char y_parent = find(y);

        if (x_parent == y_parent)
            return;
        else if (rank[x_parent - 'a'] > rank[y_parent - 'a']) {
            parent[y_parent - 'a'] = x_parent;

        } else if (rank[x_parent - 'a'] < rank[y_parent - 'a']) {
            parent[x_parent - 'a'] = y_parent;

        } else {
            parent[y_parent - 'a'] = x_parent;
            rank[x_parent - 'a']++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for (int i = 0; i < 26; i++) {
            parent[i] = 'a' + i;
        }

        for (auto& charchter : equations) {
            char p = charchter[0];
            char q = charchter[1];
            char r = charchter[2];
            char s = charchter[3];
            if (q == '=') {
                unioun(p, s);
            }
        }

        for (auto& charchter : equations) {
            char p = charchter[0];
            char q = charchter[1];
            char r = charchter[2];
            char s = charchter[3];
            if (q == '!') {
                char p_parent = find(p);
                char s_parent = find(s);

                if (p_parent == s_parent)
                    return false;
            }
        }
        return true;
    }
};
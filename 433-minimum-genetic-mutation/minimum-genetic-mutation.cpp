class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid(bank.begin(), bank.end());
        if(startGene == endGene) return 0;

        if(valid.find(endGene) == valid.end())
            return -1;

        queue<string> q;
        q.push(startGene);

        unordered_set<string> visited;
        visited.insert(startGene);

        vector<char> genes = {'A', 'C', 'G', 'T'};
        int step = 0;

        while (!q.empty()) {
            int n = q.size();

            while (n) {
                string curr = q.front();
                q.pop();

                if (curr == endGene)
                    return step;

                for (int i = 0; i < curr.size(); i++) {
                    char currentletter = curr[i];

                    for (int j = 0; j < genes.size(); j++) {

                        if (genes[j] == currentletter)
                            continue;

                        curr[i] = genes[j];
                        if (valid.count(curr) && !visited.count(curr)) {
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }

                    curr[i] = currentletter;
                }
                n = n - 1;
            }
            step++;
        }
        return -1;
    }
};
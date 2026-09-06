class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>maps(26,0);
        vector<int>mapt(26,0);

         for (char c : s) {
            maps[c - 'a']++;
        }

        for (char c : target) {
            mapt[c - 'a']++;
        }

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (mapt[i] > 0) {
                ans = min(ans, maps[i] / mapt[i]);
            }
        }

        return ans;

    }
};
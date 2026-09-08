class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());

        int n = tiles.size();
        int i = 0;
        int j = 0;
        int covered = 0;
        int ans = 0;

        while (i < n) {

            int carpetEnd = tiles[i][0] + carpetLen - 1;

            while (j < n && tiles[j][1] <= carpetEnd) {
                covered += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }

            int partial = 0;

            if (j < n && tiles[j][0] <= carpetEnd) {
                partial = carpetEnd - tiles[j][0] + 1;
            }

            ans = max(ans, covered + partial);

            covered -= tiles[i][1] - tiles[i][0] + 1;
            i++;

            if (j < i) {
                j = i;
                covered = 0;
            }
        }

        return ans;
    }
};
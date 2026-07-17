class Solution {
public:
    int maxDepth(string s) {

        int i = 0;
        int n = s.size();
        int cnt = 0;
        int maxi = 0;
        while (i < n) {
            if (s[i] == '(') {
                cnt++;
                maxi = max(maxi, cnt);
            }

            else if(s[i] == ')') {
                cnt--;
            }
            i++;
        }
        return maxi;
    }
};
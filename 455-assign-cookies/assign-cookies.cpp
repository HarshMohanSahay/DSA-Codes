class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0;
        int r = 0;
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int n = g.size();
        int m = s.size();
        int cnt =0;

        while(l<m && r<n){
            if(s[l]<g[r]){
                r++;
            }
            else{
                cnt++;
                r++;
            l++;
            }
        }

        return cnt;
        
    }
};
class Solution {
    bool isequal(int *hashs,int *hasht){
        for(int i =0;i<256;i++){
            if(hashs[i]<hasht[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int hashs[256] = {0};
        int hasht[256] = {0};
        int n = s.size();
        int minstart =0;
        int minlength = INT_MAX;
        string str = "";

        for(int i =0;i<t.size();i++){
            hasht[t[i]]++;

        }

        while(r<n){
            hashs[s[r]]++;

            while(isequal(hashs,hasht)){
                 if(r - l + 1 < minlength){
                    minlength = r - l + 1;
                    minstart = l;
                     }
                hashs[s[l]]--;
                l++;


            }
            r++;


        }
        if(minlength == INT_MAX)return "";
        str = s.substr(minstart,minlength);
        return str;
        

    }
};
class Solution {
public:
    string processStr(string s) {
       string ans = "";

       for(int i=0;i<s.size();i++){
        if(s[i]>=97 && s[i]<=122){
            ans+=s[i];
        }
        if(s[i]=='*' && !ans.empty()){
            ans.pop_back();
        }
        if(s[i]=='#'){
            string temp = ans;
            ans+=temp;
        }
        if(s[i]=='%'){
            reverse(ans.begin(),ans.end());
        }
       }
       return ans;
    }
};